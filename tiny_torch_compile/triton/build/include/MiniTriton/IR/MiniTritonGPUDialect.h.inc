/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonGPU.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mini_triton::gpu {


class MiniTritonGPUDialect : public ::mlir::Dialect {
  explicit MiniTritonGPUDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~MiniTritonGPUDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("mini_gpu");
  }
};

} // namespace mini_triton::gpu
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::gpu::MiniTritonGPUDialect)
