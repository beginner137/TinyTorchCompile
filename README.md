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
    inductor/           # Package for upcoming graph lowering and code generation
tests/
    test_ir.py          # Manual and proxy graph construction
    test_tracing.py     # Tracer and cache tests; shared forward example
```

The shared IR stays at the package level so `inductor/` can consume graphs
produced by `dynamo/`. The Inductor package is currently a scaffold.

## Running tests

Run these commands from the repository root:

```bash
python -m unittest discover -v -b                   # All tests
python -m tests.test_ir                            # IR tests
python -m tests.test_tracing                       # Tracer and cache tests
python -m tests.test_tracing -k mini_dynamo         # Tracer only
python -m tests.test_tracing -k graph_cache         # Cache only
```

The `-b` option hides printed output for passing tests. Omit it to see tracing
details. Both test modules also accept `-b`.

## Importing the implementation

```python
from tiny_torch_compile.dynamo import MiniDynamo, GraphCache
```
