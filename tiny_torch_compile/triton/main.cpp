
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "llvm/Support/raw_ostream.h"
#include "MiniTriton/IR/MiniTritonDialect.h"
#include "mlir/IR/OperationSupport.h"
#include "MiniTriton/IR/MiniTritonOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "MiniTriton/Frontend/Frontend.h"

int main()
{
    mlir::MLIRContext context;
    context.getOrLoadDialect<mlir::func::FuncDialect>();

    auto *dialect = context.getOrLoadDialect<mini_triton::MiniTritonDialect>();

    llvm::outs()
        << "Loaded dialect: "
        << dialect->getNamespace() << "\n";
    mlir::OpBuilder builder(&context);

    auto module = mlir::ModuleOp::create(
        builder.getUnknownLoc());

    mlir::OperationName opName("mini.splat", &context);

    llvm::outs() << "mini.splat registered: "
                 << opName.isRegistered() << "\n";

    mini_triton::buildDemo(module);
    module.print(llvm::outs());
    llvm::outs() << "\n";
    return 0;
}
