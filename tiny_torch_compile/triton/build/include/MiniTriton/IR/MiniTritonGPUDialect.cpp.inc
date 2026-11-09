/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonGPU.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::gpu::MiniTritonGPUDialect)
namespace mini_triton::gpu {


MiniTritonGPUDialect::MiniTritonGPUDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<MiniTritonGPUDialect>())
    
     {
  
  initialize();
}

MiniTritonGPUDialect::~MiniTritonGPUDialect() = default;


} // namespace mini_triton::gpu
