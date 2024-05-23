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

        // A function that operates a graph on another graph, we will add the second to the first
        Graph& operator+ (const Graph &graph2);

        // Add Unri
        Graph& operator+ ();

        // A function that operates a graph on another graph, we will subtract the second from the first
        Graph& operator- (const Graph &graph2);

        // Unary subtraction
        Graph& operator- ();

        // A function that activates a graph, we will add a number to each edge in the graph
        Graph& operator+= (int n);

        // A function that activates a graph, a number is subtracted from each edge in the graph
        Graph& operator-= (int n);

        bool operator> (const Graph &graph2);//TO DO

        bool operator< (const Graph &graph2);//TO DO

        // A function that checks if two graphs are identical (dimension, edges, and weights of edges)
        bool operator== (const Graph &graph2);

        Graph& operator++ ();

        Graph& operator-- ();

        friend Graph& operator* (Graph &graph, int n);
        


    };
}

#endif // GRAPH_HPP
