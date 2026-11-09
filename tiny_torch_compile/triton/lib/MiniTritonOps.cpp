#include "MiniTriton/IR/MiniTritonOps.h"
#include "mlir/IR/ImplicitLocOpBuilder.h"

#define GET_OP_CLASSES
#include "MiniTriton/IR/MiniTritonOps.cpp.inc"

mlir::LogicalResult mini_triton::SplatOp::verify()
{
    auto inputType = getInput().getType();

    auto outputType =
        mlir::cast<mlir::RankedTensorType>(
            getResult().getType());

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

    if (end <= start || end - start != type.getNumElements())
        return emitOpError("range length must match tensor size");

    return mlir::success();
}