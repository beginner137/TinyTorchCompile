"""Run MiniInductor tests with ``python -m tests.test_inductor``."""

import unittest

from tiny_torch_compile.ir import Graph, Op
from tiny_torch_compile.inductor.lowering import MiniInductor
from tiny_torch_compile.inductor.ir import Load, Mul


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


if __name__ == "__main__":
    unittest.main(verbosity=2)
