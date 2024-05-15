# Assignment 2 - Graphs and Operator Overloading

This project extends the `Graph` class from the previous assignment to support arithmetic and comparison operators. The graph representation continues to use an adjacency matrix.

## Implementation Method and Code Division

The `Graph` class is implemented in `Graph.cpp` and `Graph.hpp`. It uses a 2D vector to represent the adjacency matrix of the graph. The class includes methods for loading a graph from an adjacency matrix, printing the graph, and performing arithmetic and comparison operations.

The arithmetic and comparison operators are overloaded in the `Graph` class to perform element-wise operations on the adjacency matrices of the graphs. The increment and decrement operators, both prefix and postfix, are implemented to increase or decrease by 1 all the weights of the edges in the graph. The multiplication by an integer scalar multiplies the weight of all edges, and the graph multiplication multiplies the representative matrices of two graphs to produce a new graph.

The `Algorithms.cpp` file contains implementations of various graph algorithms, including those from the previous assignment and any new ones required for this assignment.

The `Main.cpp` file provides examples of how to use the implemented algorithms and operators.

## Files

- `Graph.cpp`: Contains the implementation of the `Graph` class, including methods to load a graph from an adjacency matrix, print the graph, and perform arithmetic and comparison operations.
- `Algorithms.cpp`: Implements various graph algorithms, including those from the previous assignment.
- `Main.cpp`: Provides examples of input and output for the implemented algorithms and operators.

## Running the Program

To compile the program, run `make all`. This will generate the executable files `main` and `test`.

- `./main`: Executes the main function, demonstrating the usage of the implemented algorithms and operators.
- `./test`: Runs the test suite to validate the correctness of the implemented algorithms and operators.

## Usage

- `Graph.cpp`: Include this file in your project to use the `Graph` class for representing graphs, loading them from adjacency matrices, and performing arithmetic and comparison operations.
- `Algorithms.cpp`: Include this file in your project to use the implemented graph algorithms.
- `Main.cpp`: Refer to this file for examples of how to use the implemented algorithms and operators.

## Operators Implemented

- Six arithmetic operators: addition (+), addition (+=), unary plus (+), and the corresponding subtraction (-) operators.
- Six comparison operators: greater, greater-or-equal, less, less-or-equal, equal, not-equal.
- Increment (++) and decrement (--) operators, both prefix and postfix. These increase or decrease by 1 all the weights of the edges in the graph.
- Multiplication by an integer scalar (`int`): Multiplies the weight of all edges.
- Graph multiplication: Multiplies the representative matrices of two graphs to produce a new graph.
- Output operator: Prints the graph.

## Author

Gidi Rabi
gidirabi111@gmail.com