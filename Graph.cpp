// 325483444 gidirabi111@gmail.com
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
    for (size_t i = 0; i < adjMatrix.size(); ++i)
    {
        const auto &row = adjMatrix[i];
        for (size_t j = 0; j < row.size(); ++j)
        {
            const auto &value = row[j];
            // Check for negative values
            if (value < 0)
            {
                containNeg = true;
            }
            // Check if diagonal elements are 0
            if (i == j && value != 0)
            {
                throw std::invalid_argument("Main diagonal elements must be 0");
            }
        }
    }

    this->adjacencyMatrix = adjMatrix;
}

string Graph::printGraph() const
{
    stringstream ss;
    int n = adjacencyMatrix.size();
    int m = (n > 0) ? adjacencyMatrix[0].size() : 0;
    for (unsigned long i = 0; i < n; ++i)
    {
        ss << "[";
        for (unsigned long j = 0; j < m; ++j)
        {
            ss << adjacencyMatrix[i][j];
            if (j != m - 1) {
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
    // Check if 'other' is a subgraph of 'this'
    if (this->isSubGraph(other)) {
        return true;
    }

    // If 'other' is not a subgraph of 'this' and 'this' is not a subgraph of 'other' and the graphs are not equal
    if (!other.isSubGraph(*this) && *this != other) {
        // If 'this' has more edges than 'other'
        if (this->edgeCount() > other.edgeCount()) {
            return true;
        }
        // If 'this' and 'other' have the same number of edges and the order of 'this''s adjacency matrix is greater than the order of 'other''s adjacency matrix
        else if (this->edgeCount() == other.edgeCount() && 
         (this->adjacencyMatrix.size() * this->adjacencyMatrix[0].size()) > 
         (other.adjacencyMatrix.size() * other.adjacencyMatrix[0].size())) {
            return true;
        }
    }

    return false;
}

bool Graph::operator>=(const Graph &other) {
    // If the graph is greater or equal to the other graph
    return (*this > other) || (*this == other);
}

bool Graph::operator<(const Graph &other) {
    if (other.isSubGraph(*this)) {
        return true;
    }

    if (!this->isSubGraph(other) && *this != other) {
        if (this->edgeCount() < other.edgeCount()) {
            return true;
        }
        else if (this->edgeCount() == other.edgeCount() && 
         (this->adjacencyMatrix.size() * this->adjacencyMatrix[0].size()) < 
         (other.adjacencyMatrix.size() * other.adjacencyMatrix[0].size())) {
            return true;
        }
    }

    return false;
}

bool Graph::operator<=(const Graph &other) {
    return (*this < other) || (*this == other);
}

bool Graph::operator==(const Graph &other) {
    //Check that both the graphs are the same size by rows and collums
    if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size() 
            || this->adjacencyMatrix[0].size() != other.adjacencyMatrix[0].size()){
        return false;
    }

    //If the size is the same, check if all the values in the matrix are the same
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            if(this->adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]){
                return false;
            }
        }
    }

    return true;

}

bool Graph::operator!=(const Graph &other) {

    // bool check = false;
    // //Checks if all the values in the matrix are the same
    // for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
    //     for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
    //         if(!check){
    //             if(this->adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]){
    //                 check = true;
    //             }
    //         }
    //     }
    // }

    // //If all the values are the same, check if the size of the matrix is the same
    // if(!check){
    //     if (this->adjacencyMatrix.size() != other.adjacencyMatrix.size() 
    //             || this->adjacencyMatrix[0].size() != other.adjacencyMatrix[0].size()){
    //         return true;
    //     }
    // }

    // return false;

    //the opposite of ==
    return !(*this == other);
}

Graph& Graph::operator++() {
    //Increment all the values in the matrix by 1
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            this->adjacencyMatrix[i][j]++;
        }
    }

    return *this;
}

Graph& Graph::operator--() {
    //reduce all the values in the matrix by 1
    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            this->adjacencyMatrix[i][j]--;
        }
    }

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
    // Implement the unary minus operator
    // Return a copy of the current graph with negated edge weights
    Graph negated = *this;
    for (size_t i = 0; i < negated.adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < negated.adjacencyMatrix[i].size(); ++j) {
            negated.adjacencyMatrix[i][j] = -negated.adjacencyMatrix[i][j];
        }
    }

    return negated;
}

Graph Graph::operator/(int scalar) {
    if(scalar == 0){
        throw invalid_argument("cannot divide by zero.");
    }

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
    if(scalar == 0){
        throw invalid_argument("cannot divide by zero.");
    }

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

Graph Graph::operator*=(const Graph &other) {
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
    this->adjacencyMatrix = resultGraph.adjacencyMatrix;

    setDiagonalToZero(*this);

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

    setDiagonalToZero(resultGraph);

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

bool Graph::isSubGraph(const Graph &other) const {
    // Check if 'other' is smaller or equal in size
    if (other.adjacencyMatrix.size() > this->adjacencyMatrix.size() ||
        other.adjacencyMatrix[0].size() > this->adjacencyMatrix[0].size()) {
        return false;
    }

    // Check if all edges in 'other' also exist in 'this'
    for (size_t i = 0; i < other.adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < other.adjacencyMatrix[i].size(); ++j) {
            // If 'other' has an edge that 'this' does not, or if the edge in 'other' has a higher weight, return false
            if ((other.adjacencyMatrix[i][j] > 0 && this->adjacencyMatrix[i][j] == 0) ||
                (other.adjacencyMatrix[i][j] > this->adjacencyMatrix[i][j])) {
                return false;
            }
        }
    }

    return true;
}

int Graph::edgeCount() const {
    int count = 0;

    for (size_t i = 0; i < this->adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < this->adjacencyMatrix[i].size(); ++j) {
            if (this->adjacencyMatrix[i][j] > 0) {
                count++;
            }
        }
    }

    return count;
}

void Graph::setDiagonalToZero(Graph &graph) {
    for (size_t i = 0; i < graph.adjacencyMatrix.size(); ++i) {
        graph.adjacencyMatrix[i][i] = 0;
    }
}