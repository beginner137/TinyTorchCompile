#pragma once

#include "mlir/IR/BuiltinOps.h"
#include "mlir/Support/LogicalResult.h"

namespace mini_triton
{
    mlir::LogicalResult lowerToGPU(mlir::ModuleOp module);
}