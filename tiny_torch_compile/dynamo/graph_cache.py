from .mini_dynamo import MiniDynamo


class GraphCache:
    def __init__(self):
        self.entries = {}

    def get_or_trace(self, fn, flag: bool):
        # 1. look for existing valid graph
        for entry in self.entries.get(fn, []):
            if all(g.check({"flag": flag}) for g in entry["guards"]):
                print("CACHE HIT")
                return entry["graph"]

        # 2. no matching graph -> trace
        print("CACHE MISS")
        tracer = MiniDynamo()
        graph = tracer.trace(fn, flag=flag)

        entry = {
            "graph": graph,
            "guards": list(tracer.guards),
        }
        self.entries.setdefault(fn, []).append(entry)
        return graph
