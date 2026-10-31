import dis

from guards import Guard
from ir import Graph, Op, Node


"""
LOAD_FAST    x
LOAD_FAST    y
BINARY_OP    *
STORE_FAST   z      ← z = x * y

LOAD_FAST    z
LOAD_CONST   1
BINARY_OP    +
STORE_FAST   z      ← z = z + 1

LOAD_FAST    z
RETURN_VALUE
"""

def describe(value):
    if isinstance(value, Node):
        return value.name
    return repr(value)


class MiniDynamo:
    def __init__(self):
        self.graph = Graph()
        self.stack = []
        self.locals = {}
        self.guards = []

    def trace(self, fn, flag: bool):
        self.locals = {
            "x": self.graph.add_input("x"),
            "flag": flag,
        }

        self.guards = [Guard("flag", flag)]
        print("Tracing with guards:", self.guards)
        # 1. Discover the function's positional arguments.
        # Example: forward(x, y) -> ("x", "y")
        code = fn.__code__
        arg_names = code.co_varnames[:code.co_argcount]

        print(f"\nTracing function: {fn.__name__}")
        print(f"Arguments: {arg_names}")

        # 2. Create symbolic input nodes.
        # We don't have real tensor values.
        for name in arg_names:
            node = self.graph.add_input(name)

        print("\nInitial locals:")
        print({k: getattr(v, "name", v) for k, v in self.locals.items()})
        # 3. Read and interpret the Python bytecode.
        instructions = list(dis.get_instructions(fn))

        """
        Every instruction has two different positions:
            - offset — its position in the original Python bytecode.
            - pc — its index in our Python list of instructions.
        """
        offset_to_pc = {
            ins.offset: i
            for i, ins in enumerate(instructions)
        }

        print(offset_to_pc)

        pc = 0

        while pc < len(instructions):
            ins = instructions[pc]

            print(f"PC={pc}: {ins.opname} {ins.argrepr}")
            pc += 1
            print("Stack BEFORE:",
                  [describe(n) for n in self.stack])

            if ins.opname == "RESUME":
                # Python interpreter bookkeeping.
                # Not relevant to our graph.
                pass

            elif ins.opname == "LOAD_FAST":
                # Look up a local variable by name.
                node = self.locals[ins.argval]

                # Push its symbolic Node onto the stack.
                self.stack.append(node)

                print(f"  Loaded variable: {ins.argval}")

            elif ins.opname == "LOAD_CONST":
                # Create a constant node in our graph.
                node = self.graph.add_const(ins.argval)

                # Push the constant node onto the stack.
                self.stack.append(node)

                print(f"  Created constant: {ins.argval}")

            elif ins.opname == "BINARY_OP":
                # Pop the top two operands.
                # Right operand is popped first.
                right = self.stack.pop()
                left = self.stack.pop()

                print(f"  Left operand:  {describe(left)}")
                print(f"  Right operand: {describe(right)}")

                # Translate Python operator to our IR op.
                if ins.argrepr == "*":
                    op = Op.MUL
                elif ins.argrepr == "+":
                    op = Op.ADD
                else:
                    raise NotImplementedError(ins.argrepr)

                # Create a graph node, NOT a numerical result.
                node = self.graph.add_node(
                    op, [left, right]
                )

                print(f"  Created graph node: {node}")

                # Push the symbolic result onto the stack.
                self.stack.append(node)
            elif ins.opname == "STORE_FAST":
                node = self.stack.pop()
                self.locals[ins.argval] = node

                print(f"  STORE_FAST: {ins.argval} = {describe(node)}")
                print({k: getattr(v, "name", v)
                      for k, v in self.locals.items()})
            elif ins.opname == "POP_JUMP_FORWARD_IF_FALSE":
                condition = self.stack.pop()
                if not isinstance(condition, bool):
                    raise NotImplementedError(
                        "Only concrete Boolean condition supported"
                    )

                if not condition:
                    pc = offset_to_pc[ins.argval]
                    print("f  Jumping to PC={pc}")
                    continue

                print("  Condition true, continue execution")

            elif ins.opname == "RETURN_VALUE":
                # The top of the stack is the function output.
                result = self.stack.pop()
                self.graph.set_output(result)

                print(f"  Returning: {describe(result)}")
                print("\nFinal Graph:")
                print(self.graph)

                return self.graph

            else:
                raise NotImplementedError(ins.opname)

            # 4. Show the state after executing an instruction.
            print("Stack AFTER:",
                  [describe(n) for n in self.stack])

            print("Graph so far:")
            print(self.graph.nodes[-1] if self.graph.nodes
                  else "(empty)")

        raise RuntimeError("No RETURN_VALUE found")
