from .ir import Add, Assign, Const, FusedKernel, Load, Mul, Pointwise, Temp


def topological_sort_pointwise(pointwise_ops):
    by_name = {op.name: op for op in pointwise_ops}

    if len(by_name) != len(pointwise_ops):
        raise ValueError("Duplicate pointwise names")

    ordered = []
    state = {}  # 0: unvisited, 1: visiting, 2: finished

    def dependencies(expr):
        if isinstance(expr, Load):
            if expr.buffer in by_name:
                yield expr.buffer

        elif isinstance(expr, (Add, Mul)):
            yield from dependencies(expr.left)
            yield from dependencies(expr.right)

        elif not isinstance(expr, (Const, Temp)):
            raise NotImplementedError(type(expr))

    def visit(name):
        status = state.get(name, 0)

        if status == 1:
            raise ValueError("Dependency cycle detected")

        if status == 2:
            return

        state[name] = 1

        for dep_name in dependencies(by_name[name].expression):
            visit(dep_name)

        state[name] = 2
        ordered.append(by_name[name])

    for op in pointwise_ops:
        visit(op.name)

    return ordered


def replace_internal_loads(expr, produced_names: set[str]):
    """
    Replace reads of values produced inside the fused kernel
    with references to local temporaries.
    """

    if isinstance(expr, Load):
        if expr.buffer in produced_names:
            if expr.index != "i":
                raise NotImplementedError(
                    "Only identical 1D indexing is supported"
                )
            return Temp(expr.buffer)

        return expr

    if isinstance(expr, Const):
        return expr

    if isinstance(expr, Temp):
        return expr

    if isinstance(expr, (Add, Mul)):
        return type(expr)(
            left=replace_internal_loads(
                expr.left, produced_names
            ),
            right=replace_internal_loads(
                expr.right, produced_names
            ),
        )

    raise NotImplementedError(
        f"Unsupported expression: {type(expr)}"
    )


def fuse_pointwise(pointwise_ops: list[Pointwise]) -> FusedKernel:
    """
    Fuse an ordered sequence of 1D pointwise computations.

    Assumptions:
      - All operations are pure and elementwise.
      - Operations are in dependency order.
      - All extents match.
      - The last operation produces the output.
    """
    pointwise_ops = topological_sort_pointwise(pointwise_ops)
    if not pointwise_ops:
        raise ValueError("Cannot fuse an empty list")

    extent = pointwise_ops[0].extent
    produced_names = set()
    all_names = {op.name for op in pointwise_ops}
    statements = []

    if len(all_names) != len(pointwise_ops):
        raise ValueError("Duplicate pointwise names")

    for op in pointwise_ops:
        if op.extent != extent:
            raise ValueError(
                f"Extent mismatch for {op.name}"
            )

        # Prevent reading a fused value before it is computed.
        def check_dependencies(expr):
            if isinstance(expr, Load):
                if (
                    expr.buffer in all_names
                    and expr.buffer not in produced_names
                ):
                    raise ValueError(
                        f"{op.name} depends on unavailable "
                        f"value {expr.buffer}"
                    )
            elif isinstance(expr, (Add, Mul)):
                check_dependencies(expr.left)
                check_dependencies(expr.right)
            elif not isinstance(expr, (Const, Temp)):
                raise NotImplementedError(type(expr))

        check_dependencies(op.expression)

        new_expr = replace_internal_loads(
            op.expression,
            produced_names,
        )

        statements.append(
            Assign(
                name=op.name,
                expression=new_expr,
            )
        )

        produced_names.add(op.name)

    return FusedKernel(
        extent=extent,
        statements=statements,
        output=pointwise_ops[-1].name,
    )
