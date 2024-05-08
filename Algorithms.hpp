// 325483444 gidirabi111@gmail.com
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <vector>
#include <stack> 
#include "Graph.hpp"


using namespace std;
namespace ariel{

    class Algorithms
    {
        public:

            static bool dfs(const ariel::Graph &g, size_t v, std::vector<size_t> &prev, std::stack<size_t> &s);

            static bool isConnected(const Graph& graph);

            static string shortestPath(const Graph &graph, size_t start, size_t end);

            static bool isContainsCycle(const Graph &graph);

            static string isBipartite(const Graph& graph);

            static bool negativeCycle(const Graph& graph);
    };
}
#endif // ALGORITHMS_HPP
