# MiniTriton TTIR tests

From the repository root:

```bash
cmake --build tiny_torch_compile/triton/build
ctest --test-dir tiny_torch_compile/triton/build --output-on-failure
```

`TTIROpsTest.cpp` loads `elementwise.mlir`, verifies the complete masked
`(x * y + 1)^2` kernel, and checks a print/parse round trip. It also tests valid
scalar memory operations, invalid operands and attributes, and memory effects.
Tests use explicit failures rather than C++ assertions, so they run in Release
builds too. They require neither a GPU nor the Python Triton package.

## TTIR contracts

- `!mini.ptr<T>` points to an integer or floating-point scalar `T`.
- `mini.get_program_id` returns an `i32` program index for axis 0, 1, or 2.
- `mini.make_range` produces a nonempty static 1D `i32` tensor for `[start, end)`.
  Its length must equal `end - start`, and every generated value must fit `i32`.
- `mini.splat` broadcasts a numeric or pointer scalar to a nonempty static 1D
  tensor with the same element type.
- `mini.addptr` adds signed `i32` or `i64` offsets measured in **elements**.
  Pointer and offset operands must both be scalars or tensors with equal shapes.
  The result preserves the pointer type. Broadcast scalar pointers with `splat`
  before adding tensor offsets.
- `mini.load(ptr, mask, other)` reads only active lanes and returns `other` for
  masked-off lanes. `mini.store(ptr, value, mask)` writes only active lanes.
  Masks have `i1` elements; pointer, mask, and value shapes must match. Loaded or
  stored elements must match the pointee type, and `other` must have exactly the
  load result type. Masks and load fallbacks are mandatory in this initial API.
  Scalar operands are supported as well as nonempty static 1D tensors.
- Tensor encodings are rejected at this TTIR stage. No GPU layout is assigned.

Constants, index multiplication/addition, comparisons, and floating-point
arithmetic use `arith.constant`, `arith.muli`, `arith.addi`, `arith.cmpi`,
`arith.mulf`, and `arith.addf`. There are no duplicate MiniTriton arithmetic ops.

Loads declare a read effect and stores declare a write effect; neither is marked
pure. The other TTIR operations are pure. These tests validate representation
and verifier behavior, not runtime memory safety or GPU execution. GPU lowering
for the newly added operations is intentionally outside this change.
