from dataclasses import dataclass, fields
import json


@dataclass
class Load:
    buffer: str
    index: str


@dataclass
class Pointwise:
    name: str
    extent: int
    expression: object


@dataclass
class InputBuffer:
    name: str
    shape: tuple


@dataclass
class Add:
    left: object
    right: object


@dataclass
class Mul:
    left: object
    right: object


@dataclass
class Const:
    value: object


@dataclass
class Temp:
    name: str


@dataclass
class Assign:
    name: str
    expression: object


@dataclass
class FusedKernel:
    extent: int
    statements: list[Assign]
    output: str

    def __str__(self):
        def format_value(value):
            if isinstance(value, str):
                return json.dumps(value)
            if isinstance(value, (Assign, Load, Temp, Const, Add, Mul)):
                arguments = ", ".join(
                    format_value(getattr(value, field.name))
                    for field in fields(value)
                )
                return f"{type(value).__name__}({arguments})"
            return repr(value)

        lines = [
            "FusedKernel(",
            f"    extent={self.extent},",
            "    statements=[",
        ]
        lines.extend(f"        {format_value(stmt)}," for stmt in self.statements)
        lines.extend([
            "    ],",
            f"    output={format_value(self.output)},",
            ")",
        ])
        return "\n".join(lines)
