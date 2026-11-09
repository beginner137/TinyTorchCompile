#pragma once

#include "mlir/IR/BuiltinOps.h"
#include "mlir/Support/LogicalResult.h"
#include <memory>
#include "mlir/Pass/Pass.h"
#include "MiniTriton/Target/TargetInfo.h"

namespace mini_triton
{
    mlir::LogicalResult lowerToGPU(mlir::ModuleOp module, TargetInfo target);
    std::unique_ptr<mlir::Pass> createLowerToGPUPass(TargetInfo target);
}
