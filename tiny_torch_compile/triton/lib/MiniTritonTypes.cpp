#include "MiniTriton/IR/MiniTritonTypes.h"
#include "mlir/IR/DialectImplementation.h"
#include "mlir/IR/Builders.h"
#include "llvm/ADT/TypeSwitch.h"

#define GET_TYPEDEF_CLASSES
#include "MiniTriton/IR/MiniTritonTypes.cpp.inc"

void mini_triton::MiniTritonDialect::registerTypes() {
    addTypes<
#define GET_TYPEDEF_LIST
#include "MiniTriton/IR/MiniTritonTypes.cpp.inc"
    >();
}

mlir::LogicalResult mini_triton::PointerType::verify(
    llvm::function_ref<mlir::InFlightDiagnostic()> emitError,
    mlir::Type pointeeType)
{
    if (!pointeeType.isIntOrFloat())
        return emitError() << "pointer pointee must be an integer or float";
    return mlir::success();
}
