"""Run tracing tests: python -m tests.test_tracing

Run one group: python -m tests.test_tracing -k mini_dynamo
              python -m tests.test_tracing -k graph_cache
"""

import dis
import unittest

from tiny_torch_compile.dynamo import GraphCache, MiniDynamo
from tiny_torch_compile.proxy import relu


def forward_with_flag(x, flag):
    z = x * 2

    if flag:
        z = z + 1
    return z


def forward(x, y):
    return relu(x*y + 1)


class TracingTests(unittest.TestCase):
    def test_mini_dynamo(self):
        tracer = MiniDynamo()
        graph = tracer.trace(forward_with_flag, flag=True)

        print("\nCaptured branch graph:")
        print(graph)

        self.assertTrue(tracer.guards[0].check({"flag": True}))
        self.assertFalse(tracer.guards[0].check({"flag": False}))

    def test_mini_dynamo_relu(self):
        for instruction in dis.get_instructions(forward):
            print(instruction.opname, instruction.argrepr)

        tracer = MiniDynamo()
        graph = tracer.trace(forward)

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
