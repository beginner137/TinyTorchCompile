#include "MiniTriton/IR/MiniTritonGPU.h"
#include "MiniTriton/IR/MiniTritonGPUOps.h"

#include "MiniTriton/IR/MiniTritonGPU.cpp.inc"

void mini_triton::gpu::MiniTritonGPUDialect::initialize()
{
    addOperations<
#define GET_OP_LIST
#include "MiniTriton/IR/MiniTritonGPUOps.cpp.inc"
        >();
}