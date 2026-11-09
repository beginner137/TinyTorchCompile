/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mini_triton::gpu {

/// 1D GPU blocked layout
class BlockedLayoutAttr;
namespace detail {

struct BlockedLayoutAttrStorage;

} // namespace detail
class BlockedLayoutAttr : public ::mlir::Attribute::AttrBase<BlockedLayoutAttr, ::mlir::Attribute, detail::BlockedLayoutAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mini_gpu.blocked";
  static constexpr ::llvm::StringLiteral dialectName = "mini_gpu";
  static BlockedLayoutAttr get(::mlir::MLIRContext *context, unsigned sizePerThread, unsigned threadsPerWarp, unsigned warpsPerCTA);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"blocked"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  unsigned getSizePerThread() const;
  unsigned getThreadsPerWarp() const;
  unsigned getWarpsPerCTA() const;
};

} // namespace mini_triton::gpu
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::gpu::BlockedLayoutAttr)

#endif // GET_ATTRDEF_CLASSES

