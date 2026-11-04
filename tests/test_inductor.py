"""Run MiniInductor tests with ``python -m tests.test_inductor``."""

import unittest

from tiny_torch_compile.ir import Graph, Op
from tiny_torch_compile.decomp.decompositions import decompose
from tiny_torch_compile.inductor.codegen import generate_python, generate_triton
from tiny_torch_compile.inductor.lowering import MiniInductor
from tiny_torch_compile.inductor.ir import Add, Const, Load, Mul, Pointwise, Temp
from tiny_torch_compile.inductor.scheduler import (
    can_fuse,
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

    def _lower_square_graph(self):
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
        return MiniInductor().lower(
            normalized_graph,
            {"x": (1024,), "y": (1024,)},
        )

    def test_scheduler(self):
        pointwise_ops = self._lower_square_graph()
        shuffled = list(reversed(pointwise_ops))
        ordered = topological_sort_pointwise(shuffled)
        self.assertEqual([op.name for op in ordered], ["%0", "%2", "%3"])

        # Fusion should also sort its input before replacing internal loads.
        fused = fuse_pointwise(shuffled)
        self.assertEqual(fused, fuse_pointwise(pointwise_ops))

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

    def test_can_fuse(self):
        pointwise_ops = self._lower_square_graph()
        pw0, pw2, pw3 = pointwise_ops

        self.assertTrue(can_fuse(pw0, pw2))
        self.assertTrue(can_fuse(pw2, pw3))

        # Shifted indexing cannot be replaced by a local temporary.
        shifted = Pointwise(
            name="%shifted",
            extent=1024,
            expression=Add(Load("%0", "i+1"), Const(1)),
        )
        self.assertFalse(can_fuse(pw0, shifted))

        # Fused operations must have matching iteration extents.
        different_extent = Pointwise(
            name="%different",
            extent=512,
            expression=Add(Load("%0", "i"), Const(1)),
        )
        self.assertFalse(can_fuse(pw0, different_extent))

        print("Fusion legality tests passed!")

    def test_scheduler_rejects_illegal_fusion(self):
        producer = self._lower_square_graph()[0]
        consumers = [
            Pointwise("%shifted", 1024, Add(Load("%0", "i+1"), Const(1))),
            Pointwise("%different", 512, Add(Load("%0", "i"), Const(1))),
            Pointwise("%independent", 1024, Add(Load("x", "i"), Const(1))),
        ]

        for consumer in consumers:
            with self.subTest(consumer=consumer.name):
                with self.assertRaisesRegex(
                    ValueError,
                    f"Cannot vertically fuse %0 -> {consumer.name}",
                ):
                    fuse_pointwise([producer, consumer])

        print("Illegal fusion attempts correctly rejected!")

    def test_codegen_triton(self):
        pointwise_ops = self._lower_square_graph()
        fused = fuse_pointwise(pointwise_ops)

        source, inputs = generate_triton(fused)

        print("Input buffers:", inputs)
        print("\nGenerated Triton:")
        print(source)

        self.assertEqual(inputs, ["x", "y"])
        self.assertIn("@triton.jit", source)
        self.assertIn("tl.load", source)
        self.assertIn("tl.store", source)

    def test_codegen(self):
        pointwise_ops = self._lower_square_graph()
        fused = fuse_pointwise(pointwise_ops)

        source = generate_python(fused)
        print(source)

        namespace = {}
        exec(source, namespace)
        compiled_fn = namespace["fused_kernel"]

        x = [1.0] * 1024
        y = [3.0] * 1024
        result = compiled_fn(x, y)

        self.assertEqual(result, [16.0] * 1024)
        print("PASS!")


if __name__ == "__main__":
    unittest.main(verbosity=2)
