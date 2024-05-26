#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

#include <sstream>

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    std::ostringstream oss;
    oss << g3;
    std::string printedGraph = oss.str();
    CHECK(printedGraph == "[0, 2, 1], [2, 0, 3], [1, 3, 0]");

    std::ostringstream os1;
    g1 = +g1;
    os1 << g1;
    CHECK(os1.str() == "[0, 1, 0], [1, 0, 1], [0, 1, 0]");
    
    std::ostringstream os2;
    g1 = -g1;
    os2 << g1;
    CHECK(os2.str() == "[0, -1, 0], [-1, 0, -1], [0, -1, 0]");

    std::ostringstream os3;
    ariel::Graph g4  = g1 - g2;
    os3 << g4;
    CHECK(os3.str() == "[0, -2, -1], [-2, 0, -3], [-1, -3, 0]");

}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    std::ostringstream oss;
    oss << g4;
    std::string printedGraph = oss.str();

    // Compare the printed output with the expected string
    CHECK(printedGraph == "[1, 0, 2], [1, 3, 1], [1, 0, 2]");}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}
TEST_CASE("Comparison Operations")
{
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph);

    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph);

    CHECK((g1 < g2) == false);
    CHECK((g1 > g2) == false);
    CHECK((g1 == g2) == false);
    CHECK((g1 <= g2) == false);
    CHECK((g1 >= g2) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g2.loadGraph(graph4);

    CHECK((g1 < g2) == true);
    CHECK((g1 > g2) == false);
    CHECK((g1 == g2) == false);
    CHECK((g1 <= g2) == true);
    CHECK((g1 >= g2) == false);

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph5);

    CHECK((g1 < g2) == false);
    CHECK((g1 > g2) == false);
    CHECK((g1 == g2) == true);
    CHECK((g1 <= g2) == true);
    CHECK((g1 >= g2) == true);

    vector<vector<int>> graph6 = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}};
    g2.loadGraph(graph6);

    CHECK((g1 < g2) == false);
    CHECK((g1 > g2) == false);
    CHECK((g1 == g2) == false);
    CHECK((g1 <= g2) == false);
    CHECK((g1 >= g2) == false);

}