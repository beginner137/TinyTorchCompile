include "MiniTriton/IR/MiniTritonDialect.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

// Base class for operations in our dialect.
class MiniTriton_Op<string mnemonic, list<Trait> traits = []>
    : Op<MiniTriton_Dialect, mnemonic, traits>;

// Our first operation.
def MiniTriton_SplatOp : MiniTriton_Op<"splat", [Pure]> {
  let summary = "Broadcast a scalar to a tensor";

  let arguments = (ins AnyType:$input);
  let results = (outs AnyRankedTensor:$result);
  let hasVerifier = 1;
}

def MiniTriton_MakeRangeOp : MiniTriton_Op<"make_range", [Pure]> {
  let arguments = (ins I64Attr:$start, I64Attr:$end);
  let results = (outs AnyRankedTensor:$result);
  let hasVerifier = 1;
}

def MiniTriton_GetProgramIdOp : MiniTriton_Op<"get_program_id", [Pure]> {
  let summary = "Program index along grid axis 0, 1, or 2";
  let arguments = (ins I32Attr:$axis);
  let results = (outs I32:$result);
  let hasVerifier = 1;
}

def MiniTriton_AddPtrOp : MiniTriton_Op<"addptr", [Pure]> {
  let summary = "Advance typed pointers by element offsets (not bytes)";
  let arguments = (ins AnyType:$ptr, AnyType:$offset);
  let results = (outs AnyType:$result);
  let hasVerifier = 1;
}

def MiniTriton_LoadOp : MiniTriton_Op<"load", [MemoryEffects<[MemRead]>]> {
  let summary = "Load active lanes; masked-off lanes return other";
  let arguments = (ins AnyType:$ptr, AnyType:$mask, AnyType:$other);
  let results = (outs AnyType:$result);
  let hasVerifier = 1;
}

def MiniTriton_StoreOp : MiniTriton_Op<"store", [MemoryEffects<[MemWrite]>]> {
  let summary = "Store active lanes; masked-off lanes do not access memory";
  let arguments = (ins AnyType:$ptr, AnyType:$value, AnyType:$mask);
  let hasVerifier = 1;
}
