from ast import Add

from ..ir import Graph, Op
from .ir import Const, InputBuffer, Load, Mul, Pointwise


def get_extent(left, right):
    def extent(value):
        if isinstance(value, InputBuffer):
            return value.shape[0]

        if isinstance(value, Pointwise):
            return value.extent

        if isinstance(value, Const):
            return None  # Scalars have no iteration extent

        raise TypeError(f"Unsupported operand: {type(value)}")

    left_n = extent(left)
    right_n = extent(right)

    if left_n is None and right_n is None:
        raise NotImplementedError("Scalar-only operations")

    if left_n is not None and right_n is not None:
        if left_n != right_n:
            raise ValueError("Tensor sizes must match")

    return left_n if left_n is not None else right_n


def as_expr(value):
    if isinstance(value, (InputBuffer, Pointwise)):
        return Load(value.name, "i")

    if isinstance(value, Const):
        return value

    raise TypeError(type(value))


class MiniInductor:
    def lower(self, graph: Graph, input_specs: dict):
        env = {}             # Original Node -> lowered representation
        pointwise_ops = []

        for node in graph.nodes:
            if node.op == Op.INPUT:
                # Register input buffer and shape
                shape = tuple(input_specs[node.name])

                if len(shape) != 1:
                    raise NotImplementedError(
                        "Only 1D tensors are supported"
                    )

                env[node] = InputBuffer(
                    name=node.name,
                    shape=shape,
                )

            elif node.op == Op.CONST:
                env[node] = Const(node.value)

            elif node.op in (Op.MUL, Op.ADD):
                left = env[node.inputs[0]]
                right = env[node.inputs[1]]

                n = get_extent(left, right)

                left_expr = as_expr(left)
                right_expr = as_expr(right)

                if node.op == Op.MUL:
                    expression = Mul(left_expr, right_expr)
                else:
                    expression = Add(left_expr, right_expr)

                lowered = Pointwise(
                    name=node.name,
                    extent=n,
                    expression=expression,
                )

                env[node] = lowered
                pointwise_ops.append(lowered)
            else:
                raise NotImplementedError(
                    f"Lowering not implemented: {node.op}"
                )
        self.env = env
        return pointwise_ops
