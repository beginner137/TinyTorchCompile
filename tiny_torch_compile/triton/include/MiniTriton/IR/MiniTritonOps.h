#pragma once
#include "mlir/Bytecode/BytecodeOpInterface.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"
#include "MiniTriton/IR/MiniTritonTypes.h"

#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/BuiltinTypes.h"
#include "MiniTriton/IR/MiniTritonDialect.h"

#define GET_OP_CLASSES
#include "MiniTriton/IR/MiniTritonOps.h.inc"
