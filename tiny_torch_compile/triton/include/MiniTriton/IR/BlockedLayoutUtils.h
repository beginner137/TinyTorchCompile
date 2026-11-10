
#pragma once

#include "MiniTriton/IR/MiniTritonGPUAttrs.h"
#include <cassert>
#include <cstdint>

namespace mini_triton
{

    inline uint64_t getTensorIndex(
        gpu::BlockedLayoutAttr layout,
        uint64_t warp,
        uint64_t lane,
        uint64_t slot)
    {
        assert(warp < layout.getWarpsPerCTA());
        assert(lane < layout.getThreadsPerWarp());
        assert(slot < layout.getSizePerThread());

        return (warp * layout.getThreadsPerWarp() + lane) * layout.getSizePerThread() + slot;
    }

} // namespace mini_triton
