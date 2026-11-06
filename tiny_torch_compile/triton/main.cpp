
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "llvm/Support/raw_ostream.h"
#include "MiniTriton/IR/MiniTritonDialect.h"
#include "mlir/IR/OperationSupport.h"

int main()
{
    mlir::MLIRContext context;

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

    module.print(llvm::outs());
    llvm::outs() << "\n";
    return 0;
}
