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