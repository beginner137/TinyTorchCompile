from ir import Graph, Op

g = Graph()

x = g.add_input("x")
y = g.add_input("y")

a = g.add_node(Op.MUL, [x, y])
one = g.add_const(1)
b = g.add_node(Op.ADD, [a, one])
c = g.add_node(Op.RELU, [b])

g.set_output(c)

print(g)
