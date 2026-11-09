#include "MiniTriton/IR/MiniTritonOps.h"
#include "mlir/IR/ImplicitLocOpBuilder.h"
#include <limits>

#define GET_OP_CLASSES
#include "MiniTriton/IR/MiniTritonOps.cpp.inc"

namespace {
// TTIR currently supports scalars and nonempty, static 1D tensors only.
bool validShape(mlir::Type type) {
    if (auto tensor = mlir::dyn_cast<mlir::RankedTensorType>(type))
        return tensor.getRank() == 1 && tensor.hasStaticShape() &&
               tensor.getDimSize(0) > 0 && !tensor.getEncoding();
    return !mlir::isa<mlir::ShapedType>(type);
}

mlir::Type elementType(mlir::Type type) {
    if (auto tensor = mlir::dyn_cast<mlir::RankedTensorType>(type))
        return tensor.getElementType();
    return type;
}

bool sameShape(mlir::Type a, mlir::Type b) {
    auto ta = mlir::dyn_cast<mlir::RankedTensorType>(a);
    auto tb = mlir::dyn_cast<mlir::RankedTensorType>(b);
    if (ta && tb)
        return ta.getShape() == tb.getShape();
    return !ta && !tb;
}

mlir::LogicalResult verifyMemory(mlir::Operation *op, mlir::Type ptr,
                                 mlir::Type value, mlir::Type mask) {
    if (!validShape(ptr) || !validShape(value) || !validShape(mask))
        return op->emitOpError("requires scalars or nonempty static 1D tensors without encoding");
    auto pointer = mlir::dyn_cast<mini_triton::PointerType>(elementType(ptr));
    if (!pointer)
        return op->emitOpError("requires pointer operands");
    if (!sameShape(ptr, value) || !sameShape(ptr, mask))
        return op->emitOpError("pointer, value, and mask shapes must match");
    if (elementType(value) != pointer.getPointeeType())
        return op->emitOpError("value element type must match pointer pointee");
    if (!elementType(mask).isInteger(1))
        return op->emitOpError("mask must have i1 elements");
    return mlir::success();
}
} // namespace

mlir::LogicalResult mini_triton::SplatOp::verify()
{
    auto inputType = getInput().getType();

    auto outputType =
        mlir::cast<mlir::RankedTensorType>(
            getResult().getType());

    if (!(inputType.isIntOrFloat() || mlir::isa<PointerType>(inputType)))
        return emitOpError("input must be a numeric or pointer scalar");
    if (!validShape(outputType))
        return emitOpError("requires a nonempty static 1D tensor without encoding");

    if (inputType != outputType.getElementType())
    {
        return emitOpError(
            "input type must match output element type");
    }

    return mlir::success();
}

mlir::LogicalResult mini_triton::MakeRangeOp::verify()
{
    int64_t start = getStartAttr().getInt();
    int64_t end = getEndAttr().getInt();

    auto type = getResult().getType();

    if (type.getRank() != 1)
        return emitOpError("requires a 1D tensor");

    if (!type.getElementType().isInteger(32))
        return emitOpError("requires i32 elements");

    if (!validShape(type))
        return emitOpError("requires a nonempty static 1D tensor without encoding");

    // Bound the endpoints before subtraction to avoid signed overflow.
    if (start < std::numeric_limits<int32_t>::min() ||
        end > int64_t(std::numeric_limits<int32_t>::max()) + 1 || end <= start)
        return emitOpError("requires an increasing range representable as i32");

    if (end - start != type.getNumElements())
        return emitOpError("range length must match tensor size");

    return mlir::success();
}

mlir::LogicalResult mini_triton::GetProgramIdOp::verify() {
    auto axis = getAxisAttr().getInt();
    if (axis < 0 || axis > 2)
        return emitOpError("axis must be 0, 1, or 2");
    return mlir::success();
}

mlir::LogicalResult mini_triton::AddPtrOp::verify() {
    auto ptr = getPtr().getType();
    auto offset = getOffset().getType();
    if (!validShape(ptr) || !validShape(offset) || !sameShape(ptr, offset))
        return emitOpError("pointer and offset must have matching scalar or static 1D shapes");
    if (!mlir::isa<PointerType>(elementType(ptr)))
        return emitOpError("requires pointer operands");
    if (!elementType(offset).isSignlessInteger(32) &&
        !elementType(offset).isSignlessInteger(64))
        return emitOpError("offset must have i32 or i64 elements");
    if (getResult().getType() != ptr)
        return emitOpError("result type must match pointer type");
    return mlir::success();
}

mlir::LogicalResult mini_triton::LoadOp::verify() {
    if (getOther().getType() != getResult().getType())
        return emitOpError("other type must match result type");
    return verifyMemory(getOperation(), getPtr().getType(),
                        getResult().getType(), getMask().getType());
}

mlir::LogicalResult mini_triton::StoreOp::verify() {
    return verifyMemory(getOperation(), getPtr().getType(),
                        getValue().getType(), getMask().getType());
}
