"""Run MiniInductor tests with ``python -m tests.test_inductor``."""

import unittest

from tiny_torch_compile.ir import Graph, Op
from tiny_torch_compile.decomp.decompositions import decompose
from tiny_torch_compile.inductor.lowering import MiniInductor
from tiny_torch_compile.inductor.ir import Add, Const, Load, Mul, Temp
from tiny_torch_compile.inductor.scheduler import (
    fuse_pointwise,
    topological_sort_pointwise,
)


class MiniInductorTests(unittest.TestCase):
    def test_lower_mul(self):
        graph = Graph()
        x = graph.add_input("x")
        y = graph.add_input("y")
        result = graph.add_node(Op.MUL, [x, y])
        graph.set_output(result)

        inductor = MiniInductor()
        ops = inductor.lower(
            graph,
            input_specs={"x": (1024,), "y": (1024,)},
        )

        self.assertEqual(len(ops), 1)
        self.assertEqual(ops[0].extent, 1024)
        self.assertEqual(ops[0].expression, Mul(Load("x", "i"), Load("y", "i")))

        print(ops[0])

    def test_scheduler(self):
        graph = Graph()
        x = graph.add_input("x")
        y = graph.add_input("y")
        product = graph.add_node(Op.MUL, [x, y])
        one = graph.add_const(1)
        shifted = graph.add_node(Op.ADD, [product, one])
        two = graph.add_const(2)
        result = graph.add_node(Op.POW, [shifted, two])
        graph.set_output(result)

        normalized_graph = decompose(graph)
        pointwise_ops = MiniInductor().lower(
            normalized_graph,
            {"x": (1024,), "y": (1024,)},
        )
        shuffled = list(reversed(pointwise_ops))
        ordered = topological_sort_pointwise(shuffled)
        self.assertEqual([op.name for op in ordered], ["%0", "%2", "%3"])

        # Fusion should also sort its input before replacing internal loads.
        fused = fuse_pointwise(shuffled)

        print("\nFused kernel:")
        print(fused)

        self.assertEqual(fused.extent, 1024)
        self.assertEqual(fused.output, "%3")
        self.assertEqual(len(fused.statements), 3)
        self.assertEqual(
            fused.statements[0].expression,
            Mul(Load("x", "i"), Load("y", "i")),
        )
        self.assertEqual(
            fused.statements[1].expression,
            Add(Temp("%0"), Const(1)),
        )
        self.assertEqual(
            fused.statements[2].expression,
            Mul(Temp("%2"), Temp("%2")),
        )


if __name__ == "__main__":
    unittest.main(verbosity=2)
