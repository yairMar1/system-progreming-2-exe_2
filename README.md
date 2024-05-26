**************************************************
Explanation of the fulfillment of the assignment
**************************************************

After in the first part of the assignment we implemented all kinds of algorithms on graphs that are represented with the help of a neighborhood matrix.
Since a graph is a complex type, in this section we were required to define its arithmetic operations. Below is a brief explanation of each function and what it does

**********************
Arithmetic Operations
**********************

#### Addition (`operator+`)
- Adds the adjacency matrices of two graphs element-wise and returns a new graph representing the sum of the graphs.
  
#### Subtraction (`operator-`)
- Subtracts the adjacency matrices of two graphs element-wise and returns a new graph representing the difference between the graphs.

#### In-Place Addition (`operator+=`)
- Adds the adjacency matrix of another graph to the current graph, modifying it in place.

#### In-Place Subtraction (`operator-=`)
- Subtracts the adjacency matrix of another graph from the current graph, modifying it in place.

#### Unary Plus (`operator+`)
- Returns the graph itself without any modification.

#### Unary Minus (`operator-`)
- Negates the adjacency matrix elements of the graph and returns a new graph.

#### Scalar Multiplication (`operator*`)
- Multiplies the adjacency matrix elements of the graph by a scalar and returns a new graph.

#### Prefix Increment (`operator++`)
- Increments the adjacency matrix elements of the graph by 1 and returns the updated graph.

#### Postfix Increment (`operator++`)
- Returns the graph and then increments the adjacency matrix elements by 1.

#### Prefix Decrement (`operator--`)
- Decrements the adjacency matrix elements of the graph by 1 and returns the updated graph.

#### Postfix Decrement (`operator--`)
- Returns the graph and then decrements the adjacency matrix elements by 1.

#### In-Place Scalar Multiplication (`operator*=`)
- Multiplies the adjacency matrix elements of the graph by a scalar, modifying it in place.

**********************
Comparison Operations
**********************

#### Less Than (`operator<`)
- Checks if the current graph is a subgraph of another graph.

#### Greater Than (`operator>`)
- Checks if the current graph contains another graph.

#### Equal To (`operator==`)
- Checks if the adjacency matrices of two graphs are equal.

#### Less Than or Equal To (`operator<=`)
- Checks if the current graph is a subgraph of or equal to another graph.

#### Greater Than or Equal To (`operator>=`)
- Checks if the current graph contains or is equal to another graph.

### Matrix Multiplication

#### Matrix Multiplication (`operator*`)
- Multiplies the adjacency matrices of two graphs and returns a new graph representing the product of the matrices.

**********************
I/O Operations
**********************

#### Output Stream (`operator<<`)
- Prints the adjacency matrix of the graph to the output stream.
