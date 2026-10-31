"""Test IR construction with ``python -m tests.test_ir``."""

import unittest

from tiny_torch_compile.ir import Graph, Op
from tiny_torch_compile.proxy import TensorProxy, relu


EXPECTED_IR = """\
x = input
y = input
%0 = mul(x, y)
%1 = const(1)
%2 = add(%0, %1)
%3 = relu(%2)
return %3"""


class GraphTests(unittest.TestCase):
    def test_manual_graph(self):
        graph = Graph()

        x = graph.add_input("x")
        y = graph.add_input("y")

        product = graph.add_node(Op.MUL, [x, y])
        one = graph.add_const(1)
        shifted = graph.add_node(Op.ADD, [product, one])
        output = graph.add_node(Op.RELU, [shifted])
        graph.set_output(output)

        self.assertEqual(str(graph), EXPECTED_IR)

    def test_proxy_graph(self):
        graph = Graph()

        x = TensorProxy(graph, graph.add_input("x"))
        y = TensorProxy(graph, graph.add_input("y"))

        def forward(x, y):
            return relu(x * y + 1)

        output = forward(x, y)
        graph.set_output(output.node)

        self.assertEqual(str(graph), EXPECTED_IR)


if __name__ == "__main__":
    unittest.main(verbosity=2)
