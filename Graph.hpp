#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Graph {
        // we made numVertices as size_t because it will never be negative
        // and also the vector constructor takes size_t as an argument for the size
    private:
        vector<vector<int> > adjacencyMatrix;
        bool containNeg; // Declare containNeg here

    public:
        Graph();
        ~Graph();
        void loadGraph(const vector<vector<int> > &matrix);
        void printGraph() const;

        const vector<vector<int> >& getAdjacencyMatrix() const;
        bool containsNegative() const; // Declare a getter for containNeg

    };
}
#endif