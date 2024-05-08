#include "Graph.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace ariel;

Graph::Graph() : containNeg(false) {} // Initialize containNeg to false in the constructor
Graph::~Graph() {}


void Graph::loadGraph(const vector<vector<int> > &adjMatrix)
{
    // Validate the adjacency matrix
    int n = adjMatrix.size();
    for (const auto &row : adjMatrix)
    {
        if (row.size() != n)
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

         // Check for negative values
        for (const auto &value : row)
        {
            if (value < 0)
            {
                containNeg = true;
                break;
            }
        }
    }

    this->adjacencyMatrix = adjMatrix;
}

// void Graph::printGraph() const
// {
//     int n = adjacencyMatrix.size();
//     int edgeCount = 0;
//     for (unsigned long i = 0; i < n; ++i)
//     {
//         for (unsigned long j = 0; j < n; ++j)
//         {
//             if (adjacencyMatrix[i][j] != 0)
//             {
//                 edgeCount++;
//             }
//         }
//     }
//     cout << "Graph with " << n << " vertices and " << edgeCount << " edges." << endl;
// }

string Graph::printGraph() const
{
    stringstream ss;
    int n = adjacencyMatrix.size();
    for (unsigned long i = 0; i < n; ++i)
    {
        ss << "[";
        for (unsigned long j = 0; j < n; ++j)
        {
            ss << adjacencyMatrix[i][j];
            if (j != n - 1) {
                ss << ", ";
            }
        }
        ss << "]";
        if (i != n - 1) {
            ss << "\n";
        }
    }
    return ss.str();
}

const vector<vector<int> >& Graph::getAdjacencyMatrix() const {
    return this->adjacencyMatrix;
}

// Getter for containNeg
bool Graph::containsNegative() const {
    return this->containNeg;
}

bool Graph::operator>(const Graph &other) {
    // Implement the less than comparison logic
    return false;
}

bool Graph::operator>=(const Graph &other) {
    // Implement the greater than or equal to comparison logic
    return false;
}

bool Graph::operator<(const Graph &other) {
    // Implement the less than comparison logic
    return false;
}

bool Graph::operator<=(const Graph &other) {
    // Implement the less than or equal to comparison logic
    return false;
}

bool Graph::operator==(const Graph &other) {
    // Implement the equal to comparison logic
    return false;
}

bool Graph::operator!=(const Graph &other) {
    // Implement the not equal to comparison logic
    return false;
}

Graph& Graph::operator++() {
    // Implement the increment operator
    return *this;
}

Graph& Graph::operator--() {
    // Implement the decrement operator
    return *this;
}

Graph Graph::operator+(const Graph &other) {
    // Implement the addition operator
    Graph resultGraph;
    // Add the edge weights of the two graphs element-wise
    // Ensure that the graphs have the same size before performing addition
    return resultGraph;
}

Graph& Graph::operator+=(const Graph &other) {
    // Implement the addition assignment operator
    // Add the edge weights of the input graph to the current graph
    return *this;
}

Graph Graph::operator+() {
    // Implement the unary plus operator
    // Return a copy of the current graph with the same edge weights
    return *this;
}

Graph Graph::operator-(const Graph &other) {
    // Implement the addition operator
    Graph resultGraph;
    // Add the edge weights of the two graphs element-wise
    // Ensure that the graphs have the same size before performing addition
    return resultGraph;
}

Graph& Graph::operator-=(const Graph &other) {
    // Implement the addition assignment operator
    // Add the edge weights of the input graph to the current graph
    return *this;
}

Graph Graph::operator-() {
    // Implement the unary plus operator
    // Return a copy of the current graph with the same edge weights
    return *this;
}

Graph Graph::operator/(int scalar) {
    // Implement the addition operator
    Graph resultGraph;
    // Add the edge weights of the two graphs element-wise
    // Ensure that the graphs have the same size before performing addition
    return resultGraph;
}

Graph& Graph::operator/=(int scalar) {
    // Implement the addition assignment operator
    // Add the edge weights of the input graph to the current graph
    return *this;
}

Graph& Graph::operator*=(int scalar) {
    // Implement the scalar multiplication operator
    return *this;
}

Graph Graph::operator*(const Graph &other) {
    // Implement the graph multiplication operator
    return Graph();
}


ostream& ariel::operator<<(ostream &os, const ariel::Graph &graph) {
    const vector<vector<int>>& matrix = graph.getAdjacencyMatrix();
    for (size_t i = 0; i < matrix.size(); ++i) {
        os << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            os << matrix[i][j];
            if (j != matrix[i].size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        if (i != matrix.size() - 1) {
            os << ", ";
        }
    }
    return os;
}
