include "mlir/IR/OpBase.td"

def MiniTritonGPU_Dialect : Dialect {
  let name = "mini_gpu";
  let cppNamespace = "::mini_triton::gpu";
}

class MiniGPU_Op<string mnemonic>
    : Op<MiniTritonGPU_Dialect, mnemonic>;

def MiniGPU_SplatOp : MiniGPU_Op<"splat"> {
  let arguments = (ins
    I32:$input,
    I64Attr:$num_warps,
    I64Attr:$elements_per_lane
  );

  let results = (outs AnyRankedTensor:$result);
}