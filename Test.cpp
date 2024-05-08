// 325483444 gidirabi111@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

//////////// Added Graph tests ///////////

TEST_CASE("Comprehensive graph test with different sizes")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 0, 1, 1},
        {2, 0, 2, 1, 1},
        {0, 2, 0, 1, 1}};
    g3.loadGraph(graph3);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 2},
        {2, 0}};
    g4.loadGraph(graph4);

    // Test printing
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    CHECK(g2.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    CHECK(g3.printGraph() == "[0, 2, 0, 1, 1]\n[2, 0, 2, 1, 1]\n[0, 2, 0, 1, 1]");
    CHECK(g4.printGraph() == "[0, 2]\n[2, 0]");

    // Test arithmetic operations
    g1 += g2;
    CHECK(g1.printGraph() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]");
    g1 -= g2;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
    g1 *= 2;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    g1 /= 2;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");

    // Test comparison operators
    CHECK(g1 == g1);
    CHECK(g1 != g2);
    CHECK(g1 != g3);
    CHECK(g1 != g4);
    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK(g2 > g1);
    CHECK(g2 >= g1);
    CHECK(g3 != g1);
    CHECK(g3 != g2);
    CHECK(g3 != g4);
    CHECK(g4 != g1);
    CHECK(g4 != g2);
    CHECK(g4 != g3);
}

TEST_CASE("Test graph addition with different sizes")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 + g2);
}

TEST_CASE("Test graph subtraction with different sizes")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 - g2);
}

TEST_CASE("Test graph multiplication with scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1 *= 2;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph division with scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    g1 /= 2;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph division by zero")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    CHECK_THROWS(g1 /= 0);
}

TEST_CASE("Test graph unary plus operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph unary minus operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
}

TEST_CASE("Test graph self addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1 += g1;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph self subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    g1 -= g1;
    CHECK(g1.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Test graph self multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1 *= g1;
    CHECK(g1.printGraph() == "[1, 0, 1]\n[0, 2, 0]\n[1, 0, 1]");
}

TEST_CASE("Test graph self division")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    g1 /= 2;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph self division by zero")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);

    CHECK_THROWS(g1 /= 0);
}

TEST_CASE("Test graph comparison operators")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g3.loadGraph(graph3);

    CHECK(g1 == g2);
    CHECK(g1 != g3);
    CHECK(g1 < g3);
    CHECK(g1 <= g2);
    CHECK(g3 > g1);
    CHECK(g3 >= g1);
    g3 /= 2;
    CHECK(g1 == g3);
}

TEST_CASE("Test graph increment and decrement operators")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ++g1;
    CHECK(g1.printGraph() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");

    --g1;
    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph arithmetic operators")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1 += g1;
    CHECK(g1.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");

    g1 -= g1;
    CHECK(g1.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");

    g1 *= 2;
    CHECK(g1.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");

    g1 /= 2;
    CHECK(g1.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
}

TEST_CASE("Test graph output operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    CHECK(g1.printGraph() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

/////////// Origin Graph tests ///////////
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g3.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g2 * g1); 
    CHECK_NOTHROW(g1 * g2); 

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}