"""Run tracing tests: python -m tests.test_tracing

Run one group: python -m tests.test_tracing -k mini_dynamo
              python -m tests.test_tracing -k graph_cache
              python -m tests.test_tracing -k decomposition
"""

import dis
import unittest

from tiny_torch_compile.dynamo import GraphCache, MiniDynamo
from tiny_torch_compile.decomp.decompositions import decompose
from tiny_torch_compile.ir import Op
from tiny_torch_compile.proxy import relu


def forward_with_flag(x, flag):
    z = x * 2

    if flag:
        z = z + 1
    return z


def forward_relu(x, y):
    return relu(x*y + 1)


def forward(x, y):
    z = x * y + 1
    return z ** 2


class TracingTests(unittest.TestCase):
    def test_mini_dynamo(self):
        tracer = MiniDynamo()
        graph = tracer.trace(forward_with_flag, flag=True)

        print("\nCaptured branch graph:")
        print(graph)

        self.assertTrue(tracer.guards[0].check({"flag": True}))
        self.assertFalse(tracer.guards[0].check({"flag": False}))

    def test_mini_dynamo_relu(self):
        for instruction in dis.get_instructions(forward_relu):
            print(instruction.opname, instruction.argrepr)

        tracer = MiniDynamo()
        graph = tracer.trace(forward_relu)

        print("\nCaptured graph:")
        print(graph)

        self.assertEqual(str(graph), "\n".join([
            "x = input",
            "y = input",
            "%0 = mul(x, y)",
            "%1 = const(1)",
            "%2 = add(%0, %1)",
            "%3 = relu(%2)",
            "return %3",
        ]))
        self.assertEqual(tracer.guards, [])

    def test_mini_dynamo_pow(self):
        graph = MiniDynamo().trace(forward)

        print("\nCaptured power graph:")
        print(graph)

        self.assertEqual(str(graph), "\n".join([
            "x = input",
            "y = input",
            "%0 = mul(x, y)",
            "%1 = const(1)",
            "%2 = add(%0, %1)",
            "%3 = const(2)",
            "%4 = pow(%2, %3)",
            "return %4",
        ]))
        self.assertIs(graph.output.op, Op.POW)

    def test_decomposition(self):
        tracer = MiniDynamo()
        original = tracer.trace(forward)
        original_text = str(original)

        normalized = decompose(original)

        print("Before decomposition:")
        print(original)
        print("\nAfter decomposition:")
        print(normalized)

        self.assertEqual(str(original), original_text)
        self.assertIs(original.output.op, Op.POW)
        self.assertIsNot(normalized, original)
        self.assertEqual(str(normalized), "\n".join([
            "x = input",
            "y = input",
            "%0 = mul(x, y)",
            "%1 = const(1)",
            "%2 = add(%0, %1)",
            "%3 = mul(%2, %2)",
            "return %3",
        ]))
        self.assertIs(normalized.output.inputs[0], normalized.output.inputs[1])

    def test_graph_cache(self):
        cache = GraphCache()

        g1 = cache.get_or_trace(forward_with_flag, True)
        g2 = cache.get_or_trace(forward_with_flag, True)
        g3 = cache.get_or_trace(forward_with_flag, False)
        g4 = cache.get_or_trace(forward_with_flag, True)
        g5 = cache.get_or_trace(forward_with_flag, False)

        self.assertIs(g1, g2)
        self.assertIs(g1, g4)
        self.assertIsNot(g1, g3)
        self.assertIs(g3, g5)
        self.assertEqual(len(cache.entries[forward_with_flag]), 2)


if __name__ == "__main__":
    unittest.main(verbosity=2)
