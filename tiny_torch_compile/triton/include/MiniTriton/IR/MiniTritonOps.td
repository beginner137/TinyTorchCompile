include "MiniTriton/IR/MiniTritonDialect.td"

// Base class for operations in our dialect.
class MiniTriton_Op<string mnemonic>
    : Op<MiniTriton_Dialect, mnemonic>;

// Our first operation.
def MiniTriton_SplatOp : MiniTriton_Op<"splat"> {
  let summary = "Broadcast a scalar to a tensor";

  let arguments = (ins I32:$input);
  let results = (outs AnyRankedTensor:$result);
  let hasVerifier = 1;
}
