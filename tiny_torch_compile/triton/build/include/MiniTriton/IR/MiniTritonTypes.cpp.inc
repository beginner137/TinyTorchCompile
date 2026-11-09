/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mini_triton::PointerType

#endif // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mini_triton::PointerType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mini_triton::PointerType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mini_triton::PointerType>([&](auto t) {
      printer << ::mini_triton::PointerType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mini_triton {

namespace detail {

struct PointerTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::mlir::Type>;
  PointerTypeStorage(::mlir::Type pointeeType) : pointeeType(std::move(pointeeType)) {}

  KeyTy getAsKey() const {
    return KeyTy(pointeeType);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (pointeeType == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static PointerTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto pointeeType = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<PointerTypeStorage>()) PointerTypeStorage(std::move(pointeeType));
  }

  ::mlir::Type pointeeType;
};

} // namespace detail
PointerType PointerType::get(::mlir::MLIRContext *context, ::mlir::Type pointeeType) {
  return Base::get(context, std::move(pointeeType));
}

PointerType PointerType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::mlir::Type pointeeType) {
  return Base::getChecked(emitError, context, std::move(pointeeType));
}

::llvm::LogicalResult PointerType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::Type pointeeType) {
  if (::mlir::failed(verify(emitError, pointeeType)))
    return ::mlir::failure();
  return ::mlir::success();
}

::mlir::Type PointerType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::mlir::Type> _result_pointeeType;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'pointeeType'
  _result_pointeeType = ::mlir::FieldParser<::mlir::Type>::parse(odsParser);
  if (::mlir::failed(_result_pointeeType)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MiniTriton_PointerType parameter 'pointeeType' which is to be a `::mlir::Type`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_pointeeType));
  return odsParser.getChecked<PointerType>(odsLoc, odsParser.getContext(),
      ::mlir::Type((*_result_pointeeType)));
}

void PointerType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getPointeeType());
  odsPrinter << ">";
}

::mlir::Type PointerType::getPointeeType() const {
  return getImpl()->pointeeType;
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::PointerType)
namespace mini_triton {


/// Parse a type registered to this dialect.
::mlir::Type MiniTritonDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void MiniTritonDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}

} // namespace mini_triton

#endif // GET_TYPEDEF_CLASSES

