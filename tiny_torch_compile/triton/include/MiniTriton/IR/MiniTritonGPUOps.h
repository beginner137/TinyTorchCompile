#pragma once

#include "MiniTriton/IR/MiniTritonGPU.h"
#include "mlir/Bytecode/BytecodeOpInterface.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/BuiltinTypes.h"

#define GET_OP_CLASSES
#include "MiniTriton/IR/MiniTritonGPUOps.h.inc"
