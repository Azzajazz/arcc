# arcc
A C compiler written in C.

## Building from source
Automatic building is currently only done by Makefiles. To build the compiler from source, execute the following commands from the top-level directory
```
cd arcc
make
```

To compile the `gcc` and `arcc` examples, follow the steps for building the compiler shown above and then execute the following commands from the top-level directory.
```
cd examples
make
```

## Supported language features
Support is currently limited to:
- The `int` type keyword
- Function definitions with no parameters
- `return` statments
- Integer constants
This list will be expanded in future.

Programs can currently only consist of one function definition. This will be expanded in future.

## Examples
Examples can be found in the `examples` subdirectory. Files in the `asm` subdirectory end in `_arcc` or `_gcc` depending on whether they were compiled by `arcc` or `gcc`. The corresponding source code can be found in the `C` subdirectory.