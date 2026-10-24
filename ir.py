from enum import Enum, auto


class Op(Enum):
    INPUT = auto()
    CONST = auto()
    ADD = auto()
    MUL = auto()
    RELU = auto()


class Node:
    def __init__(self, op: Op, inputs: list, name: str, value=None):
        self.op = op  # "mul", "input"
        self.inputs = inputs  # [x, y] other Nodes
        self.name = name  # "%0"
        self.value = value

    def __repr__(self):
        match self.op:
            case Op.INPUT:
                return f"{self.name} = input"
            case Op.CONST:
                return f"{self.name} = const({self.value})"
            case _:
                operands = ", ".join(node.name for node in self.inputs)
                return f"{self.name} = {self.op.name.lower()}({operands})"


class Graph:
    def __init__(self):
        self.nodes = []
        self.output = None
        self.next_id = 0

    def _get_name(self):
        name = f"%{self.next_id}"
        self.next_id += 1
        return name

    def add_input(self, name):
        node = Node(Op.INPUT, [], name)
        self.nodes.append(node)
        return node

    def add_const(self, value):
        node = Node(Op.CONST, [], self._get_name(), value)
        self.nodes.append(node)
        return node

    def add_node(self, op: Op, inputs):
        if not isinstance(op, Op):
            raise TypeError(f"Expected Op enum, got {type(op)}")
        node = Node(op, inputs, self._get_name())
        self.nodes.append(node)
        return node

    def set_output(self, node):
        self.output = node

    def __repr__(self):
        s = "\n".join(str(node) for node in self.nodes)
        s += f"\nreturn {self.output.name}"
        return s
