
class Guard:
    def __init__(self, name, predicate):
        self.name = name
        self.predicate = predicate

    def check(self, context):
        return self.predicate(context)
