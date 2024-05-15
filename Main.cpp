// 325483444 gidirabi111@gmail.com
#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

#define nl printf("\n");


int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout<<g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    nl

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout<<g3;           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]
    nl

    g1 *= -2;        // Multiply the graph by -2.
    cout<<g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
    nl

    g1 /= -2;

    ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
    cout<<g4;           // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]
    nl

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }


    // Perform multiple operations and display the changes
    cout << "\n\nOriginal g1:\n" << g1 << "\n\n";

    cout << "Is g1 connected? " << (Algorithms::isConnected(g1) ? "Yes" : "No") << "\n\n";

    ++g1;
    cout << "++g1:\n" << g1 << "\n\n";

    cout << "Is g1 bipartite? " << Algorithms::isBipartite(g1) << "\n\n";

    g1 = g1 + g2;
    cout << "g1 = g1 + g2:\n" << g1 << "\n\n";

    cout << "Does g1 contain a cycle? " << (Algorithms::isContainsCycle(g1) ? "Yes" : "No") << "\n\n";

    g1 *= 2;
    cout << "g1 *= 2:\n" << g1 << "\n\n";

    cout << "Does g1 contain a negative cycle? " << (Algorithms::negativeCycle(g1) ? "Yes" : "No") << "\n\n";

    g1 *= g2;
    cout << "g1 *= g2:\n" << g1 << "\n\n";

    cout << "Shortest path in g1 from 0 to 2: " << Algorithms::shortestPath(g1, 0, 2) << "\n\n";

    g1 /= 4;
    cout << "g1 /= 4:\n" << g1 << "\n\n";

    cout << "Is g1 still connected? " << (Algorithms::isConnected(g1) ? "Yes" : "No") << "\n\n";

    g2 *= 2;
    g1 += g2;
    cout << "g1 += g2*2:\n" << g1 << "\n\n";

    cout << "Does g1 now contain a cycle? " << (Algorithms::isContainsCycle(g1) ? "Yes" : "No") << "\n\n" << endl;
}
