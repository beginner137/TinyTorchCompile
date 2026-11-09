
include "mlir/IR/AttrTypeBase.td"
include "MiniTriton/IR/MiniTritonGPU.td"

def MiniGPU_BlockedLayoutAttr
    : AttrDef<MiniTritonGPU_Dialect, "BlockedLayout"> {

  let mnemonic = "blocked";

  let summary = "1D GPU blocked layout";

  let parameters = (ins
    "unsigned":$sizePerThread,
    "unsigned":$threadsPerWarp,
    "unsigned":$warpsPerCTA
  );

  let assemblyFormat =
    "`<` $sizePerThread `,` $threadsPerWarp `,` $warpsPerCTA `>`";
}
