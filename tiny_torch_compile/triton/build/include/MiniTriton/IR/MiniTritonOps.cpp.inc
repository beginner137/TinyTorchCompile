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

::mini_triton::AddPtrOp,
::mini_triton::GetProgramIdOp,
::mini_triton::LoadOp,
::mini_triton::MakeRangeOp,
::mini_triton::SplatOp,
::mini_triton::StoreOp
#endif // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//


static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MiniTritonOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(!((::llvm::isa<::mlir::TokenType>(type))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be any non-token type, but got " << type;
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

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MiniTritonOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::RankedTensorType>(type))) && ([](::mlir::Type elementType) { return !((::llvm::isa<::mlir::TokenType>(elementType))); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be ranked tensor of any non-token type values, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(32)))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MiniTritonOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonOps2(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(64)))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 64-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonOps2(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MiniTritonOps2(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
namespace mini_triton {


//===----------------------------------------------------------------------===//
// ::mini_triton::AddPtrOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

AddPtrOpGenericAdaptorBase::AddPtrOpGenericAdaptorBase(AddPtrOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}


} // namespace detail
AddPtrOpAdaptor::AddPtrOpAdaptor(AddPtrOp op) : AddPtrOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult AddPtrOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::LogicalResult AddPtrOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
      return ::mlir::success();
}

::mlir::Attribute AddPtrOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AddPtrOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine();
}

std::optional<mlir::Attribute> AddPtrOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
  return std::nullopt;
}

void AddPtrOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
}

void AddPtrOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
}

::llvm::LogicalResult AddPtrOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    return ::mlir::success();
}

void AddPtrOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value ptr, ::mlir::Value offset) {
  odsState.addOperands(ptr);
  odsState.addOperands(offset);
  odsState.addTypes(result);
}

AddPtrOp AddPtrOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value ptr, ::mlir::Value offset) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(ptr)>(ptr), std::forward<decltype(offset)>(offset));
  auto __res__ = ::llvm::dyn_cast<AddPtrOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

AddPtrOp AddPtrOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value ptr, ::mlir::Value offset) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(ptr)>(ptr), std::forward<decltype(offset)>(offset));
}

void AddPtrOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value offset) {
  odsState.addOperands(ptr);
  odsState.addOperands(offset);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

AddPtrOp AddPtrOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value offset) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(ptr)>(ptr), std::forward<decltype(offset)>(offset));
  auto __res__ = ::llvm::dyn_cast<AddPtrOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

AddPtrOp AddPtrOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value offset) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(ptr)>(ptr), std::forward<decltype(offset)>(offset));
}

void AddPtrOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

AddPtrOp AddPtrOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = ::llvm::dyn_cast<AddPtrOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

AddPtrOp AddPtrOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void AddPtrOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

AddPtrOp AddPtrOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = ::llvm::dyn_cast<AddPtrOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

AddPtrOp AddPtrOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult AddPtrOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
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

::llvm::LogicalResult AddPtrOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::llvm::LogicalResult AddPtrOp::setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
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

void AddPtrOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::AddPtrOp)

namespace mini_triton {


//===----------------------------------------------------------------------===//
// ::mini_triton::GetProgramIdOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

GetProgramIdOpGenericAdaptorBase::GetProgramIdOpGenericAdaptorBase(GetProgramIdOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

uint32_t GetProgramIdOpGenericAdaptorBase::getAxis() {
  auto attr = getAxisAttr();
  return attr.getValue().getZExtValue();
}


} // namespace detail
GetProgramIdOpAdaptor::GetProgramIdOpAdaptor(GetProgramIdOp op) : GetProgramIdOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult GetProgramIdOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_axis = getProperties().axis; (void)tblgen_axis;
  if (!tblgen_axis) return emitError(loc, "'mini.get_program_id' op requires attribute 'axis'");

  if (tblgen_axis && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_axis))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_axis).getType().isSignlessInteger(32)))))
    return emitError(loc, "'mini.get_program_id' op attribute 'axis' failed to satisfy constraint: 32-bit signless integer attribute");
  return ::mlir::success();
}

::llvm::LogicalResult GetProgramIdOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.axis;
       auto attr = dict.get("axis");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `axis` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute GetProgramIdOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.axis;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("axis",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code GetProgramIdOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine(
    llvm::hash_value(prop.axis.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> GetProgramIdOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "axis")
      return prop.axis;
  return std::nullopt;
}

void GetProgramIdOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "axis") {
       prop.axis = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.axis)>>(value);
       return;
    }
}

void GetProgramIdOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.axis) attrs.append("axis", prop.axis);
}

::llvm::LogicalResult GetProgramIdOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getAxisAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps1(attr, "axis", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult GetProgramIdOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.axis)))
    return ::mlir::failure();
  return ::mlir::success();
}

void GetProgramIdOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.axis);
}

uint32_t GetProgramIdOp::getAxis() {
  auto attr = getAxisAttr();
  return attr.getValue().getZExtValue();
}

void GetProgramIdOp::setAxis(uint32_t attrValue) {
  getProperties().axis = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(32), attrValue);
}

void GetProgramIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::IntegerAttr axis) {
  odsState.getOrAddProperties<Properties>().axis = axis;
  odsState.addTypes(result);
}

GetProgramIdOp GetProgramIdOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::IntegerAttr axis) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(axis)>(axis));
  auto __res__ = ::llvm::dyn_cast<GetProgramIdOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

GetProgramIdOp GetProgramIdOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::IntegerAttr axis) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(axis)>(axis));
}

void GetProgramIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr axis) {
  odsState.getOrAddProperties<Properties>().axis = axis;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

GetProgramIdOp GetProgramIdOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr axis) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(axis)>(axis));
  auto __res__ = ::llvm::dyn_cast<GetProgramIdOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

GetProgramIdOp GetProgramIdOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr axis) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(axis)>(axis));
}

void GetProgramIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, uint32_t axis) {
  odsState.getOrAddProperties<Properties>().axis = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), axis);
  odsState.addTypes(result);
}

GetProgramIdOp GetProgramIdOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, uint32_t axis) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(axis)>(axis));
  auto __res__ = ::llvm::dyn_cast<GetProgramIdOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

GetProgramIdOp GetProgramIdOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, uint32_t axis) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(axis)>(axis));
}

void GetProgramIdOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, uint32_t axis) {
  odsState.getOrAddProperties<Properties>().axis = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(32), axis);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

GetProgramIdOp GetProgramIdOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, uint32_t axis) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(axis)>(axis));
  auto __res__ = ::llvm::dyn_cast<GetProgramIdOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

GetProgramIdOp GetProgramIdOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, uint32_t axis) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(axis)>(axis));
}

void GetProgramIdOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    (void)odsState.getOrAddProperties<GetProgramIdOp::Properties>();
    ::mlir::PropertyRef properties = odsState.getRawProperties();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
}

GetProgramIdOp GetProgramIdOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = ::llvm::dyn_cast<GetProgramIdOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

GetProgramIdOp GetProgramIdOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void GetProgramIdOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

GetProgramIdOp GetProgramIdOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = ::llvm::dyn_cast<GetProgramIdOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

GetProgramIdOp GetProgramIdOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult GetProgramIdOp::verifyInvariantsImpl() {
  auto tblgen_axis = getProperties().axis; (void)tblgen_axis;
  if (!tblgen_axis) return emitOpError("requires attribute 'axis'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps1(*this, tblgen_axis, "axis")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult GetProgramIdOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::llvm::LogicalResult GetProgramIdOp::setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
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

    auto &propStorage = prop.axis;
    auto axisAttrName = ::mlir::StringAttr::get(ctx, "axis");
    auto attr = dict.get(axisAttrName);
    usedKeys.insert(axisAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for axis in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `axis` in property conversion: " << attr;
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

void GetProgramIdOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::GetProgramIdOp)
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::detail::GetProgramIdOpGenericAdaptorBase::Properties)

namespace mini_triton {


//===----------------------------------------------------------------------===//
// ::mini_triton::LoadOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

LoadOpGenericAdaptorBase::LoadOpGenericAdaptorBase(LoadOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}


} // namespace detail
LoadOpAdaptor::LoadOpAdaptor(LoadOp op) : LoadOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult LoadOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::LogicalResult LoadOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
      return ::mlir::success();
}

::mlir::Attribute LoadOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code LoadOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine();
}

std::optional<mlir::Attribute> LoadOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
  return std::nullopt;
}

void LoadOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
}

void LoadOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
}

::llvm::LogicalResult LoadOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    return ::mlir::success();
}

void LoadOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value ptr, ::mlir::Value mask, ::mlir::Value other) {
  odsState.addOperands(ptr);
  odsState.addOperands(mask);
  odsState.addOperands(other);
  odsState.addTypes(result);
}

LoadOp LoadOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value ptr, ::mlir::Value mask, ::mlir::Value other) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(ptr)>(ptr), std::forward<decltype(mask)>(mask), std::forward<decltype(other)>(other));
  auto __res__ = ::llvm::dyn_cast<LoadOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

LoadOp LoadOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value ptr, ::mlir::Value mask, ::mlir::Value other) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(ptr)>(ptr), std::forward<decltype(mask)>(mask), std::forward<decltype(other)>(other));
}

void LoadOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value mask, ::mlir::Value other) {
  odsState.addOperands(ptr);
  odsState.addOperands(mask);
  odsState.addOperands(other);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

LoadOp LoadOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value mask, ::mlir::Value other) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(ptr)>(ptr), std::forward<decltype(mask)>(mask), std::forward<decltype(other)>(other));
  auto __res__ = ::llvm::dyn_cast<LoadOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

LoadOp LoadOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value mask, ::mlir::Value other) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(ptr)>(ptr), std::forward<decltype(mask)>(mask), std::forward<decltype(other)>(other));
}

void LoadOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LoadOp LoadOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = ::llvm::dyn_cast<LoadOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

LoadOp LoadOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void LoadOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LoadOp LoadOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = ::llvm::dyn_cast<LoadOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

LoadOp LoadOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult LoadOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
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

::llvm::LogicalResult LoadOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::llvm::LogicalResult LoadOp::setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
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

void LoadOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  effects.emplace_back(::mlir::MemoryEffects::Read::get(), 0, false, ::mlir::SideEffects::DefaultResource::get());
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::LoadOp)

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
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps2(attr, "end", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getStartAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps2(attr, "start", emitError)))
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

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps2(*this, tblgen_start, "start")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonOps2(*this, tblgen_end, "end")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps3(*this, v.getType(), "result", index++)))
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

void MakeRangeOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
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
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps3(*this, v.getType(), "result", index++)))
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

void SplatOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::SplatOp)

namespace mini_triton {


//===----------------------------------------------------------------------===//
// ::mini_triton::StoreOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

StoreOpGenericAdaptorBase::StoreOpGenericAdaptorBase(StoreOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}


} // namespace detail
StoreOpAdaptor::StoreOpAdaptor(StoreOp op) : StoreOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult StoreOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::LogicalResult StoreOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
      return ::mlir::success();
}

::mlir::Attribute StoreOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code StoreOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine();
}

std::optional<mlir::Attribute> StoreOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
  return std::nullopt;
}

void StoreOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
}

void StoreOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
}

::llvm::LogicalResult StoreOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    return ::mlir::success();
}

void StoreOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value ptr, ::mlir::Value value, ::mlir::Value mask) {
  odsState.addOperands(ptr);
  odsState.addOperands(value);
  odsState.addOperands(mask);
}

StoreOp StoreOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value ptr, ::mlir::Value value, ::mlir::Value mask) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(ptr)>(ptr), std::forward<decltype(value)>(value), std::forward<decltype(mask)>(mask));
  auto __res__ = ::llvm::dyn_cast<StoreOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

StoreOp StoreOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value ptr, ::mlir::Value value, ::mlir::Value mask) {
  return create(builder, builder.getLoc(), std::forward<decltype(ptr)>(ptr), std::forward<decltype(value)>(value), std::forward<decltype(mask)>(mask));
}

void StoreOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value value, ::mlir::Value mask) {
  odsState.addOperands(ptr);
  odsState.addOperands(value);
  odsState.addOperands(mask);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

StoreOp StoreOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value value, ::mlir::Value mask) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(ptr)>(ptr), std::forward<decltype(value)>(value), std::forward<decltype(mask)>(mask));
  auto __res__ = ::llvm::dyn_cast<StoreOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

StoreOp StoreOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value ptr, ::mlir::Value value, ::mlir::Value mask) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(ptr)>(ptr), std::forward<decltype(value)>(value), std::forward<decltype(mask)>(mask));
}

void StoreOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

StoreOp StoreOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = ::llvm::dyn_cast<StoreOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

StoreOp StoreOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void StoreOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

StoreOp StoreOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = ::llvm::dyn_cast<StoreOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

StoreOp StoreOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult StoreOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup2 = getODSOperands(2);

    for (auto v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult StoreOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::llvm::LogicalResult StoreOp::setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
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

void StoreOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
  effects.emplace_back(::mlir::MemoryEffects::Write::get(), 0, false, ::mlir::SideEffects::DefaultResource::get());
}


} // namespace mini_triton
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::StoreOp)


#endif // GET_OP_CLASSES

