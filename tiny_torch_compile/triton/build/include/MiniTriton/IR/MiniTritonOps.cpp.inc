/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonOps.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mini_triton::MakeRangeOp,
::mini_triton::SplatOp
#endif // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//


static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MiniTritonOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::RankedTensorType>(type))) && ([](::mlir::Type elementType) { return !((::llvm::isa<::mlir::TokenType>(elementType))); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be ranked tensor of any non-token type values, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MiniTritonOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(32)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 32-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(64)))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 64-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MiniTritonOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
namespace mini_triton {


//===----------------------------------------------------------------------===//
// ::mini_triton::MakeRangeOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

MakeRangeOpGenericAdaptorBase::MakeRangeOpGenericAdaptorBase(MakeRangeOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

uint64_t MakeRangeOpGenericAdaptorBase::getStart() {
  auto attr = getStartAttr();
  return attr.getValue().getZExtValue();
}

uint64_t MakeRangeOpGenericAdaptorBase::getEnd() {
  auto attr = getEndAttr();
  return attr.getValue().getZExtValue();
}


} // namespace detail
MakeRangeOpAdaptor::MakeRangeOpAdaptor(MakeRangeOp op) : MakeRangeOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult MakeRangeOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_end = getProperties().end; (void)tblgen_end;
  if (!tblgen_end) return emitError(loc, "'mini.make_range' op requires attribute 'end'");
  auto tblgen_start = getProperties().start; (void)tblgen_start;
  if (!tblgen_start) return emitError(loc, "'mini.make_range' op requires attribute 'start'");

  if (tblgen_start && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_start))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_start).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini.make_range' op attribute 'start' failed to satisfy constraint: 64-bit signless integer attribute");

  if (tblgen_end && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_end))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_end).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini.make_range' op attribute 'end' failed to satisfy constraint: 64-bit signless integer attribute");
  return ::mlir::success();
}

::llvm::LogicalResult MakeRangeOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.end;
       auto attr = dict.get("end");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `end` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.start;
       auto attr = dict.get("start");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `start` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute MakeRangeOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.end;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("end",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.start;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("start",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code MakeRangeOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine(
    llvm::hash_value(prop.end.getAsOpaquePointer()), 
    llvm::hash_value(prop.start.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> MakeRangeOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "end")
      return prop.end;

    if (name == "start")
      return prop.start;
  return std::nullopt;
}

void MakeRangeOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "end") {
       prop.end = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.end)>>(value);
       return;
    }

    if (name == "start") {
       prop.start = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.start)>>(value);
       return;
    }
}

void MakeRangeOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.end) attrs.append("end", prop.end);

    if (prop.start) attrs.append("start", prop.start);
}

::llvm::LogicalResult MakeRangeOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getEndAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps1(attr, "end", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getStartAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps1(attr, "start", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult MakeRangeOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.end)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.start)))
    return ::mlir::failure();
  return ::mlir::success();
}

void MakeRangeOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.end);
  writer.writeAttribute(prop.start);
}

uint64_t MakeRangeOp::getStart() {
  auto attr = getStartAttr();
  return attr.getValue().getZExtValue();
}

uint64_t MakeRangeOp::getEnd() {
  auto attr = getEndAttr();
  return attr.getValue().getZExtValue();
}

void MakeRangeOp::setStart(uint64_t attrValue) {
  getProperties().start = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void MakeRangeOp::setEnd(uint64_t attrValue) {
  getProperties().end = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end) {
  odsState.getOrAddProperties<Properties>().start = start;
  odsState.getOrAddProperties<Properties>().end = end;
  odsState.addTypes(result);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end) {
  odsState.getOrAddProperties<Properties>().start = start;
  odsState.getOrAddProperties<Properties>().end = end;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, uint64_t start, uint64_t end) {
  odsState.getOrAddProperties<Properties>().start = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), start);
  odsState.getOrAddProperties<Properties>().end = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), end);
  odsState.addTypes(result);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, uint64_t start, uint64_t end) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, uint64_t start, uint64_t end) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end) {
  odsState.getOrAddProperties<Properties>().start = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), start);
  odsState.getOrAddProperties<Properties>().end = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), end);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
}

void MakeRangeOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    (void)odsState.getOrAddProperties<MakeRangeOp::Properties>();
    ::mlir::PropertyRef properties = odsState.getRawProperties();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void MakeRangeOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult MakeRangeOp::verifyInvariantsImpl() {
  auto tblgen_end = getProperties().end; (void)tblgen_end;
  if (!tblgen_end) return emitOpError("requires attribute 'end'");
  auto tblgen_start = getProperties().start; (void)tblgen_start;
  if (!tblgen_start) return emitOpError("requires attribute 'start'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps1(*this, tblgen_start, "start")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps1(*this, tblgen_end, "end")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult MakeRangeOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::llvm::LogicalResult MakeRangeOp::setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
  // keep track of used keys in the input dictionary to be able to error out
  // if there are some unknown ones.
  ::mlir::DenseSet<::mlir::StringAttr> usedKeys;
  ::mlir::MLIRContext *ctx = dict.getContext();
  (void)ctx;
  {

    auto &propStorage = prop.start;
    auto startAttrName = ::mlir::StringAttr::get(ctx, "start");
    auto attr = dict.get(startAttrName);
    usedKeys.insert(startAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for start in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `start` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  {

    auto &propStorage = prop.end;
    auto endAttrName = ::mlir::StringAttr::get(ctx, "end");
    auto attr = dict.get(endAttrName);
    usedKeys.insert(endAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for end in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `end` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  for (::mlir::NamedAttribute attr : dict) {
    if (!usedKeys.contains(attr.getName()))
      return emitError() << "unknown key '" << attr.getName() <<
          "' when parsing properties dictionary";
  }
  return ::mlir::success();
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::MakeRangeOp)
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::detail::MakeRangeOpGenericAdaptorBase::Properties)

namespace mini_triton {


//===----------------------------------------------------------------------===//
// ::mini_triton::SplatOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

SplatOpGenericAdaptorBase::SplatOpGenericAdaptorBase(SplatOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}


} // namespace detail
SplatOpAdaptor::SplatOpAdaptor(SplatOp op) : SplatOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult SplatOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::LogicalResult SplatOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
      return ::mlir::success();
}

::mlir::Attribute SplatOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code SplatOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine();
}

std::optional<mlir::Attribute> SplatOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
  return std::nullopt;
}

void SplatOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
}

void SplatOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
}

::llvm::LogicalResult SplatOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    return ::mlir::success();
}

void SplatOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input) {
  odsState.addOperands(input);
  odsState.addTypes(result);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(input)>(input));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(input)>(input));
}

void SplatOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input));
}

void SplatOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void SplatOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult SplatOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult SplatOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::llvm::LogicalResult SplatOp::setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
  // keep track of used keys in the input dictionary to be able to error out
  // if there are some unknown ones.
  ::mlir::DenseSet<::mlir::StringAttr> usedKeys;
  ::mlir::MLIRContext *ctx = dict.getContext();
  (void)ctx;

  for (::mlir::NamedAttribute attr : dict) {
    if (!usedKeys.contains(attr.getName()))
      return emitError() << "unknown key '" << attr.getName() <<
          "' when parsing properties dictionary";
  }
  return ::mlir::success();
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::SplatOp)


#endif // GET_OP_CLASSES

