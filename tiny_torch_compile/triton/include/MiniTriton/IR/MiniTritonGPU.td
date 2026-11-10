include "mlir/IR/OpBase.td"

def MiniTritonGPU_Dialect : Dialect {
  let name = "mini_gpu";
  let cppNamespace = "::mini_triton::gpu";
  let useDefaultAttributePrinterParser = 1;
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

def MiniGPU_MakeRangeOp : MiniGPU_Op<"make_range"> {
  let summary = "Create a range with a GPU layout";

  let arguments = (ins
    I64Attr:$start,
    I64Attr:$end,
    I64Attr:$num_warps,
    I64Attr:$elements_per_lane
  );

  let results = (outs AnyRankedTensor:$result);
}