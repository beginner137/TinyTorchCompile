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
class Mul:
    left: object
    right: object


@dataclass
class Const:
    value: object
