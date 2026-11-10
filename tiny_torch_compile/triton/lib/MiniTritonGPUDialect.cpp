#include "MiniTriton/IR/MiniTritonGPU.h"
#include "MiniTriton/IR/MiniTritonGPUOps.h"
#include "MiniTriton/IR/MiniTritonGPUDialect.cpp.inc"
#include "MiniTriton/IR/MiniTritonGPUAttrs.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

#define GET_ATTRDEF_CLASSES
#include "MiniTriton/IR/MiniTritonGPUAttrs.cpp.inc"

void mini_triton::gpu::MiniTritonGPUDialect::initialize()
{
    addOperations<
#define GET_OP_LIST
#include "MiniTriton/IR/MiniTritonGPUOps.cpp.inc"
        >();

    addAttributes<
#define GET_ATTRDEF_LIST
#include "MiniTriton/IR/MiniTritonGPUAttrs.cpp.inc"
        >();
}
