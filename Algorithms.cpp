#include "Graph.hpp"
#include "Algorithms.hpp"

#include <queue>
#include <limits>
#include <unordered_set>
#include <sstream>
#include <stack>

namespace ariel{
    namespace Algorithms{

bool bfs(const Graph& graph, int startVertex) {
     const size_t numVertices = graph.getAdjacencyMatrix().size();
     // Mark all vertices as not visited
     std::vector<bool> visited(graph.getAdjacencyMatrix().size(), false);

     // Create a queue for BFS
     std::queue<int> queue;

     // Mark the current vertex as visited and enqueue it
     visited[static_cast<size_t>(startVertex)] = true;
     queue.push(startVertex);

     // Continue until the queue is empty
     while (!queue.empty()) {
         // Dequeue a vertex from the queue
         size_t currentVertex = static_cast<size_t>(queue.front());
         queue.pop();

         // Get all adjacent vertices of the dequeued vertex
         // If an adjacent vertex has not been visited, mark it as visited and enqueue it
         for (size_t i = 0; i < numVertices; ++i) {
             if (graph.getAdjacencyMatrix()[currentVertex][i] != 0 && !visited[i]) {
                 visited[i] = true;
                 queue.push(i);
             }
         }
     }

     // Check if all vertices are visited
     for (size_t i = 0; i < numVertices; ++i) {
         if (!visited[i]) {
             return false; // Graph is not connected
         }
     }

     return true; // Graph is connected
}

std::string isConnected(const Graph& graph) {
    const size_t numVertices = graph.getAdjacencyMatrix().size();
    // Check if the graph is directed
    if (graph.isDirected()) {
        // Iterate over each vertex and perform BFS
        for (size_t i = 0; i < numVertices; i++) {
            if (bfs(graph, i)) {
                //std::cout << "The graph is connected" << std::endl;
                return "1 (true)";
            }
        }
    } else {
        // If the graph is undirected, run BFS once from any vertex
        if (bfs(graph, 0)) {
            //std::cout << "The graph is connected" << std::endl;
            return "1 (true)";
        }
    }
    //std::cout << "The graph is not connected" << std::endl;
    return "0 (false)";
}


std::string shortestPath(const Graph& graph, size_t startVertex, size_t endVertex) {
    if (startVertex<0 || startVertex >= graph.getAdjacencyMatrix().size() || endVertex<0 || endVertex >= graph.getAdjacencyMatrix().size()){
        return "At least one of the vertices you entered is not in the graph";}
    const int maxValue = std::numeric_limits<int>::max();
    const size_t numVertices = graph.getAdjacencyMatrix().size();
    std::vector<int> distance(numVertices, maxValue);
    std::vector<int> parent(numVertices, -1);

    distance[startVertex] = 0;

    // The relaxation operation n-1 times
    for (size_t i = 0; i < numVertices - 1; ++i) {
        // Iterate over all edges
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                // Consider both directions of the edge (u, v) and (v, u)
                if (graph.getAdjacencyMatrix()[u][v] != 0 && distance[u] != maxValue &&
                    distance[u] + graph.getAdjacencyMatrix()[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph.getAdjacencyMatrix()[u][v];
                    parent[v] = u;
                }
                if (graph.getAdjacencyMatrix()[v][u] != 0 && distance[v] != maxValue &&
                    distance[v] + graph.getAdjacencyMatrix()[v][u] < distance[u]) {
                    distance[u] = distance[v] + graph.getAdjacencyMatrix()[v][u];
                    parent[u] = v;
                }
            }
        }
    }

    // Check for negative cycles. The relaxation action after n-1 times. If there is still an update to the vertex we have found a negative circle
    for (size_t u = 0; u < numVertices; ++u) {
        for (size_t v = 0; v < numVertices; ++v) {
            if (graph.getAdjacencyMatrix()[u][v] != 0 && distance[u] != maxValue &&
                distance[u] + graph.getAdjacencyMatrix()[u][v] < distance[v]) {
                return "Error: Graph contains negative cycle.";
            }
        }
    }

    // Create a stringstream to construct the string
    std::stringstream ss;

    // Print the shortest path from startVertex to endVertex
    ss << "Shortest path from vertex " << startVertex << " to vertex " << endVertex << ": ";
    if (distance[endVertex] == maxValue) {
        ss << "-1 (No path exists)";
    } else {
        size_t currentVertex = endVertex;
        while (currentVertex != startVertex) {
            ss << currentVertex << " <- ";
            currentVertex = static_cast<size_t>(parent[currentVertex]);
        }
        ss << startVertex;
    }

    return ss.str();
}

bool dfsUtil(const Graph& graph, size_t vertex, std::vector<bool>& visited, std::vector<bool>& inStack, std::vector<size_t>& cycleVertices, size_t parent) {
    // Mark the current vertex as visited and add it to the stack
    visited[vertex] = true;
    inStack[vertex] = true;

    const size_t numVertices = graph.getAdjacencyMatrix().size();
    // Traverse adjacent vertices
    for (size_t adjacentVertex = 0; adjacentVertex < numVertices; ++adjacentVertex) {
        if (graph.getAdjacencyMatrix()[vertex][adjacentVertex]) {
            // If the adjacent vertex is not visited, recursively call dfsUtil
            if (!visited[adjacentVertex]) {
                if (dfsUtil(graph, adjacentVertex, visited, inStack, cycleVertices, vertex)) {
                    // If a cycle is found, add the current vertex to the cycleVertices vector
                    cycleVertices.push_back(vertex);
                    return true;
                }
            } else if (inStack[adjacentVertex]) {
                // If the adjacent vertex is in the stack, it indicates a back edge (cycle)
                cycleVertices.push_back(adjacentVertex);
                cycleVertices.push_back(vertex);
                return true;
            }
        }
    }

    // Remove the current vertex from the stack
    inStack[vertex] = false;
    return false; // No cycle found in this traversal path
}

std::string isContainsCycle(const Graph& graph) {
    size_t numVertices = graph.getAdjacencyMatrix().size();
    std::vector<bool> visited(numVertices, false);
    std::vector<bool> inStack(numVertices, false);
    std::vector<size_t> cycleVertices;

    // Perform DFS traversal from each vertex to check for cycles
    for (size_t i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            if (dfsUtil(graph, i, visited, inStack, cycleVertices, SIZE_MAX)) {
                // If a cycle is found, construct the string representation of the cycle
                std::stringstream ss;
                ss << "Cycle detected: ";
                for (size_t i = 0; i < cycleVertices.size(); ++i) {
                    if (i > 0) {
                        ss << " <- ";
                    }
                    ss << cycleVertices[i];
                }
                return ss.str();
            }
        }
    }

    return "0";
}

std::string isBipartite(const Graph& graph) {
    size_t numVertices = graph.getAdjacencyMatrix().size();

    // Check if the graph has less than 2 vertices
    if (numVertices < 2) {return "0 (false)";}

    std::vector<int> color(numVertices, -1);
    std::unordered_set<size_t> partitionA, partitionB;

    for (size_t i = 0; i < numVertices; ++i) {
        if (color[i] == -1) {
            std::stack<size_t> stack;
            stack.push(i);
            color[i] = 0;
            partitionA.insert(i);

            while (!stack.empty()) {
                size_t currentVertex = stack.top();
                stack.pop();

                for (size_t adjacentVertex = 0; adjacentVertex < numVertices; ++adjacentVertex) {
                    if (graph.getAdjacencyMatrix()[currentVertex][adjacentVertex]) {
                        if (color[adjacentVertex] == -1) {
                            color[adjacentVertex] = 1 - color[currentVertex];
                            if (color[adjacentVertex] == 0) {
                                partitionA.insert(adjacentVertex);
                            } else {
                                partitionB.insert(adjacentVertex);
                            }
                            stack.push(adjacentVertex);
                        } else if (color[adjacentVertex] == color[currentVertex]) { //Two neighboring vertices have the same color
                            return "0 (false)";
                        }
                    }
                }
            }
        }
    }

    // If there are no edges, assign vertices to two partitions
    if (partitionA.empty() || partitionB.empty()) {
        partitionA.clear();
        partitionB.clear();
        for (size_t i = 0; i < numVertices; ++i) {
            if (i % 2 == 0) { //This is a simple way to partition the vertices when there are no edges in the graph.
                partitionA.insert(i);
            } else {
                partitionB.insert(i);
            }
        }
    }

    std::stringstream ss; //Printing the vertices that are divided into groups
    if (!partitionA.empty() && !partitionB.empty()) {
        ss << "Graph is bipartite: ";
        ss << "A={";
        bool firstVertexA = true;
        for (size_t vertex : partitionA) {
            if (!firstVertexA) {
                ss << ", ";
            }
            ss << vertex;
            firstVertexA = false;
        }
        ss << "} B={";
        bool firstVertexB = true;
        for (size_t vertex : partitionB) {
            if (!firstVertexB) {
                ss << ", ";
            }
            ss << vertex;
            firstVertexB = false;
        }
        ss << "}";
    } else {
        ss << "0 (false)";
    }

    return ss.str();
}

std::string bellmanFordShortestPath(const Graph& graph, size_t startVertex, size_t endVertex) {
    const int maxValue = std::numeric_limits<int>::max();
    const size_t numVertices = graph.getAdjacencyMatrix().size();
    std::vector<int> distance(numVertices, maxValue);
    std::vector<int> parent(numVertices, -1);

    distance[startVertex] = 0;

    for (size_t i = 0; i < numVertices - 1; ++i) {
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                if (graph.getAdjacencyMatrix()[u][v] != 0 && distance[u] != maxValue &&
                    distance[u] + graph.getAdjacencyMatrix()[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph.getAdjacencyMatrix()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycle
    for (size_t u = 0; u < numVertices; ++u) {
        for (size_t v = 0; v < numVertices; ++v) {
            if (graph.getAdjacencyMatrix()[u][v] != 0 && distance[u] != maxValue &&
                distance[u] + graph.getAdjacencyMatrix()[u][v] < distance[v]) {
                return "Error: Graph contains negative cycle.";
            }
        }
    }
    return "No negative cycle found.";
}

std::string negativeCycle(const Graph& graph) {
    if (!graph.hasNegativeWeights()){return "No negative cycle found.";}
    const size_t numVertices = graph.getAdjacencyMatrix().size();
    std::string result;

    // Run Bellman-Ford for each vertex
    for (size_t i = 0; i < numVertices; ++i) {
        result = bellmanFordShortestPath(graph, i, i); // Start and end vertices are the same
        if (result == "Error: Graph contains negative cycle.") {
            return "Graph contains negative cycle";
        }
    }

    return "No negative cycle found.";
}
    }
}