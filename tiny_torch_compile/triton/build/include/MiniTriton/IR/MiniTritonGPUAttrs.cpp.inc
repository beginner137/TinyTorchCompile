/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mini_triton::gpu::BlockedLayoutAttr

#endif // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mini_triton::gpu::BlockedLayoutAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mini_triton::gpu::BlockedLayoutAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::llvm::LogicalResult>(def)    .Case<::mini_triton::gpu::BlockedLayoutAttr>([&](auto t) {
      printer << ::mini_triton::gpu::BlockedLayoutAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mini_triton::gpu {

namespace detail {

struct BlockedLayoutAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<unsigned, unsigned, unsigned>;
  BlockedLayoutAttrStorage(unsigned sizePerThread, unsigned threadsPerWarp, unsigned warpsPerCTA) : sizePerThread(std::move(sizePerThread)), threadsPerWarp(std::move(threadsPerWarp)), warpsPerCTA(std::move(warpsPerCTA)) {}

  KeyTy getAsKey() const {
    return KeyTy(sizePerThread, threadsPerWarp, warpsPerCTA);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (sizePerThread == std::get<0>(tblgenKey)) && (threadsPerWarp == std::get<1>(tblgenKey)) && (warpsPerCTA == std::get<2>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey));
  }

  static BlockedLayoutAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto sizePerThread = std::move(std::get<0>(tblgenKey));
    auto threadsPerWarp = std::move(std::get<1>(tblgenKey));
    auto warpsPerCTA = std::move(std::get<2>(tblgenKey));
    return new (allocator.allocate<BlockedLayoutAttrStorage>()) BlockedLayoutAttrStorage(std::move(sizePerThread), std::move(threadsPerWarp), std::move(warpsPerCTA));
  }

  unsigned sizePerThread;
  unsigned threadsPerWarp;
  unsigned warpsPerCTA;
};

} // namespace detail
BlockedLayoutAttr BlockedLayoutAttr::get(::mlir::MLIRContext *context, unsigned sizePerThread, unsigned threadsPerWarp, unsigned warpsPerCTA) {
  return Base::get(context, std::move(sizePerThread), std::move(threadsPerWarp), std::move(warpsPerCTA));
}

::mlir::Attribute BlockedLayoutAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<unsigned> _result_sizePerThread;
  ::mlir::FailureOr<unsigned> _result_threadsPerWarp;
  ::mlir::FailureOr<unsigned> _result_warpsPerCTA;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'sizePerThread'
  _result_sizePerThread = ::mlir::FieldParser<unsigned>::parse(odsParser);
  if (::mlir::failed(_result_sizePerThread)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MiniGPU_BlockedLayoutAttr parameter 'sizePerThread' which is to be a `unsigned`");
    return {};
  }
  // Parse literal ','
  if (odsParser.parseComma()) return {};

  // Parse variable 'threadsPerWarp'
  _result_threadsPerWarp = ::mlir::FieldParser<unsigned>::parse(odsParser);
  if (::mlir::failed(_result_threadsPerWarp)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MiniGPU_BlockedLayoutAttr parameter 'threadsPerWarp' which is to be a `unsigned`");
    return {};
  }
  // Parse literal ','
  if (odsParser.parseComma()) return {};

  // Parse variable 'warpsPerCTA'
  _result_warpsPerCTA = ::mlir::FieldParser<unsigned>::parse(odsParser);
  if (::mlir::failed(_result_warpsPerCTA)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MiniGPU_BlockedLayoutAttr parameter 'warpsPerCTA' which is to be a `unsigned`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_sizePerThread));
  assert(::mlir::succeeded(_result_threadsPerWarp));
  assert(::mlir::succeeded(_result_warpsPerCTA));
  return BlockedLayoutAttr::get(odsParser.getContext(),
      unsigned((*_result_sizePerThread)),
      unsigned((*_result_threadsPerWarp)),
      unsigned((*_result_warpsPerCTA)));
}

void BlockedLayoutAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getSizePerThread());
  odsPrinter << ",";
  odsPrinter << ' ';
  odsPrinter.printStrippedAttrOrType(getThreadsPerWarp());
  odsPrinter << ",";
  odsPrinter << ' ';
  odsPrinter.printStrippedAttrOrType(getWarpsPerCTA());
  odsPrinter << ">";
}

unsigned BlockedLayoutAttr::getSizePerThread() const {
  return getImpl()->sizePerThread;
}

unsigned BlockedLayoutAttr::getThreadsPerWarp() const {
  return getImpl()->threadsPerWarp;
}

unsigned BlockedLayoutAttr::getWarpsPerCTA() const {
  return getImpl()->warpsPerCTA;
}


} // namespace mini_triton::gpu
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::gpu::BlockedLayoutAttr)

#endif // GET_ATTRDEF_CLASSES

