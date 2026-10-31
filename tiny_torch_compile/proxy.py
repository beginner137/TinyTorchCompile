from .ir import Graph, Node, Op


class TensorProxy:
    def __init__(self, graph: Graph, node: Node):
        self.graph = graph
        self.node = node

    def __mul__(self, other: "TensorProxy"):
        node = self.graph.add_node(Op.MUL, [self.node, other.node])
        return TensorProxy(self.graph, node)

    def __add__(self, other):
        if isinstance(other, TensorProxy):
            other_node = other.node
        else:
            other_node = self.graph.add_const(other)

        node = self.graph.add_node(
            Op.ADD, [self.node, other_node]
        )
        return TensorProxy(self.graph, node)


def relu(x: TensorProxy):
    node = x.graph.add_node(
        Op.RELU, [x.node]
    )
    return TensorProxy(x.graph, node)
