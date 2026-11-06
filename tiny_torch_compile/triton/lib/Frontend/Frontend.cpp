#include "MiniTriton/Frontend/Frontend.h"
#include "MiniTriton/IR/MiniTritonOps.h"

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Builders.h"

void mini_triton::buildDemo(mlir::ModuleOp module)
{
    mlir::OpBuilder builder(module.getContext());

    auto loc = builder.getUnknownLoc();
    auto i32 = builder.getI32Type();
    auto tensorType = mlir::RankedTensorType::get({256}, i32);

    // Create function: (i32) -> tensor<256xi32>
    builder.setInsertionPointToStart(module.getBody());

    auto funcType = builder.getFunctionType({i32}, {tensorType});
    auto func = builder.create<mlir::func::FuncOp>(
        loc, "demo", funcType);

    // Create function body
    auto *block = func.addEntryBlock();
    builder.setInsertionPointToStart(block);

    // Create our custom mini.splat operation
    auto splat = builder.create<mini_triton::SplatOp>(
        loc, tensorType, block->getArgument(0));

    builder.create<mlir::func::ReturnOp>(
        loc, splat.getResult());
}
