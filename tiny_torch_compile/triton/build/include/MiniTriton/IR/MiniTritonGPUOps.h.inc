/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MiniTritonGPU.td                                                     *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mini_triton::gpu {

/// Create a range with a GPU layout
class MakeRangeOp;

} // namespace mini_triton::gpu
namespace mini_triton::gpu {

class SplatOp;

} // namespace mini_triton::gpu
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mini_triton::gpu {


//===----------------------------------------------------------------------===//
// ::mini_triton::gpu::MakeRangeOp declarations
//===----------------------------------------------------------------------===//

namespace detail {

class MakeRangeOpGenericAdaptorBase {
public:
  struct Properties {
    using elements_per_laneTy = ::mlir::IntegerAttr;
    elements_per_laneTy elements_per_lane;

    auto getElementsPerLane() const {
      auto &propStorage = this->elements_per_lane;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setElementsPerLane(const ::mlir::IntegerAttr &propValue) {
      this->elements_per_lane = propValue;
    }
    using endTy = ::mlir::IntegerAttr;
    endTy end;

    auto getEnd() const {
      auto &propStorage = this->end;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setEnd(const ::mlir::IntegerAttr &propValue) {
      this->end = propValue;
    }
    using num_warpsTy = ::mlir::IntegerAttr;
    num_warpsTy num_warps;

    auto getNumWarps() const {
      auto &propStorage = this->num_warps;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setNumWarps(const ::mlir::IntegerAttr &propValue) {
      this->num_warps = propValue;
    }
    using startTy = ::mlir::IntegerAttr;
    startTy start;

    auto getStart() const {
      auto &propStorage = this->start;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setStart(const ::mlir::IntegerAttr &propValue) {
      this->start = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.elements_per_lane == this->elements_per_lane &&
        rhs.end == this->end &&
        rhs.num_warps == this->num_warps &&
        rhs.start == this->start &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  MakeRangeOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("mini_gpu.make_range", odsAttrs.getContext());
  }

  MakeRangeOpGenericAdaptorBase(MakeRangeOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getStartAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().start);
    return attr;
  }

  uint64_t getStart();
  ::mlir::IntegerAttr getEndAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().end);
    return attr;
  }

  uint64_t getEnd();
  ::mlir::IntegerAttr getNumWarpsAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().num_warps);
    return attr;
  }

  uint64_t getNumWarps();
  ::mlir::IntegerAttr getElementsPerLaneAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().elements_per_lane);
    return attr;
  }

  uint64_t getElementsPerLane();
};

} // namespace detail
template <typename RangeT>
class MakeRangeOpGenericAdaptor : public detail::MakeRangeOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MakeRangeOpGenericAdaptorBase;
public:
  MakeRangeOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MakeRangeOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::PropertyRef properties, ::mlir::RegionRange regions = {}) : MakeRangeOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  MakeRangeOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : MakeRangeOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  MakeRangeOpGenericAdaptor(RangeT values, const MakeRangeOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = MakeRangeOp, typename = std::enable_if_t<std::is_same_v<LateInst, MakeRangeOp>>>
  MakeRangeOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MakeRangeOpAdaptor : public MakeRangeOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MakeRangeOpGenericAdaptor::MakeRangeOpGenericAdaptor;
  MakeRangeOpAdaptor(MakeRangeOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class MakeRangeOp : public ::mlir::Op<MakeRangeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::RankedTensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MakeRangeOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MakeRangeOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("elements_per_lane"), ::llvm::StringRef("end"), ::llvm::StringRef("num_warps"), ::llvm::StringRef("start")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getElementsPerLaneAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getElementsPerLaneAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getEndAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getEndAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getNumWarpsAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getNumWarpsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getStartAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getStartAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("mini_gpu.make_range");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::RankedTensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::RankedTensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getStartAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().start);
  }

  uint64_t getStart();
  ::mlir::IntegerAttr getEndAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().end);
  }

  uint64_t getEnd();
  ::mlir::IntegerAttr getNumWarpsAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().num_warps);
  }

  uint64_t getNumWarps();
  ::mlir::IntegerAttr getElementsPerLaneAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().elements_per_lane);
  }

  uint64_t getElementsPerLane();
  void setStartAttr(::mlir::IntegerAttr attr) {
    getProperties().start = attr;
  }

  void setStart(uint64_t attrValue);
  void setEndAttr(::mlir::IntegerAttr attr) {
    getProperties().end = attr;
  }

  void setEnd(uint64_t attrValue);
  void setNumWarpsAttr(::mlir::IntegerAttr attr) {
    getProperties().num_warps = attr;
  }

  void setNumWarps(uint64_t attrValue);
  void setElementsPerLaneAttr(::mlir::IntegerAttr attr) {
    getProperties().elements_per_lane = attr;
  }

  void setElementsPerLane(uint64_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static MakeRangeOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static MakeRangeOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static MakeRangeOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static MakeRangeOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr start, ::mlir::IntegerAttr end, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane);
  static MakeRangeOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane);
  static MakeRangeOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane);
  static MakeRangeOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane);
  static MakeRangeOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, uint64_t start, uint64_t end, uint64_t num_warps, uint64_t elements_per_lane);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static MakeRangeOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static MakeRangeOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static MakeRangeOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static MakeRangeOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};

} // namespace mini_triton::gpu
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::gpu::MakeRangeOp)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::gpu::detail::MakeRangeOpGenericAdaptorBase::Properties)

namespace mini_triton::gpu {


//===----------------------------------------------------------------------===//
// ::mini_triton::gpu::SplatOp declarations
//===----------------------------------------------------------------------===//

namespace detail {

class SplatOpGenericAdaptorBase {
public:
  struct Properties {
    using elements_per_laneTy = ::mlir::IntegerAttr;
    elements_per_laneTy elements_per_lane;

    auto getElementsPerLane() const {
      auto &propStorage = this->elements_per_lane;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setElementsPerLane(const ::mlir::IntegerAttr &propValue) {
      this->elements_per_lane = propValue;
    }
    using num_warpsTy = ::mlir::IntegerAttr;
    num_warpsTy num_warps;

    auto getNumWarps() const {
      auto &propStorage = this->num_warps;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setNumWarps(const ::mlir::IntegerAttr &propValue) {
      this->num_warps = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.elements_per_lane == this->elements_per_lane &&
        rhs.num_warps == this->num_warps &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  SplatOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("mini_gpu.splat", odsAttrs.getContext());
  }

  SplatOpGenericAdaptorBase(SplatOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getNumWarpsAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().num_warps);
    return attr;
  }

  uint64_t getNumWarps();
  ::mlir::IntegerAttr getElementsPerLaneAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().elements_per_lane);
    return attr;
  }

  uint64_t getElementsPerLane();
};

} // namespace detail
template <typename RangeT>
class SplatOpGenericAdaptor : public detail::SplatOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::SplatOpGenericAdaptorBase;
  static constexpr int odsIndex_input = 0;
public:
  SplatOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  SplatOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::PropertyRef properties, ::mlir::RegionRange regions = {}) : SplatOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  SplatOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : SplatOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  SplatOpGenericAdaptor(RangeT values, const SplatOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = SplatOp, typename = std::enable_if_t<std::is_same_v<LateInst, SplatOp>>>
  SplatOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class SplatOpAdaptor : public SplatOpGenericAdaptor<::mlir::ValueRange> {
public:
  using SplatOpGenericAdaptor::SplatOpGenericAdaptor;
  SplatOpAdaptor(SplatOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class SplatOp : public ::mlir::Op<SplatOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::RankedTensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SplatOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = SplatOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static constexpr int odsIndex_input = 0;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("elements_per_lane"), ::llvm::StringRef("num_warps")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getElementsPerLaneAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getElementsPerLaneAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getNumWarpsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getNumWarpsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("mini_gpu.splat");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::IntegerType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::IntegerType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::RankedTensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::RankedTensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getNumWarpsAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().num_warps);
  }

  uint64_t getNumWarps();
  ::mlir::IntegerAttr getElementsPerLaneAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().elements_per_lane);
  }

  uint64_t getElementsPerLane();
  void setNumWarpsAttr(::mlir::IntegerAttr attr) {
    getProperties().num_warps = attr;
  }

  void setNumWarps(uint64_t attrValue);
  void setElementsPerLaneAttr(::mlir::IntegerAttr attr) {
    getProperties().elements_per_lane = attr;
  }

  void setElementsPerLane(uint64_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static SplatOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static SplatOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static SplatOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static SplatOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr num_warps, ::mlir::IntegerAttr elements_per_lane);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane);
  static SplatOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane);
  static SplatOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane);
  static SplatOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane);
  static SplatOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t num_warps, uint64_t elements_per_lane);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static SplatOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static SplatOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static SplatOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static SplatOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::llvm::LogicalResult setPropertiesFromParsedAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};

} // namespace mini_triton::gpu
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::gpu::SplatOp)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mini_triton::gpu::detail::SplatOpGenericAdaptorBase::Properties)


#endif // GET_OP_CLASSES

