from .ir import (
    FusedKernel, Load, Const, Temp, Add, Mul
)


def emit_expr(expr, temp_names):
    if isinstance(expr, Load):
        return f"{expr.buffer}[{expr.index}]"

    if isinstance(expr, Const):
        return repr(expr.value)

    if isinstance(expr, Temp):
        return temp_names[expr.name]

    if isinstance(expr, Mul):
        left = emit_expr(expr.left, temp_names)
        right = emit_expr(expr.right, temp_names)
        return f"({left} * {right})"

    if isinstance(expr, Add):
        left = emit_expr(expr.left, temp_names)
        right = emit_expr(expr.right, temp_names)
        return f"({left} + {right})"

    raise NotImplementedError(type(expr))


def generate_python(kernel: FusedKernel) -> str:
    if not kernel.statements:
        raise ValueError("Empty fused kernel")
    print(kernel.statements, len(kernel.statements))
    # 1. Map IR temporary names to valid Python identifiers.
    temp_names = {
        stmt.name: f"t{i}"
        for i, stmt in enumerate(kernel.statements)
    }

    # 2. Discover external input buffers from Load expressions.
    inputs = []

    def collect_inputs(expr):
        if isinstance(expr, Load):
            if expr.index != "i":
                raise NotImplementedError("Only 1D indexing supported")
            if expr.buffer not in inputs:
                inputs.append(expr.buffer)

        elif isinstance(expr, (Add, Mul)):
            collect_inputs(expr.left)
            collect_inputs(expr.right)

        elif isinstance(expr, (Const, Temp)):
            pass

        else:
            raise NotImplementedError(type(expr))

    for stmt in kernel.statements:
        collect_inputs(stmt.expression)

    # 3. Emit function header and output allocation.
    params = ", ".join(inputs)

    lines = [
        f"def fused_kernel({params}):",
        f"    out = [0] * {kernel.extent}",
        f"    for i in range({kernel.extent}):",
    ]

    # 4. Emit each fused computation as a local assignment.
    for stmt in kernel.statements:
        name = temp_names[stmt.name]
        expression = emit_expr(stmt.expression, temp_names)
        lines.append(f"        {name} = {expression}")

    # 5. Store final result and return output.
    output_name = temp_names[kernel.output]
    lines.append(f"        out[i] = {output_name}")
    lines.append("    return out")

    return "\n".join(lines)


def generate_triton(kernel: FusedKernel) -> tuple[str, list[str]]:
    if not kernel.statements:
        raise ValueError("Empty fused kernel")

    temp_names = {
        stmt.name: f"t{i}"
        for i, stmt in enumerate(kernel.statements)
    }

    inputs = []
    produced = set()

    # Convert an expression into Triton source.
    def emit_expr(expr):
        if isinstance(expr, Load):
            if expr.index != "i":
                raise NotImplementedError("Only 1D indexing supported")

            if expr.buffer in temp_names:
                raise ValueError(
                    f"Unfused intermediate load: {expr.buffer}"
                )

            if expr.buffer not in inputs:
                inputs.append(expr.buffer)

            ptr = f"P{inputs.index(expr.buffer)}"
            return (
                f"tl.load({ptr} + offsets, "
                f"mask=mask, other=0)"
            )

        if isinstance(expr, Const):
            return repr(expr.value)

        if isinstance(expr, Temp):
            if expr.name not in produced:
                raise ValueError(f"Undefined temporary: {expr.name}")
            return temp_names[expr.name]

        if isinstance(expr, (Mul, Add)):
            left = emit_expr(expr.left)
            right = emit_expr(expr.right)
            op = "*" if isinstance(expr, Mul) else "+"
            return f"({left} {op} {right})"

        raise NotImplementedError(type(expr))

    # Generate the local computations first.
    statements = []

    for stmt in kernel.statements:
        expr = emit_expr(stmt.expression)
        statements.append(f"    {temp_names[stmt.name]} = {expr}")
        produced.add(stmt.name)

    if kernel.output not in produced:
        raise ValueError("Kernel output is not defined")

    # P0, P1, ... are external tensor pointers.
    params = [f"P{i}" for i in range(len(inputs))]
    params += ["OUT", "N", "BLOCK: tl.constexpr"]

    lines = [
        "import triton",
        "import triton.language as tl",
        "",
        "@triton.jit",
        f"def fused_kernel({', '.join(params)}):",
        "    offsets = tl.program_id(0) * BLOCK + tl.arange(0, BLOCK)",
        "    mask = offsets < N",
        "",
        *statements,
        "",
        f"    tl.store(OUT + offsets, {temp_names[kernel.output]}, mask=mask)",
    ]

    return "\n".join(lines), inputs
