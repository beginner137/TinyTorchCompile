
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "llvm/Support/raw_ostream.h"
#include "MiniTriton/IR/MiniTritonDialect.h"
#include "mlir/IR/OperationSupport.h"
#include "MiniTriton/IR/MiniTritonOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "MiniTriton/Frontend/Frontend.h"
#include "mlir/IR/Verifier.h"
#include "MiniTriton/IR/MiniTritonGPUOps.h"
#include "MiniTriton/Conversion/LowerToGPU.h"
#include "mlir/Pass/PassManager.h"
#include "MiniTriton/IR/MiniTritonGPUAttrs.h"
#include "MiniTriton/IR/BlockedLayoutUtils.h"

int main()
{
    mlir::MLIRContext context;
    context.getOrLoadDialect<mlir::func::FuncDialect>();

    auto *dialect = context.getOrLoadDialect<mini_triton::MiniTritonDialect>();

    llvm::outs()
        << "Loaded dialect: "
        << dialect->getNamespace() << "\n";

    context.getOrLoadDialect<mini_triton::gpu::MiniTritonGPUDialect>();
    mlir::OpBuilder builder(&context);

    // NVIDIA: 2 elements per lane, 32 lanes, 4 warps.
    auto layout = mini_triton::gpu::BlockedLayoutAttr::get(
        &context, 2, 32, 4);

    auto tensorType = mlir::RankedTensorType::get(
        {256},
        builder.getI32Type(),
        layout);

    llvm::outs() << "Layout: " << layout << "\n";
    llvm::outs() << "Tensor type: " << tensorType << "\n";

    mlir::OperationName splatName(mini_triton::gpu::SplatOp::getOperationName(), &context);
    llvm::outs() << "GPU splat registered: "
                 << splatName.isRegistered() << "\n";

    mlir::OperationName rangeName(mini_triton::gpu::MakeRangeOp::getOperationName(), &context);

    llvm::outs() << "GPU make_range registered: "
                 << rangeName.isRegistered() << "\n";

    auto module = mlir::ModuleOp::create(
        builder.getUnknownLoc());

    mlir::OperationName opName(mini_triton::MakeRangeOp::getOperationName(), &context);

    llvm::outs() << "mini.make_range registered: "
                 << opName.isRegistered() << "\n";

    mini_triton::buildDemo(module);
    if (mlir::failed(mlir::verify(module.getOperation())))
    {
        llvm::errs() << "Invalid MLIR module!\n";
        return 1;
    }
    llvm::outs() << "Before GPU pass:\n";
    module.print(llvm::outs());
    llvm::outs() << "\n";

    auto printReturnProducer = [&]()
    {
        module.walk([](mlir::func::ReturnOp ret)
                    {
        auto *producer =
            ret.getOperand(0).getDefiningOp();

        llvm::outs() << "Return value produced by: "
                     << producer->getName() << "\n"; });
    };

    printReturnProducer(); // Before lowering
    mini_triton::TargetInfo target{
        mini_triton::GPUVendor::NVIDIA,
        32, // NVIDIA warp size
        4   // warps per CTA
    };

    mlir::PassManager pm(&context);
    pm.addPass(mini_triton::createLowerToGPUPass(target));
    if (mlir::failed(pm.run(module)))
    {
        llvm::errs() << "GPU lowering failed\n";
        return 1;
    }

    module.walk([](mini_triton::gpu::MakeRangeOp op)
                {
    auto type = op.getResult().getType();

    auto layout = mlir::cast<
        mini_triton::gpu::BlockedLayoutAttr
    >(type.getEncoding());

    auto index = mini_triton::getTensorIndex(
        layout,
        1, // Warp
        4, // Lane
        1  // Register slot
    );

    llvm::outs() << "Tensor index: " << index << "\n"; });
    printReturnProducer(); // After lowering
    llvm::outs() << "After GPU pass:\n";
    module.print(llvm::outs());
    return 0;
}
