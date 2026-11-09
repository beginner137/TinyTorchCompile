#pragma once

namespace mini_triton
{

    enum class GPUVendor
    {
        NVIDIA,
        AMD
    };

    struct TargetInfo
    {
        GPUVendor vendor;
        unsigned warpSize;
        unsigned numWarps;
    };

}