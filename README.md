Binary Search Tree
==================

### What is this?

This is a C implementation of a binary search tree. It supports 
int numbers, although (using void pointers) could be used whit 
any value or structure.

### Building

This project is build using cmake. To build:

1. From the root of the project, create a dir named `build` and cd into it.
2. Type in a terminal `cmake ..` to create the makefiles for your platform.
3. Type `make .` to build the project in to the current dir.


### Usage

To use this bst, include the `bst.h` file into your source code. All functions imported from
that source file start with `bst_` (ex. `bst_create_tree(tree);`).
 
        