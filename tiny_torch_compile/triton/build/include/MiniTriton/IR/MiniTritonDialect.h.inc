/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonDialect.td                                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mini_triton {


class MiniTritonDialect : public ::mlir::Dialect {
  explicit MiniTritonDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~MiniTritonDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("mini");
  }

  /// Parse a type registered to this dialect.
  ::mlir::Type parseType(::mlir::DialectAsmParser &parser) const override;

  /// Print a type registered to this dialect.
  void printType(::mlir::Type type,
                 ::mlir::DialectAsmPrinter &os) const override;
 void registerTypes(); };

} // namespace mini_triton
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::MiniTritonDialect)
