/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mini_triton {

/// Pointer to a scalar integer or floating-point element
class PointerType;
namespace detail {

struct PointerTypeStorage;

} // namespace detail
class PointerType : public ::mlir::Type::TypeBase<PointerType, ::mlir::Type, detail::PointerTypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mini.ptr";
  static constexpr ::llvm::StringLiteral dialectName = "mini";
  using Base::getChecked;
  static PointerType get(::mlir::MLIRContext *context, ::mlir::Type pointeeType);
  static PointerType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::mlir::Type pointeeType);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::Type pointeeType);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::Type pointeeType);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"ptr"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::Type getPointeeType() const;
};

} // namespace mini_triton
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::PointerType)

#endif // GET_TYPEDEF_CLASSES

