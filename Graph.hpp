#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>

using namespace std;

namespace ariel{

class Graph{

    private:
        vector<vector<int>> adjacencyMatrix;

    public:
        // Constructor
        Graph();

        // Function to get the matrix
        const vector<vector<int>> &getAdjacencyMatrix() const;

        // Function to check if the graph is weighted (contains weights other than 0 and 1).
        bool isWeightedGraph() const;

        // Function to check if a square matrix is square (number of rows equals number of columns).
        bool isSquare(const vector<vector<int>> &matrix);

        // Function to load a graph into the object.
        // The graph must be represented as a 2D vector of integers.
        void loadGraph(const vector<vector<int>> &graph);

        // Function to print the graph as a neighborhood matrix.
        void printGraph() const;

        // Function to check if the graph with negative weighted.
        bool hasNegativeWeights() const;

        // Function to check if the graph is directed (symmetric)
        bool isDirected() const;

        // PART 2

        // Adding the values of two graphs, we get a new matrix. New edges may have been added or removed.
        Graph operator+ (const Graph &graph2);

        // subtraction the values of two graphs, we get a new matrix. New edges may have been added or removed.
        Graph operator- (const Graph &graph2);

        // Graph addition, we will update the graph that activated the function. and we will get a reference to the same graph (because there is no need to copy the graph unnecessarily)Graph addition/subtraction, we will update the graph that activated the function. and we will get a reference to the same graph (because there is no need to copy the graph unnecessarily)
        Graph& operator+= (const Graph &graph2);

        // Graph subtraction, we will update the graph that activated the function. and we will get a reference to the same graph (because there is no need to copy the graph unnecessarily)
        Graph& operator-= (const Graph &graph2);

        // Unary addition,   
        Graph& operator+ ();

        // unary subtraction
        Graph& operator- ();

        // Graph h = (Graph)g * 5;
        Graph operator* (int num);

        // increasing the graph by 1 first and then returninig it
        Graph& operator++ (); // Prefix (++g)

        // return the graph and then increasing it by 1
        Graph operator++ (int num); // Postfix (g++)

        //  Prefix (--g)
        Graph& operator-- ();

        //  Postfix (g--)
        Graph operator-- (int num);

        // multiplying the sides of the graph by a scalar (g *= 5;)
        Graph& operator*= (int num);
        
        // Boolean functions that define a relationship between graphs
        // A graph is identical only if its representation matrix is identical. A graph is smaller than its member only if it is contained in it
        bool operator< ( Graph &graph2);

        bool operator> (Graph &graph2);

        bool operator== ( Graph &graph2);

        bool operator<= ( Graph &graph2);

        bool operator>= ( Graph &graph2);

        // A function that defines multiplication of graphs, and returns a new graph
        Graph operator* (const Graph &graph2);

        // This function implements the print operator
        friend ostream& operator<< (ostream& os, const Graph &graph);

    };
}

#endif // GRAPH_HPP
