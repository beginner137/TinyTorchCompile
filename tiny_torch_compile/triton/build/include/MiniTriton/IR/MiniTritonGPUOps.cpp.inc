/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonGPU.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mini_triton::gpu::MakeRangeOp,
::mini_triton::gpu::SplatOp
#endif // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//


static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MiniTritonGPU1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::RankedTensorType>(type))) && ([](::mlir::Type elementType) { return !((::llvm::isa<::mlir::TokenType>(elementType))); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be ranked tensor of any non-token type values, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MiniTritonGPU2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((type.isSignlessInteger(32)))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be 32-bit signless integer, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonGPU1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::IntegerAttr>(attr))) && ((::llvm::cast<::mlir::IntegerAttr>(attr).getType().isSignlessInteger(64)))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 64-bit signless integer attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MiniTritonGPU1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
namespace mini_triton::gpu {


//===----------------------------------------------------------------------===//
// ::mini_triton::gpu::MakeRangeOp definitions
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

uint64_t MakeRangeOpGenericAdaptorBase::getNumWarps() {
  auto attr = getNumWarpsAttr();
  return attr.getValue().getZExtValue();
}

uint64_t MakeRangeOpGenericAdaptorBase::getElementsPerLane() {
  auto attr = getElementsPerLaneAttr();
  return attr.getValue().getZExtValue();
}


} // namespace detail
MakeRangeOpAdaptor::MakeRangeOpAdaptor(MakeRangeOp op) : MakeRangeOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult MakeRangeOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_elements_per_lane = getProperties().elements_per_lane; (void)tblgen_elements_per_lane;
  if (!tblgen_elements_per_lane) return emitError(loc, "'mini_gpu.make_range' op requires attribute 'elements_per_lane'");
  auto tblgen_end = getProperties().end; (void)tblgen_end;
  if (!tblgen_end) return emitError(loc, "'mini_gpu.make_range' op requires attribute 'end'");
  auto tblgen_num_warps = getProperties().num_warps; (void)tblgen_num_warps;
  if (!tblgen_num_warps) return emitError(loc, "'mini_gpu.make_range' op requires attribute 'num_warps'");
  auto tblgen_start = getProperties().start; (void)tblgen_start;
  if (!tblgen_start) return emitError(loc, "'mini_gpu.make_range' op requires attribute 'start'");

  if (tblgen_start && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_start))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_start).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini_gpu.make_range' op attribute 'start' failed to satisfy constraint: 64-bit signless integer attribute");

  if (tblgen_end && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_end))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_end).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini_gpu.make_range' op attribute 'end' failed to satisfy constraint: 64-bit signless integer attribute");

  if (tblgen_num_warps && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_num_warps))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_num_warps).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini_gpu.make_range' op attribute 'num_warps' failed to satisfy constraint: 64-bit signless integer attribute");

  if (tblgen_elements_per_lane && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_elements_per_lane))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_elements_per_lane).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini_gpu.make_range' op attribute 'elements_per_lane' failed to satisfy constraint: 64-bit signless integer attribute");
  return ::mlir::success();
}

::llvm::LogicalResult MakeRangeOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.elements_per_lane;
       auto attr = dict.get("elements_per_lane");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `elements_per_lane` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
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
    auto &propStorage = prop.num_warps;
       auto attr = dict.get("num_warps");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `num_warps` in property conversion: " << attr;
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
      const auto &propStorage = prop.elements_per_lane;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("elements_per_lane",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.end;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("end",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.num_warps;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("num_warps",
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
    llvm::hash_value(prop.elements_per_lane.getAsOpaquePointer()), 
    llvm::hash_value(prop.end.getAsOpaquePointer()), 
    llvm::hash_value(prop.num_warps.getAsOpaquePointer()), 
    llvm::hash_value(prop.start.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> MakeRangeOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "elements_per_lane")
      return prop.elements_per_lane;

    if (name == "end")
      return prop.end;

    if (name == "num_warps")
      return prop.num_warps;

    if (name == "start")
      return prop.start;
  return std::nullopt;
}

void MakeRangeOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "elements_per_lane") {
       prop.elements_per_lane = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.elements_per_lane)>>(value);
       return;
    }

    if (name == "end") {
       prop.end = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.end)>>(value);
       return;
    }

    if (name == "num_warps") {
       prop.num_warps = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.num_warps)>>(value);
       return;
    }

    if (name == "start") {
       prop.start = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.start)>>(value);
       return;
    }
}

void MakeRangeOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.elements_per_lane) attrs.append("elements_per_lane", prop.elements_per_lane);

    if (prop.end) attrs.append("end", prop.end);

    if (prop.num_warps) attrs.append("num_warps", prop.num_warps);

    if (prop.start) attrs.append("start", prop.start);
}

::llvm::LogicalResult MakeRangeOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getElementsPerLaneAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, "elements_per_lane", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getEndAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, "end", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getNumWarpsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, "num_warps", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getStartAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, "start", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult MakeRangeOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.elements_per_lane)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.end)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.num_warps)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.start)))
    return ::mlir::failure();
  return ::mlir::success();
}

void MakeRangeOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.elements_per_lane);
  writer.writeAttribute(prop.end);
  writer.writeAttribute(prop.num_warps);
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

uint64_t MakeRangeOp::getNumWarps() {
  auto attr = getNumWarpsAttr();
  return attr.getValue().getZExtValue();
}

uint64_t MakeRangeOp::getElementsPerLane() {
  auto attr = getElementsPerLaneAttr();
  return attr.getValue().getZExtValue();
}

void MakeRangeOp::setStart(uint64_t attrValue) {
  getProperties().start = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void MakeRangeOp::setEnd(uint64_t attrValue) {
  getProperties().end = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void MakeRangeOp::setNumWarps(uint64_t attrValue) {
  getProperties().num_warps = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void MakeRangeOp::setElementsPerLane(uint64_t attrValue) {
  getProperties().elements_per_lane = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  odsState.getOrAddProperties<Properties>().start = start;
  odsState.getOrAddProperties<Properties>().end = end;
  odsState.getOrAddProperties<Properties>().num_warps = num_warps;
  odsState.getOrAddProperties<Properties>().elements_per_lane = elements_per_lane;
  odsState.addTypes(result);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  odsState.getOrAddProperties<Properties>().start = start;
  odsState.getOrAddProperties<Properties>().end = end;
  odsState.getOrAddProperties<Properties>().num_warps = num_warps;
  odsState.getOrAddProperties<Properties>().elements_per_lane = elements_per_lane;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane) {
  odsState.getOrAddProperties<Properties>().start = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), start);
  odsState.getOrAddProperties<Properties>().end = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), end);
  odsState.getOrAddProperties<Properties>().num_warps = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), num_warps);
  odsState.getOrAddProperties<Properties>().elements_per_lane = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), elements_per_lane);
  odsState.addTypes(result);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void MakeRangeOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane) {
  odsState.getOrAddProperties<Properties>().start = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), start);
  odsState.getOrAddProperties<Properties>().end = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), end);
  odsState.getOrAddProperties<Properties>().num_warps = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), num_warps);
  odsState.getOrAddProperties<Properties>().elements_per_lane = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), elements_per_lane);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

MakeRangeOp MakeRangeOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<MakeRangeOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

MakeRangeOp MakeRangeOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(start)>(start), std::forward<decltype(end)>(end), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
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
  auto tblgen_elements_per_lane = getProperties().elements_per_lane; (void)tblgen_elements_per_lane;
  if (!tblgen_elements_per_lane) return emitOpError("requires attribute 'elements_per_lane'");
  auto tblgen_end = getProperties().end; (void)tblgen_end;
  if (!tblgen_end) return emitOpError("requires attribute 'end'");
  auto tblgen_num_warps = getProperties().num_warps; (void)tblgen_num_warps;
  if (!tblgen_num_warps) return emitOpError("requires attribute 'num_warps'");
  auto tblgen_start = getProperties().start; (void)tblgen_start;
  if (!tblgen_start) return emitOpError("requires attribute 'start'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(*this, tblgen_start, "start")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(*this, tblgen_end, "end")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(*this, tblgen_num_warps, "num_warps")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(*this, tblgen_elements_per_lane, "elements_per_lane")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonGPU1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult MakeRangeOp::verifyInvariants() {
  return verifyInvariantsImpl();
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
  {

    auto &propStorage = prop.num_warps;
    auto num_warpsAttrName = ::mlir::StringAttr::get(ctx, "num_warps");
    auto attr = dict.get(num_warpsAttrName);
    usedKeys.insert(num_warpsAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for num_warps in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `num_warps` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  {

    auto &propStorage = prop.elements_per_lane;
    auto elements_per_laneAttrName = ::mlir::StringAttr::get(ctx, "elements_per_lane");
    auto attr = dict.get(elements_per_laneAttrName);
    usedKeys.insert(elements_per_laneAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for elements_per_lane in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `elements_per_lane` in property conversion: " << attr;
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


} // namespace mini_triton::gpu
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::gpu::MakeRangeOp)
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::gpu::detail::MakeRangeOpGenericAdaptorBase::Properties)

namespace mini_triton::gpu {


//===----------------------------------------------------------------------===//
// ::mini_triton::gpu::SplatOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

SplatOpGenericAdaptorBase::SplatOpGenericAdaptorBase(SplatOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

uint64_t SplatOpGenericAdaptorBase::getNumWarps() {
  auto attr = getNumWarpsAttr();
  return attr.getValue().getZExtValue();
}

uint64_t SplatOpGenericAdaptorBase::getElementsPerLane() {
  auto attr = getElementsPerLaneAttr();
  return attr.getValue().getZExtValue();
}


} // namespace detail
SplatOpAdaptor::SplatOpAdaptor(SplatOp op) : SplatOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult SplatOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_elements_per_lane = getProperties().elements_per_lane; (void)tblgen_elements_per_lane;
  if (!tblgen_elements_per_lane) return emitError(loc, "'mini_gpu.splat' op requires attribute 'elements_per_lane'");
  auto tblgen_num_warps = getProperties().num_warps; (void)tblgen_num_warps;
  if (!tblgen_num_warps) return emitError(loc, "'mini_gpu.splat' op requires attribute 'num_warps'");

  if (tblgen_num_warps && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_num_warps))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_num_warps).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini_gpu.splat' op attribute 'num_warps' failed to satisfy constraint: 64-bit signless integer attribute");

  if (tblgen_elements_per_lane && !(((::llvm::isa<::mlir::IntegerAttr>(tblgen_elements_per_lane))) && ((::llvm::cast<::mlir::IntegerAttr>(tblgen_elements_per_lane).getType().isSignlessInteger(64)))))
    return emitError(loc, "'mini_gpu.splat' op attribute 'elements_per_lane' failed to satisfy constraint: 64-bit signless integer attribute");
  return ::mlir::success();
}

::llvm::LogicalResult SplatOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.elements_per_lane;
       auto attr = dict.get("elements_per_lane");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `elements_per_lane` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }

  {
    auto &propStorage = prop.num_warps;
       auto attr = dict.get("num_warps");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `num_warps` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute SplatOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.elements_per_lane;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("elements_per_lane",
                                       propStorage));
    }

    {
      const auto &propStorage = prop.num_warps;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("num_warps",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code SplatOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine(
    llvm::hash_value(prop.elements_per_lane.getAsOpaquePointer()), 
    llvm::hash_value(prop.num_warps.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> SplatOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "elements_per_lane")
      return prop.elements_per_lane;

    if (name == "num_warps")
      return prop.num_warps;
  return std::nullopt;
}

void SplatOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "elements_per_lane") {
       prop.elements_per_lane = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.elements_per_lane)>>(value);
       return;
    }

    if (name == "num_warps") {
       prop.num_warps = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.num_warps)>>(value);
       return;
    }
}

void SplatOp::populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs) {
    if (prop.elements_per_lane) attrs.append("elements_per_lane", prop.elements_per_lane);

    if (prop.num_warps) attrs.append("num_warps", prop.num_warps);
}

::llvm::LogicalResult SplatOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getElementsPerLaneAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, "elements_per_lane", emitError)))
        return ::mlir::failure();
    }

    {
      ::mlir::Attribute attr = attrs.get(getNumWarpsAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(attr, "num_warps", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult SplatOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.elements_per_lane)))
    return ::mlir::failure();

  if (::mlir::failed(reader.readAttribute(prop.num_warps)))
    return ::mlir::failure();
  return ::mlir::success();
}

void SplatOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.elements_per_lane);
  writer.writeAttribute(prop.num_warps);
}

uint64_t SplatOp::getNumWarps() {
  auto attr = getNumWarpsAttr();
  return attr.getValue().getZExtValue();
}

uint64_t SplatOp::getElementsPerLane() {
  auto attr = getElementsPerLaneAttr();
  return attr.getValue().getZExtValue();
}

void SplatOp::setNumWarps(uint64_t attrValue) {
  getProperties().num_warps = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void SplatOp::setElementsPerLane(uint64_t attrValue) {
  getProperties().elements_per_lane = ::mlir::Builder((*this)->getContext()).getIntegerAttr(::mlir::Builder((*this)->getContext()).getIntegerType(64), attrValue);
}

void SplatOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().num_warps = num_warps;
  odsState.getOrAddProperties<Properties>().elements_per_lane = elements_per_lane;
  odsState.addTypes(result);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void SplatOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().num_warps = num_warps;
  odsState.getOrAddProperties<Properties>().elements_per_lane = elements_per_lane;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void SplatOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().num_warps = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), num_warps);
  odsState.getOrAddProperties<Properties>().elements_per_lane = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), elements_per_lane);
  odsState.addTypes(result);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void SplatOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().num_warps = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), num_warps);
  odsState.getOrAddProperties<Properties>().elements_per_lane = odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), elements_per_lane);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

SplatOp SplatOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
  auto __res__ = ::llvm::dyn_cast<SplatOp>(builder.create(__state__));
  assert(__res__ && "builder didn't return the right type");
  return __res__;
}

SplatOp SplatOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(num_warps)>(num_warps), std::forward<decltype(elements_per_lane)>(elements_per_lane));
}

void SplatOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);

  if (!attributes.empty()) {
    (void)odsState.getOrAddProperties<SplatOp::Properties>();
    ::mlir::PropertyRef properties = odsState.getRawProperties();
    std::optional<::mlir::RegisteredOperationName> info =
      odsState.name.getRegisteredInfo();
    if (failed(info->setOpPropertiesFromAttribute(odsState.name, properties,
        odsState.attributes.getDictionary(odsState.getContext()), nullptr)))
      ::llvm::report_fatal_error("Property conversion failed.");
  }
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
  auto tblgen_elements_per_lane = getProperties().elements_per_lane; (void)tblgen_elements_per_lane;
  if (!tblgen_elements_per_lane) return emitOpError("requires attribute 'elements_per_lane'");
  auto tblgen_num_warps = getProperties().num_warps; (void)tblgen_num_warps;
  if (!tblgen_num_warps) return emitOpError("requires attribute 'num_warps'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(*this, tblgen_num_warps, "num_warps")))
    return ::mlir::failure();

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MiniTritonGPU1(*this, tblgen_elements_per_lane, "elements_per_lane")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonGPU2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MiniTritonGPU1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult SplatOp::verifyInvariants() {
  return verifyInvariantsImpl();
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
  {

    auto &propStorage = prop.num_warps;
    auto num_warpsAttrName = ::mlir::StringAttr::get(ctx, "num_warps");
    auto attr = dict.get(num_warpsAttrName);
    usedKeys.insert(num_warpsAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for num_warps in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `num_warps` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  {

    auto &propStorage = prop.elements_per_lane;
    auto elements_per_laneAttrName = ::mlir::StringAttr::get(ctx, "elements_per_lane");
    auto attr = dict.get(elements_per_laneAttrName);
    usedKeys.insert(elements_per_laneAttrName);
    if (attr || /*isRequired=*/true) {
      if (!attr) {
        emitError() << "expected key entry for elements_per_lane in DictionaryAttr to set "
                   "Properties.";
        return ::mlir::failure();
      }
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `elements_per_lane` in property conversion: " << attr;
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


} // namespace mini_triton::gpu
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::gpu::SplatOp)
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mini_triton::gpu::detail::SplatOpGenericAdaptorBase::Properties)


#endif // GET_OP_CLASSES

