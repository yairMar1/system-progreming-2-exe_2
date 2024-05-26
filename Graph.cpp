#include "Graph.hpp"
#include <vector>
#include <iostream>

using namespace std;
    
namespace ariel{

    // Constructor
    Graph::Graph(){}

    // Function to get the matrix
    const vector<vector<int>>& Graph::getAdjacencyMatrix() const {return adjacencyMatrix;}

    // Function to check if the graph is weighted (contains weights other than 0 and 1).
    bool Graph::isWeightedGraph() const {
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = 0; j < getAdjacencyMatrix().size(); ++j) {
                if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1) {
                    return true; // Found a weight other than 0 or 1
                }   
            }
        }  
        return false; // No weights other than 0 and 1 found
    }

    // Function to check if a square matrix is square (number of rows equals number of columns).
    bool Graph::isSquare(const vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        for (size_t i = 0; i < numRows; ++i) {
            if (matrix[i].size() != numRows) {
                return false; // Number of columns is not equal to the number of rows
            }
        }
        return true; // Number of rows and columns are equal
    }

    // Function to load a graph into the object.
    // The graph must be represented as a 2D vector of integers.
    void Graph::loadGraph(const vector<vector<int>>& graph) {
        if (!isSquare(graph)) {
            throw std::invalid_argument("Error: Graph size is not square."); // Throw a runtime_error exception
        }
        adjacencyMatrix = graph;
        if(adjacencyMatrix.size() == 0){throw std::invalid_argument("Error: It is impossible to infer things about the graph, because no vertices were inserted.");}
    }

    // Function to print the graph as a neighborhood matrix.
    void Graph::printGraph() const {
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = 0; j < getAdjacencyMatrix().size(); ++j) {cout << adjacencyMatrix[i][j] << " ";}
            cout << endl;
        }
    }

    // Function to check if the graph with negative weighted.
    bool Graph::hasNegativeWeights() const {
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = 0; j < getAdjacencyMatrix().size(); ++j) {
                if (adjacencyMatrix[i][j] < 0) {
                    return true; // Found a negative weight
                }
            }
        }
        return false; // No negative weights found
    }

    // Function to check if the graph is directed (symmetric)
    bool Graph::isDirected() const {
        // Check if the adjacency matrix is symmetric
        for (size_t i = 0; i < getAdjacencyMatrix().size(); ++i) {
            for (size_t j = i + 1; j < getAdjacencyMatrix().size(); ++j) {
                if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                    return true; // Graph is directed
                }
            }
        }
        return false; // Graph is undirected
    }


    //PART 2

    Graph Graph::operator+(const Graph &graph2){
        if(adjacencyMatrix.size() != graph2.getAdjacencyMatrix().size()){throw std::invalid_argument("Error: The matrices are not the same, in their dimensions");}
        
        Graph newGraph;
        size_t row = adjacencyMatrix.size();
        vector<vector<int>> newMatrix(row, vector<int>(row,0));

        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                newMatrix[i][j] = adjacencyMatrix[i][j] + graph2.getAdjacencyMatrix()[i][j];
            }
        }
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    Graph Graph::operator-(const Graph &graph2){
        if(adjacencyMatrix.size() != graph2.getAdjacencyMatrix().size()){throw std::invalid_argument("Error: The matrices are not the same, in their dimensions");}
        
        Graph newGraph;
        size_t row = adjacencyMatrix.size();
        vector<vector<int>> newMatrix(row, vector<int>(row,0));

        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                newMatrix[i][j] = adjacencyMatrix[i][j] - graph2.getAdjacencyMatrix()[i][j];
            }
        }
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    Graph& Graph::operator+=(const Graph &graph2){
        if(adjacencyMatrix.size() != graph2.getAdjacencyMatrix().size()){throw std::invalid_argument("Error: The matrices are not the same, in their dimensions");}
        
        *this = *this + graph2;
        return *this;
    }

    Graph& Graph::operator-=(const Graph &graph2){
        if(adjacencyMatrix.size() != graph2.getAdjacencyMatrix().size()){throw std::invalid_argument("Error: The matrices are not the same, in their dimensions");}
        
        *this = *this - graph2;
        return *this;
    }

    Graph& Graph::operator+(){
        return *this;
    }

    Graph& Graph::operator-(){
        return (*this) *= -1;
    }

    Graph Graph::operator*(int num){
        if(adjacencyMatrix.empty()){throw std::invalid_argument("Error: there is no edges in the graph");}

        Graph newGraph;
        size_t row = adjacencyMatrix.size();
        vector<vector<int>> newMatrix(row, vector<int>(row,0));

        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                newMatrix[i][j]  = adjacencyMatrix[i][j] * num;
            }
        }
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    Graph& Graph::operator++(){
        if(adjacencyMatrix.empty()){throw std::invalid_argument("Error: there is no edges in the graph");}

        size_t row = adjacencyMatrix.size();       
        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                if(adjacencyMatrix[i][j] != 0){
                   adjacencyMatrix[i][j] = adjacencyMatrix[i][j] + 1;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator++(int num){ // Postfix (g++) g = g + 1
     if(adjacencyMatrix.empty()){throw std::invalid_argument("Error: there is no edges in the graph");}

        Graph newGraph = *this;
        size_t row = adjacencyMatrix.size();
       
        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                if(adjacencyMatrix[i][j] != 0){
                   adjacencyMatrix[i][j] = adjacencyMatrix[i][j] + 1;
                }
            }
        }
        return newGraph;
    }

    Graph& Graph::operator--(){
        if(adjacencyMatrix.empty()){throw std::invalid_argument("Error: there is no edges in the graph");}

        size_t row = adjacencyMatrix.size();       
        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                if(adjacencyMatrix[i][j] != 0){
                   adjacencyMatrix[i][j] = adjacencyMatrix[i][j] - 1;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator--(int num){
        if(adjacencyMatrix.empty()){throw std::invalid_argument("Error: there is no edges in the graph");}

        Graph newGraph = *this;
        size_t row = adjacencyMatrix.size();
       
        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                if(adjacencyMatrix[i][j] != 0){
                   adjacencyMatrix[i][j] = adjacencyMatrix[i][j] - 1;
                }
            }
        }
        return newGraph;
    }

    Graph& Graph::operator*=(int num){
        if(adjacencyMatrix.empty()){throw std::invalid_argument("Error: there is no edges in the graph");}

        int row = adjacencyMatrix.size();
        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                adjacencyMatrix[i][j] = adjacencyMatrix[i][j] * num;
            }
        }
        return *this;
    }

    bool Graph::operator<(Graph &graph2){
    if(adjacencyMatrix == graph2.getAdjacencyMatrix()){return false;}

    size_t n1 = adjacencyMatrix.size();
    size_t n2 = graph2.getAdjacencyMatrix().size();

    if(n1 > n2){return false;}

    for(size_t i = 0; i <= n2 - n1; i++){
        for(size_t j = 0; j <= n2 - n1; j++){
            if(adjacencyMatrix[i][j] == graph2.getAdjacencyMatrix()[i][j]){
                bool match = true;
                for(size_t k = 0; k < n1; k++){
                    for(size_t l = 0; l < n1; l++){
                        if(adjacencyMatrix[k][l] != graph2.getAdjacencyMatrix()[i+k][j+l]){
                            match = false;
                            break;
                        }
                    }
                }
                if(match) return true;
            }
        }
    }
    return false;
}

bool Graph::operator>(Graph &graph2){
    return graph2 < *this;
}

bool Graph::operator==(Graph &graph2){
        if(adjacencyMatrix.size() != graph2.getAdjacencyMatrix().size()){return false;}

        size_t row = adjacencyMatrix.size();
        for (size_t i = 0; i < row; i++){
            for (size_t j = 0; j < row; j++){
                if(adjacencyMatrix[i][j] != graph2.getAdjacencyMatrix()[i][j]){return false;};
            }
        }
        return true;

        //return !(*this < graph2) && !(*this > graph2);
    }

    bool Graph::operator<=(Graph &graph2){
        return (*this < graph2) || (graph2 == *this);
    }

    bool Graph::operator>=(Graph &graph2){
        return graph2 <= *this;
    }

    Graph Graph::operator*(const Graph &graph2){
        if (adjacencyMatrix.size() != graph2.getAdjacencyMatrix().size()){throw std::invalid_argument("Error: The matrices are not the same, in their dimensions");}

        size_t n1 = adjacencyMatrix.size();
        size_t n2 = graph2.getAdjacencyMatrix().size();

        Graph newGraph; // Creating a new graph that we will return
        vector<vector<int>> newMatrix(n1, vector<int>(n1,0));

        for(size_t i = 0; i < n1; i++){
            for(size_t j = 0; j < n1; j++){
                for(size_t k = 0; k < n1; k++){
                    newMatrix[i][j] += adjacencyMatrix[i][k] * graph2.getAdjacencyMatrix()[k][j];
                }
            }
        }
        newGraph.loadGraph(newMatrix);
        return newGraph;
    }

    ostream &operator<<(ostream &os, const Graph &graph){
        size_t n1 = graph.getAdjacencyMatrix().size();

        for(size_t i = 0; i < n1; i++){
            os << "[";
            for(size_t j = 0; j < n1; j++){
                if(j == n1 - 1){os << graph.getAdjacencyMatrix()[i][j];}
                else{
                os << graph.getAdjacencyMatrix()[i][j] << ", ";
                }
            }
            os << "] " ;
            if (i != n1 -1){os << ", ";}
        }
        return os;
    }
};