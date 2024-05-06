#include "Graph.hpp"
#include <iostream>

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

void Graph::printGraph() const
{
    int n = adjacencyMatrix.size();
    int edgeCount = 0;
    for (unsigned long i = 0; i < n; ++i)
    {
        for (unsigned long j = 0; j < n; ++j)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                edgeCount++;
            }
        }
    }
    cout << "Graph with " << n << " vertices and " << edgeCount << " edges." << endl;
}

const vector<vector<int> >& Graph::getAdjacencyMatrix() const {
    return this->adjacencyMatrix;
}

// Getter for containNeg
bool Graph::containsNegative() const {
    return this->containNeg;
}
