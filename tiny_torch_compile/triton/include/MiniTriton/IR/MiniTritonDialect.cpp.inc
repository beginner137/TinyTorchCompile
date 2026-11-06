/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonDialect.td                                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::MiniTritonDialect)
namespace mini_triton {


MiniTritonDialect::MiniTritonDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<MiniTritonDialect>())
    
     {
  
  initialize();
}

MiniTritonDialect::~MiniTritonDialect() = default;


} // namespace mini_triton
