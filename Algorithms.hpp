#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <vector>
#include <iostream>
#include "Graph.hpp"

namespace ariel{
    namespace Algorithms{
// Perform BFS from a starting vertex, To know if the graph is connected
bool bfs(const Graph& graph, int startVertex);

// The function runs bfs on all vertices if the graph is directed (otherwise we run bfs once)
std::string isConnected(const Graph& graph);

std::string shortestPath(const Graph& graph, size_t startVertex, size_t endVertex);

bool dfsUtil(const Graph& graph, size_t vertex, std::vector<bool>& visited, std::vector<bool>& inStack, std::vector<size_t>& cycleVertices, size_t parent);

std::string isContainsCycle(const Graph& graph);

std::string isBipartite(const Graph& graph);

std::string bellmanFordShortestPath(const Graph& graph, size_t startVertex, size_t endVertex);

std::string negativeCycle(const Graph& graph);
    }
}
#endif // ALGORITHMS_HPP