#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == "1 (true)");

    std::vector<std::vector<int>> graph11 = {
        {0,0},
        {0,0}};
    g.loadGraph(graph11);
    CHECK(ariel::Algorithms::isConnected(g) == "0 (false)");

    std::vector<std::vector<int>> graph9 = {
        {0}};
    g.loadGraph(graph9);
    CHECK(ariel::Algorithms::isConnected(g) == "1 (true)");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == "0 (false)");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "Shortest path from vertex 0 to vertex 2: 2 <- 1 <- 0");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 2) == "At least one of the vertices you entered is not in the graph");

    vector<vector<int>> graph6 = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph(graph6); 
    CHECK(ariel::Algorithms::shortestPath(g, 3, 0) == "Shortest path from vertex 3 to vertex 0: 0 <- 1 <- 3");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 4) == "At least one of the vertices you entered is not in the graph");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "Shortest path from vertex 0 to vertex 4: -1 (No path exists)");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "At least one of the vertices you entered is not in the graph");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "Shortest path from vertex 1 to vertex 3: 3 <- 2 <- 1");

    std::vector<std::vector<int>> graph9 = {
        {0}};
    g.loadGraph(graph9);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "Shortest path from vertex 0 to vertex 0: 0");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Cycle detected: 0 <- 1 <- 0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Cycle detected: 0 <- 1 <- 0");

    vector<vector<int>> graph7 = {
         {0, 3, 2, 0, 0},
         {0, 0, 4, 0, 0},
         {-2, 3, 0, 4, 0},
         {0, 0, -4, 0, 15},
         {0, 0, 0, 5, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "Cycle detected: 0 <- 2 <- 1 <- 0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "Graph is bipartite: A={2, 0} B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0 (false)");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0 (false)");

    vector<vector<int>> graph6 = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph(graph6);

    CHECK(ariel::Algorithms::isBipartite(g) == "Graph is bipartite: A={3, 0} B={2, 1}");

    vector<vector<int>> graph8 = {
    {0, 2, 3, 0, 0},
    {-2, 0, 0, 0, 0},
    {3, 0, 0, -1, 0},
    {0, 0, -1, 0, 4},
    {0, 0, 0, -3, 0}};
    g.loadGraph(graph8);

    CHECK(ariel::Algorithms::isBipartite(g) == "Graph is bipartite: A={3, 0} B={4, 2, 1}");

    vector<vector<int>> graph9 = {{0}};
    g.loadGraph(graph9);

    CHECK(ariel::Algorithms::isBipartite(g) == "0 (false)");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    std::vector<std::vector<int>> graph10 = {};
    CHECK_THROWS(g.loadGraph(graph10));
}
TEST_CASE("Test negativeCycle in graph")
{
    ariel::Graph g;
    vector<vector<int>> graph5 = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph(graph5);
    
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle found.");

    vector<vector<int>> graph8 = {
    {0, 2, 3, 0, 0},
    {-2, 0, 0, 0, 0},
    {3, 0, 0, -1, 0},
    {0, 0, -1, 0, -4},
    {0, 0, 0, -3, 0}};
    g.loadGraph(graph8);

    CHECK(ariel::Algorithms::negativeCycle(g) == "Graph contains negative cycle");
}

