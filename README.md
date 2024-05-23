***************************************
Definitions:
***************************************

**Connected graph**  a graph that through one vertex we can reach every other vertex in the graph.

**shortest way**
In the weighted graph the output will be the sum of the cheapest edges from the source vertex to the destination.
In an unweighted graph the output will have the smallest number of edges from the source to the destination.

**A circle in a graph** a path that starts and ends at the same vertex. (In an undirected graph there is always a circle. In extreme cases, a vertex with itself or another vertex and back and forth).

**Bilateral graph** a graph in which the vertices can be classified into two groups. the edges are between the two groups and not between the group members. I defined that if the graph is not connected, meaning there are no edges between the two groups, the graph is not a Bilateral graph.

**Negative circles** a route whose total edge weights are negative.

***************************************
Choosing an algorithm to implement a function
***************************************

*****************
isConnected:
*****************

1. **Algorithm Choice**: BFS is a suitable choice because it efficiently explores all vertices reachable from a starting vertex in a systematic manner. It's ideal for determining graph connectivity as it traverses vertices layer by layer, ensuring that it visits all reachable vertices.

2. **Implementation**: The algorithm works by starting from a given vertex and exploring its neighbors first before moving on to their neighbors. It maintains a queue to keep track of the vertices to visit, ensuring that vertices are visited in the order of their distance from the starting vertex.

3. **Graph Type Handling**: The algorithm is versatile and can handle both directed and undirected graphs. For directed graphs, it runs BFS from each vertex to ensure all vertices are reachable. For undirected graphs, it only needs to run BFS once from any vertex.

4. **Output**: Returns `1 (true)` if the graph is connected, and `0 (false)` if the graph is not connected.

BFS is a suitable algorithm for determining graph connectivity due to its efficiency, systematic exploration of vertices, and versatility in handling different types of graphs.

*****************
shortestPath:
*****************

1. **Algorithm Choice**: Bellman-Ford is a suitable choice because it can handle graphs with negative edge weights and also detect negative cycles. It's commonly used when there might be negative weight edges in the graph, making it versatile for various scenarios.

2. **Handling Negative Edges**: Bellman-Ford algorithm can handle graphs with negative edge weights by iteratively relaxing edges in a number of iterations equal to the number of vertices minus one. This ensures that the shortest path distances are computed correctly, even in the presence of negative edge weights.

3. **Negative Cycle Detection**: After performing the relaxation step for the required number of iterations, the algorithm checks for the presence of negative cycles by performing one additional iteration. If a shorter path is found, it indicates the presence of a negative cycle.

4. **Output**: Returns a string indicating the shortest path from `startVertex` to `endVertex`. If no path exists, returns `-1 (No path exists)`. If the input vertices are out of range, returns `At least one of the vertices you entered is not in the graph`.

*****************
isContainsCycle:
*****************

1. **Algorithm Choice**: DFS is commonly used to detect cycles in a graph due to its simplicity and efficiency. It systematically explores the graph, marking vertices as visited and recursively visiting adjacent vertices.

2. **Cycle Detection**: In the DFS traversal, if we encounter a vertex that is already visited and is currently in the recursion stack, it implies the existence of a back edge, which forms a cycle in the graph. This is because we can reach the current vertex from the ancestor vertex via multiple paths.

3. **Implementation**: The implementation of DFS in this algorithm keeps track of visited vertices and vertices currently in the recursion stack. If a cycle is detected during the traversal, the algorithm constructs a string representation of the cycle and returns it.

4. **Output**: Returns `Cycle detected: [vertex sequence]` if a cycle is detected in the graph, where `[vertex sequence]` represents the vertices forming the cycle. If no cycle is found, returns "0".

*****************
isBipartite:
*****************

1. **Algorithm Choice**: This function utilizes a depth-first search (DFS) approach for checking bipartiteness in graphs. DFS is effective for traversing connected components and assigning colors to vertices.

2. **Bipartite Graphs**: A graph is bipartite if its vertices can be partitioned into two disjoint sets such that no edge connects vertices within the same set. DFS explores the graph, coloring vertices alternatively and ensuring no adjacent vertices have the same color.

3. **Coloring Technique**: Vertices are colored using two distinct colors, represented by integers. The function employs DFS to traverse the graph, assigning colors to vertices and detecting violations of bipartiteness.

4. **Implementation**: The algorithm initializes two sets, partitionA and partitionB, to store vertices belonging to each partition. DFS explores the graph, coloring vertices alternately and checking for violations of bipartiteness. If a violation is found, the function returns "0 (false)", indicating that the graph is not bipartite.

5. **Output**: Returns `Graph is bipartite: A={..} B={..}` if the graph is bipartite, where `{...}` represents the vertices in each partition. If the graph is not bipartite, returns `0 (false)`.

*****************
negativeCycle:
*****************

1. **Bellman-Ford Algorithm**: This algorithm is commonly used to find the shortest paths from a single source vertex to all other vertices in a weighted graph. It can also detect the presence of negative cycles in the graph.

2. **Negative Cycles**: A negative cycle exists in a graph if there is a path that starts and ends at the same vertex, and the sum of the weights of the edges along the path is negative. Bellman-Ford detects negative cycles by iteratively relaxing edges in the graph.

3. **Implementation**: The algorithm is applied to each vertex in the graph, with the start and end vertices set to the same vertex. This allows Bellman-Ford to detect negative cycles originating from each vertex individually. If a negative cycle is detected during any iteration, the function immediately returns an indication of the graph containing a negative cycle.

4. **Output**: Returns `Graph contains negative cycle` if the graph contains a negative cycle. If no negative cycle is found, returns `No negative cycle found.`

*****************
PART 2
*****************

***************************************
Definitions:
***************************************

The only definition I think I may have made important assumptions to remember:
When I did arithmetical operations of addition or subtraction, if there was no edge in the graph we were adding/subtracting to/from an edge would be added to it if we added something different from zero.

