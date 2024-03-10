# linkedlist

Linked list implementation in C.

NOTES:

+ This is a just for fun project to implement data structures and algorithms in C.
+ This is not focused in performance, so it's not a good idea to use this in production.
+ Use a Generic Linked List implementation in C, so it's possible to use it with any data type is less performant than a specific implementation.  This is because the data type is passed as a void pointer and when `malloc` is used to allocate memory for the data type, this is not together with the node, so it's necessary to allocate memory for the data type and then assign the pointer to the node.

## Development

## Requirements

+ [GNU Make](https://www.gnu.org/software/make/)
+ [GCC](https://gcc.gnu.org/)
+ [Valgrind](https://www.valgrind.org/) or [Leak](https://developer.apple.com/library/archive/documentation/Performance/Conceptual/ManagingMemory/Articles/FindingLeaks.html)
+ [Doxygen](http://www.doxygen.nl/)

## make targets

```bash
make help
```

## Build

Build the library

```bash
make
```

## Test

Test the library

```bash
make test
```

## Memory Leak

Check for memory leaks

```bash
make memcheck
```

## License

This module is released under the Apache License Version 2.0:

+ [http://www.apache.org/licenses/LICENSE-2.0.html](http://www.apache.org/licenses/LICENSE-2.0.html)
