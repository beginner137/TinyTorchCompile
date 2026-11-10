#include "MiniTriton/IR/BlockedLayoutUtils.h"
#include "mlir/IR/MLIRContext.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdint>
#include <set>

int main() {
    mlir::MLIRContext context;
    context.getOrLoadDialect<mini_triton::gpu::MiniTritonGPUDialect>();
    auto layout = mini_triton::gpu::BlockedLayoutAttr::get(&context, 2, 32, 4);
    std::set<uint64_t> indices;

    // Explicit checks remain active in Release builds, unlike assert().
    for (unsigned warp = 0; warp < 4; ++warp) {
        for (unsigned lane = 0; lane < 32; ++lane) {
            for (unsigned slot = 0; slot < 2; ++slot) {
                auto index = mini_triton::getTensorIndex(layout, warp, lane, slot);
                if (index >= 256) {
                    llvm::errs() << "Out-of-range index " << index << " at warp "
                                 << warp << ", lane " << lane << ", slot " << slot << "\n";
                    return 1;
                }
                if (!indices.insert(index).second) {
                    llvm::errs() << "Duplicate index " << index << " at warp "
                                 << warp << ", lane " << lane << ", slot " << slot << "\n";
                    return 1;
                }
            }
        }
    }

    if (indices.size() != 256) {
        llvm::errs() << "Expected 256 unique indices, got " << indices.size() << "\n";
        return 1;
    }
    llvm::outs() << "Blocked layout covers all 256 indices exactly once.\n";
    return 0;
}
