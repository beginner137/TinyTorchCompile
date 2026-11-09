
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

int main()
{
    mlir::MLIRContext context;
    context.getOrLoadDialect<mlir::func::FuncDialect>();

    auto *dialect = context.getOrLoadDialect<mini_triton::MiniTritonDialect>();

    llvm::outs()
        << "Loaded dialect: "
        << dialect->getNamespace() << "\n";

    context.getOrLoadDialect<mini_triton::gpu::MiniTritonGPUDialect>();

    mlir::OperationName name("mini_gpu.splat", &context);
    llvm::outs() << "GPU splat registered: "
                 << name.isRegistered() << "\n";

    mlir::OpBuilder builder(&context);

    auto module = mlir::ModuleOp::create(
        builder.getUnknownLoc());

    mlir::OperationName opName("mini.splat", &context);

    llvm::outs() << "mini.splat registered: "
                 << opName.isRegistered() << "\n";

    mini_triton::buildDemo(module);
    if (mlir::failed(mlir::verify(module.getOperation())))
    {
        llvm::errs() << "Invalid MLIR module!\n";
        return 1;
    }
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

    mlir::PassManager pm(&context);
    pm.addPass(mini_triton::createLowerToGPUPass());
    if (mlir::failed(pm.run(module)))
    {
        llvm::errs() << "GPU lowering failed\n";
        return 1;
    }

    printReturnProducer(); // After lowering
    module.print(llvm::outs());
    return 0;
}
