#include "MiniTriton/Frontend/Frontend.h"
#include "MiniTriton/IR/MiniTritonOps.h"

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Builders.h"

void mini_triton::buildDemo(mlir::ModuleOp module)
{
    mlir::OpBuilder builder(module.getContext());

    auto loc = builder.getUnknownLoc();
    auto i32 = builder.getI32Type();
    constexpr int64_t start = 0;
    constexpr int64_t end = 256;
    auto tensorType = mlir::RankedTensorType::get({end - start}, i32);

    // Create function: () -> tensor<256xi32>
    builder.setInsertionPointToStart(module.getBody());

    auto funcType = builder.getFunctionType({}, {tensorType});
    auto func = mlir::func::FuncOp::create(
        builder, loc, "demo", funcType);

    // Create function body
    auto *block = func.addEntryBlock();
    builder.setInsertionPointToStart(block);

    auto range = mini_triton::MakeRangeOp::create(
        builder, loc,
        tensorType,
        builder.getI64IntegerAttr(start),
        builder.getI64IntegerAttr(end));

    mlir::func::ReturnOp::create(
        builder, loc, range.getResult());
}
