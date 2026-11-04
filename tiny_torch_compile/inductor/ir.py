from dataclasses import dataclass


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
