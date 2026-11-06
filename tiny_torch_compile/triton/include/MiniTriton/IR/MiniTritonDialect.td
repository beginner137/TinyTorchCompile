include "mlir/IR/OpBase.td"

def MiniTriton_Dialect : Dialect {
  let name = "mini";
  let cppNamespace = "::mini_triton";
}
