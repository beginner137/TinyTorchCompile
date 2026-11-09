include "mlir/IR/OpBase.td"

def MiniTriton_Dialect : Dialect {
  let name = "mini";
  let cppNamespace = "::mini_triton";
  let useDefaultTypePrinterParser = 1;
  let extraClassDeclaration = [{ void registerTypes(); }];
}
