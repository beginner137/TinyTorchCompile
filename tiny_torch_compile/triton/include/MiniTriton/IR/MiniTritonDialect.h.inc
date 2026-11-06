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
};

} // namespace mini_triton
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::MiniTritonDialect)
