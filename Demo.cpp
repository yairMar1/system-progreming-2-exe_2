#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace ariel;
using namespace std;

int main(){
    
    Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
        
    g.loadGraph(graph); // Load the graph to the object.
    cout << "****************************************" << endl;
    cout << "Graph 1" << endl << endl;
    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << Algorithms::negativeCycle(g) << endl;

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.
    cout << "****************************************" << endl;
    cout << "Graph 2" << endl << endl;
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::negativeCycle(g) << endl;

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};

    g.loadGraph(graph3); // Load the graph to the object.
    cout << "****************************************" << endl;
    cout << "Graph 3" << endl << endl;
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
    cout << Algorithms::negativeCycle(g) << endl;

    vector<vector<int>> graph5 = {
    {0, 1, 0, 0, 0},
    {-1, 0, 1, 0, 0},
    {0, -1, 0, 1, 0},
    {0, 0, -1, 0, 1},
    {-5, 0, 0, -1, 0}};

    g.loadGraph(graph5); 
    cout << "****************************************" << endl;
    cout << "Graph 5" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 0, 6) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl; 

     vector<vector<int>> graph6 = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}};

    g.loadGraph(graph6); 
    cout << "****************************************" << endl;
    cout << "Graph 6" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 3, 0) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl; 

    vector<vector<int>> graph7 = {
         {0, 1, 2, 0, 0},
         {1, 0, 3, 0, 0},
         {2, 3, 0, -4, 0},
         {0, 0, -4, 0, 5},
         {0, 0, 0, 5, 0}};

    g.loadGraph(graph7); 
    cout << "****************************************" << endl;
    cout << "Graph 7" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 1, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl;    
    
    vector<vector<int>> graph8 = {
    {0, 2, 3, 0, 0},
    {-2, 0, 0, 0, 0},
    {3, 0, 0, -1, 0},
    {0, 0, -1, 0, 4},
    {0, 0, 0, -3, 0}};

    g.loadGraph(graph8); 
    cout << "****************************************" << endl;
    cout << "Graph 8" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 1, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl;

    vector<vector<int>> graph9 = {{0}};

    g.loadGraph(graph9); 
    cout << "****************************************" << endl;
    cout << "Graph 9" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 0, 0) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl;

    vector<vector<int>> graph11 = {
        {0,0},
        {0,0}};

    g.loadGraph(graph11); 
    cout << "****************************************" << endl;
    cout << "Graph 11" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 0, 1) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl;

    vector<vector<int>> graph12 = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph12); 
    cout << "****************************************" << endl;
    cout << "Graph 12" << endl << endl;
    g.printGraph();                                    
    cout << endl;
    cout << Algorithms::isConnected(g) << endl;       
    cout << Algorithms::shortestPath(g, 1, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        
    cout << Algorithms::negativeCycle(g) << endl;

    vector<vector<int>> graph10 = {};
 
    cout << "****************************************" << endl;
    cout << "Graph 10" << endl << endl;
     try{
        g.loadGraph(graph10);
    }
    catch (const std::invalid_argument &e){
        cout << e.what() << endl; // Should print: "Error: It is impossible to infer things about the graph, because no vertices were inserted."
    }                                      
    
    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};

    cout << "****************************************" << endl;
    cout << "Graph 4" << endl << endl;
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }   
return 0;
}
