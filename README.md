# TinyTorchCompile

A small Python project exploring graph IR, tracing, guards, and graph caching.
Requires Python 3.11 for the bytecode instructions currently handled by the tracer.
No third-party dependencies are needed.

## Layout

```text
tiny_torch_compile/      # Implementation
    ir.py               # Shared graph, nodes, and operations
    proxy.py            # Symbolic tensor operations
    dynamo/
        guards.py       # Predicate-based guards
        mini_dynamo.py  # Bytecode tracer
        graph_cache.py  # Guarded graph cache
    decomp/             # Rewrite POW(x, 2) as MUL(x, x)
    inductor/           # Graph lowering and code generation
        lowering.py    # Lower graph nodes to pointwise operations
        scheduler.py   # Sort operations, check legality, and fuse
        codegen.py     # Generate Python and Triton source
    triton/             # Mini Triton compiler scaffold
        frontend/       # Python AST parsing
        compiler/       # Python compilation orchestration
        include/        # C++ IR definitions
        lib/
            Dialect/    # MiniTTIR and MiniTTGIR
            Transforms/ # Optimization passes
            Conversion/ # Lowering to LLVM
        tests/          # Mini Triton tests
tests/
    test_ir.py          # Manual and proxy graph construction
    test_inductor.py    # Lowering, scheduling, fusion, and code generation
    test_tracing.py     # Tracer and cache tests; shared forward example
```

The shared IR stays at the package level so `inductor/` can consume graphs
produced by `dynamo/`. MiniInductor supports 1D pointwise addition and
multiplication with scalar constants.

## Running tests

Run these commands from the repository root. Follow this order to inspect each
stage of the compiler pipeline. Each command selects exactly one test.

```bash
# 1. Build the graph manually, then with tensor proxies
python -m tests.test_ir GraphTests.test_manual_graph
python -m tests.test_ir GraphTests.test_proxy_graph

# 2. Trace Python bytecode: branching, ReLU, and power
python -m tests.test_tracing TracingTests.test_mini_dynamo
python -m tests.test_tracing TracingTests.test_mini_dynamo_relu
python -m tests.test_tracing TracingTests.test_mini_dynamo_pow

# 3. Reuse traced graphs through guards and caching
python -m tests.test_tracing TracingTests.test_graph_cache

# 4. Decompose power into multiplication; print before and after
python -m tests.test_tracing TracingTests.test_decomposition

# 5. Lower graph operations to indexed pointwise IR
python -m tests.test_inductor MiniInductorTests.test_lower_mul

# 6. Check fusion legality
python -m tests.test_inductor MiniInductorTests.test_can_fuse

# 7. Sort reversed operations and fuse; reject illegal fusion
python -m tests.test_inductor MiniInductorTests.test_scheduler
python -m tests.test_inductor MiniInductorTests.test_scheduler_rejects_illegal_fusion

# 8. Generate Python, execute it, and check the numerical result
python -m tests.test_inductor MiniInductorTests.test_codegen

# 9. Generate Triton source and check its inputs, loads, and store
python -m tests.test_inductor MiniInductorTests.test_codegen_triton
```

The Triton test checks generated source only; it does not execute a GPU kernel
or require Triton to be installed.

To run all tests or a whole module:

```bash
python -m unittest discover -v -b  # All tests
python -m tests.test_ir           # Graph construction
python -m tests.test_tracing      # Tracing, caching, and decomposition
python -m tests.test_inductor     # Lowering through code generation
```

The `-b` option hides printed output for passing tests. Omit it to see tracing
details. All test modules also accept `-b`.

## Importing the implementation

```python
from tiny_torch_compile.dynamo import MiniDynamo, GraphCache
```
