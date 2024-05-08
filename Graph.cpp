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
    // Check if the graphs have the same size
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw invalid_argument("not same size.");
    }

    Graph resultGraph;
    resultGraph.adjacencyMatrix.resize(this->adjacencyMatrix.size(), std::vector<int>(this->adjacencyMatrix.size(), 0));

    // Add the edge weights of the two graphs element-wise
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            resultGraph.adjacencyMatrix[i][j] = this->adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
        }
    }

    return resultGraph;
}

Graph& Graph::operator+=(const Graph &other) {
    // Check if the graphs have the same size
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw invalid_argument("not same size.");
    }

    // Add the edge weights of the two graphs element-wise
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            this->adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
        }
    }

    return *this;
}

Graph Graph::operator+() {
    // Implement the unary plus operator
    // Return a copy of the current graph with the same edge weights
    return *this;
}

Graph Graph::operator-(const Graph &other) {
    // Check if the graphs have the same size
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw invalid_argument("not same size.");
    }

    Graph resultGraph;
    resultGraph.adjacencyMatrix.resize(this->adjacencyMatrix.size(), std::vector<int>(this->adjacencyMatrix.size(), 0));

    // Remove the edge weights of the two graphs element-wise
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            resultGraph.adjacencyMatrix[i][j] = this->adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
        }
    }

    return resultGraph;
}

Graph& Graph::operator-=(const Graph &other) {
    // Check if the graphs have the same size
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
        throw invalid_argument("not same size.");
    }

    // Remove the edge weights of the two graphs element-wise
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            this->adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
        }
    }

    return *this;
}

Graph Graph::operator-() {
    // Implement the unary plus operator
    // Return a copy of the current graph with the same edge weights
    return *this;
}

Graph Graph::operator/(int scalar) {
    Graph resultGraph;
    resultGraph.adjacencyMatrix.resize(this->adjacencyMatrix.size(), std::vector<int>(this->adjacencyMatrix.size(), 0));

    // Remove the edge weights of the two graphs element-wise
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            resultGraph.adjacencyMatrix[i][j] = this->adjacencyMatrix[i][j] / scalar;
        }
    }

    return resultGraph;
}

Graph& Graph::operator/=(int scalar) {
    // Divide the edge weights of the graph by the scalar
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            this->adjacencyMatrix[i][j] /= scalar;
        }
    }

    return *this;
}

Graph& Graph::operator*=(int scalar) {
    // Multiply the edge weights of the graph by the scalar
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            this->adjacencyMatrix[i][j] *= scalar;
        }
    }

    return *this;
}

Graph Graph::operator*(const Graph &other) {
    // Check if the number of columns in the first graph is equal to the number of rows in the second graph
    if (this->adjacencyMatrix[0].size() != other.adjacencyMatrix.size()) {
        throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    Graph resultGraph;
    resultGraph.adjacencyMatrix.resize(this->adjacencyMatrix.size(), std::vector<int>(other.adjacencyMatrix[0].size(), 0));

    // Multiply the adjacency matrices of the two graphs
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < other.adjacencyMatrix[0].size(); ++j) {
            for (size_t k = 0; k < this->adjacencyMatrix[0].size(); ++k) {
                resultGraph.adjacencyMatrix[i][j] += this->adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
            }
        }
    }

    return resultGraph;
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