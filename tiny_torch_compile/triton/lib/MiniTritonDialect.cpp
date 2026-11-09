#include "MiniTriton/IR/MiniTritonDialect.h"
#include "MiniTriton/IR/MiniTritonOps.h"
#include "MiniTriton/IR/MiniTritonTypes.h"

#include "MiniTriton/IR/MiniTritonDialect.cpp.inc"

void mini_triton::MiniTritonDialect::initialize()
{
    registerTypes();
    addOperations<
#define GET_OP_LIST
#include "MiniTriton/IR/MiniTritonOps.cpp.inc"
    >();
}
