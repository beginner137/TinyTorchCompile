
from tiny_torch_compile.ir import Graph, Node, Op


def decompose(graph: Graph) -> Graph:
    new_graph = Graph()
    memo = {}

    def rewrite(node: Node) -> Node:
        if node in memo:
            return memo[node]

        if node.op == Op.INPUT:
            result = new_graph.add_input(node.name)
        elif node.op == Op.CONST:
            result = new_graph.add_const(node.value)
        elif node.op == Op.POW:
            base, exponent = node.inputs

            if exponent.op != Op.CONST or exponent.value != 2:
                raise NotImplementedError(
                    "Only POW(x, 2) is supported"
                )
            new_base = rewrite(base)

            # POW(base, 2) -> MUL(base, base)
            result = new_graph.add_node(
                Op.MUL, [new_base, new_base]
            )
        elif node.op in (Op.ADD, Op.MUL, Op.RELU):
            new_inputs = [
                rewrite(inp) for inp in node.inputs
            ]
            result = new_graph.add_node(
                node.op, new_inputs
            )
        else:
            raise NotImplementedError(
                f"No decomposition for {node.op}"
            )

        memo[node] = result
        return result

    new_graph.set_output(rewrite(graph.output))
    return new_graph
