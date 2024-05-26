#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace ariel;
using namespace std;

int main(){
    
    Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout<<g1 << endl; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.
    cout << "**************" << endl;
    cout << g1 << endl;
    cout << endl;
    cout << g2 << endl;
    cout << endl;
    cout << "this graph is aresult of the addition of the two graphs. the form is: (g3 = g1 + g2)" << endl << endl;
    
    Graph g3 = g1 + g2; // Add the two graphs together.
    cout << g3 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is aresult of the subtraction of the two graphs. the form is: (g4 = g1 - g2)" << endl << endl;
    cout << g1 << endl;
    cout << endl;
    cout << g2 << endl;
    cout << endl;
    Graph g4 = g1 - g2; // Add the two graphs together.
    cout << g4 << endl;
    cout << endl;

    cout << "**************" << endl;
    g1 += g2; // Add the two graphs together.
    cout << "this graph is aresult of the addition of the two graphs. the form is: (g1 += g2)" << endl << endl;
    cout << g1 << endl;
    cout << endl;

    cout << "**************" << endl;
    cout << "this graph is aresult of the subtraction of the two graphs. the form is: (g1 -= g2)" << endl << endl;
    
    g1 -= g2; // Add the two graphs together.
    cout << g1 << endl;
    cout << endl;
    
    cout << "**************" << endl;
    cout << "this graph is a result of unari adding. the form is: (g1 = +g1)" << endl << endl;
    
    g1 = +g1;
    cout << g1 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of unari subtraction. the form is: (g1 = -g1)" << endl << endl;
    
    g1 = -g1;
    cout << g1 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: g1++" << endl << endl;
    
    cout << g1++ << endl; // There will be no change in the current printing, only in the next one
    cout << endl;
    cout << g1 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: ++g1" << endl << endl;
    
    g1.loadGraph(graph);
    cout << g1 << endl;
    cout << endl;
    cout << (++g1) << endl; // The change will be in the current printing
    cout << endl;
    cout << g1 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: g1--" << endl << endl;
    
    g1.loadGraph(graph);
    cout << g1 << endl;
    cout << endl;
    cout << (g1--) << endl; // There will be no change in the current printing, only in the next one
    cout << endl;
    cout << g1 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: --g1" << endl << endl;

    g1.loadGraph(graph);
    cout << g1 << endl;
    cout << endl;
    cout << (--g1) << endl; // The change will be in the current printing
    cout << endl;
    cout << g1 << endl;
    cout << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: g1 *= 2" << endl << endl;

    g1.loadGraph(graph);
    cout << g1 << endl;
    cout << endl;
    g1 *= -2;
    cout << g1 << endl;
    cout << "**************" << endl;
    cout << "this graph ia a result of the form: h = g * 5" << endl << endl;
    g1.loadGraph(graph);
    cout << g1 << endl;
    cout << endl;
    Graph h = g1 * 5;
    cout << h << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: g1 < g2" << endl << endl;
    g1.loadGraph(graph);
    cout << g1 << endl;
    cout << endl;

    g2.loadGraph(weightedGraph);
    cout << g2 << endl;
    cout << endl;

    cout << "g1 < g2 " <<(g1 < g2) << endl << endl;
    cout << "**************" << endl;
    cout << g1 << endl;
    cout << endl;
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g2.loadGraph(graph4);
    cout << g2 << endl;
    cout << endl;

    cout << "g1 < g2 " << (g1 < g2) << endl;
    cout << "g1 > g2 " <<(g1 > g2) << endl;
    cout << "**************" << endl;
    cout << "this graph is a result of the form: g1 == g2" << endl << endl;
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph5);
    cout << g1 << endl;
    cout << endl;

    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph3);
    cout << g2 << endl;
    cout << endl;

    cout << "equal ? " << (g1 == g2) << endl;
    cout << "g1 < g2 " << (g1 < g2) << endl;
    cout << "g1 > g2 " << (g1 > g2) << endl;

    cout << endl;
    cout << g1 << endl;
    cout << endl;
    vector<vector<int>> graph6 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g2.loadGraph(graph6);
    cout << g2 << endl;
    cout << endl;

    cout << "equal ? " << (g1 == g2) << endl << endl;

    cout << "this graph is a result of the form: g1 <= g2" << endl;
    cout << g1 << endl;
    cout << endl;
    vector<vector<int>> graph7 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 0, 1, 0}};
    g2.loadGraph(graph7);
    cout << g2 << endl;
    cout << endl;

    cout << "g1 <= g2 " << (g1 <= g2) << endl;
    cout << "g1 >= g2 " << (g1 >= g2) << endl;
    cout << "equal ? " << (g1 == g2) << endl;
    cout << "**************" << endl;
    cout << endl;
    
    cout << "this graph is a result of the form:g = g1 * g2" << endl;
    cout << g1 << endl;
    cout << endl;

     vector<vector<int>> graph9 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g2.loadGraph(graph9);
    cout << g2 << endl;
    cout << endl;

    Graph g = g1 * g2;
    cout << g << endl;
    cout << "**************" << endl;

    cout << g1 << endl;
    cout << endl;

    vector<vector<int>> graph10 = {
            {0, -3, 4},
            {2, 0, 1},
            {7, 1, 0}};
    g2.loadGraph(graph10);
    cout << g2 << endl;
    cout << endl;

    Graph g11 = g1 * g2;
    cout << g11 << endl;
    cout << "**************" << endl;

    cout << g1 << endl;
    cout << endl;

    vector<vector<int>> graph11 = {
            {0, 1, 0, 1},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {0, 1, 0, 0}};

    g2.loadGraph(graph11);
    cout << g2 << endl;
    cout << endl;
    try{
    Graph g12 = g1 * g2;
    }
    catch (const std::invalid_argument &e){
        cout << e.what() << endl;
    }

    cout << "**************" << endl;

    
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    Graph g5;
    g5.loadGraph(graph2);
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
    }


return 0;
}
