"""Run all tests: python test_tracing.py

Run one group: python test_tracing.py -k mini_dynamo
              python test_tracing.py -k graph_cache
"""

import dis
import unittest

from graph_cache import GraphCache
from mini_dynamo import MiniDynamo


def forward(x, flag):
    z = x * 2

    if flag:
        z = z + 1
    return z


class TracingTests(unittest.TestCase):
    def test_mini_dynamo(self):
        for instruction in dis.get_instructions(forward):
            print(instruction.opname, instruction.argrepr)

        tracer = MiniDynamo()
        graph = tracer.trace(forward, flag=True)

        print("\nCaptured graph:")
        print(graph)

        self.assertTrue(tracer.guards[0].check({"flag": True}))
        self.assertFalse(tracer.guards[0].check({"flag": False}))

    def test_graph_cache(self):
        cache = GraphCache()

        g1 = cache.get_or_trace(forward, True)
        g2 = cache.get_or_trace(forward, True)
        g3 = cache.get_or_trace(forward, False)
        g4 = cache.get_or_trace(forward, True)

        self.assertIs(g1, g2)
        self.assertIs(g1, g4)
        self.assertIsNot(g1, g3)
        self.assertEqual(len(cache.entries[forward]), 2)


if __name__ == "__main__":
    unittest.main(verbosity=2)
