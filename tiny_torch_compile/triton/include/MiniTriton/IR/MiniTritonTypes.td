include "mlir/IR/AttrTypeBase.td"
include "MiniTriton/IR/MiniTritonDialect.td"

def MiniTriton_PointerType : TypeDef<MiniTriton_Dialect, "Pointer"> {
  let mnemonic = "ptr";
  let summary = "Pointer to a scalar integer or floating-point element";
  let parameters = (ins "::mlir::Type":$pointeeType);
  let assemblyFormat = "`<` $pointeeType `>`";
  let genVerifyDecl = 1;
}
