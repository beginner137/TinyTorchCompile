from dataclasses import dataclass


@dataclass
class Guard:
    name: str
    expected: bool

    def check(self, values: dict) -> bool:
        actual = values[self.name]
        return type(actual) is bool and actual == self.expected
