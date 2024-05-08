// 325483444 gidirabi111@gmail.com
#include "Algorithms.hpp"
#include <queue>
#include <stack>
#include <limits> // for INT_MAX
#include <sstream>


using namespace std;
using namespace ariel;

/**
 * This function performs a Depth-First Search (DFS) on a graph starting from a vertex v.
 * It uses a stack to keep track of the vertices to be visited and a vector to keep track of the parent of each vertex.
 * It returns true if it finds a cycle in the graph.
 */
bool Algorithms::dfs(const Graph &g, size_t v, vector<size_t> &prev, stack<size_t> &s) {
    s.push(v);
    std::vector<std::vector<int>> adjMatrix = g.getAdjacencyMatrix();
    for (size_t u = 0; u < adjMatrix[v].size(); ++u) {
        if (adjMatrix[v][u] != 0) { // there is an edge from v to u
            if (prev[u] == -1) {
                prev[u] = v;
                if (dfs(g, u, prev, s)) {
                    return true;
                }
            } else if (u != prev[v]) {
                s.push(u);
                return true;
            }
        }
    }
    s.pop();
    return false;
}

/**
 * This function checks if a graph is connected or not.
 * It uses a Depth-First Search (DFS) starting from the first vertex and checks if all vertices are visited.
 */
bool Algorithms::isConnected(const Graph &graph)
{
    vector<vector<int>> adjMatrix = graph.getAdjacencyMatrix();
    size_t n = adjMatrix.size();
    vector<bool> visited(n, false);

    // Perform DFS traversal from the first node
    stack<size_t> st;
    st.push(0);

    while (!st.empty())
    {
        size_t node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            for (size_t i = 0; i < n; ++i)
            {
                if (adjMatrix[node][i] != 0)
                {
                    st.push(i);
                }
            }
        }
    }

    // Check if all nodes were visited
    for (bool v : visited)
    {
        if (!v)
        {
            return false;
        }
    }
    return true;
}

/**
 * This function finds the shortest path between two vertices in a graph.
 * It uses a Breadth-First Search (BFS) and keeps track of the parent of each vertex to reconstruct the path.
 * If there is a negative cycle in the graph, it returns "-1".
 * The path is returned as a string of vertices, separated by "->".
 */
// string Algorithms::shortestPath(const Graph &graph, size_t start, size_t end)
// {
//     vector<vector<int>> adjMatrix = graph.getAdjacencyMatrix();
//     size_t n = adjMatrix.size();
//     vector<size_t> distance(n, numeric_limits<size_t>::max());
//     vector<size_t> parent(n, numeric_limits<size_t>::max());

//     distance[start] = 0;
//     queue<size_t> q;
//     q.push(start);

//     if (negativeCycle(graph))
//     {
//         return "-1";
//     }

//     while (!q.empty())
//     {
//         size_t node = q.front();
//         q.pop();

//         for (size_t i = 0; i < n; ++i)
//         {
//             if (adjMatrix[node][i] != 0 && distance[i] == numeric_limits<size_t>::max())
//             {
//                 distance[i] = distance[node] + 1;
//                 parent[i] = node;
//                 q.push(i);
//             }
//         }
//     }

//     if (distance[end] == numeric_limits<size_t>::max()) {
//         return "-1";
//     }

//     // Reconstruct the shortest path
//     string path;
//     for (size_t v = end; v != numeric_limits<size_t>::max(); v = parent[v])
//     {
//         path = to_string(v) + (path.empty() ? "" : "->" + path);
//     }

//     return path;
// }
    
    string Algorithms::shortestPath(const Graph &graph, size_t start, size_t end)
{
    vector<vector<int>> adjMatrix = graph.getAdjacencyMatrix();
    size_t n = adjMatrix.size();
    vector<int> distance(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);

    distance[start] = 0;
    queue<size_t> q;
    q.push(start);

    if (negativeCycle(graph))
    {
        return "-1";
    }

    while (!q.empty())
    {
        size_t node = q.front();
        q.pop();

        for (size_t i = 0; i < n; ++i)
        {
            if (adjMatrix[node][i] != 0 && distance[i] == numeric_limits<int>::max())
            {
                distance[i] = distance[node] + adjMatrix[node][i];
                parent[i] = node;
                q.push(i);
            }
        }
    }

    if (distance[end] == numeric_limits<int>::max()) {
        return "-1";
    }

    // Reconstruct the shortest path
    std::stringstream path;
    size_t current = end;
    std::stack<size_t> reversePath;

    while (current != static_cast<size_t>(-1))
    {
        reversePath.push(current);
        current = static_cast<size_t>(parent[current]);
    }

    while (!reversePath.empty())
    {
        path << reversePath.top();
        reversePath.pop();
        if (!reversePath.empty())
        {
            path << "->";
        }
    }

    return path.str();
}

/**
 * This function checks if a graph contains a cycle or not.
 * It uses a Depth-First Search (DFS) and checks for back edges to detect cycles.
 * If a cycle is found, it prints the cycle path and returns true.
 * If no cycle is found, it returns false.
 */
bool Algorithms::isContainsCycle(const Graph &graph)
{
    vector<vector<int>> adjMatrix = graph.getAdjacencyMatrix();
    size_t n = adjMatrix.size();
    vector<bool> visited(n, false);
    vector<size_t> parent(n, numeric_limits<size_t>::max());

    for (size_t i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            stack<size_t> st;
            st.push(i);

            while (!st.empty())
            {
                size_t node = st.top();
                st.pop();

                if (!visited[node])
                {
                    visited[node] = true;

                    for (size_t j = 0; j < n; ++j)
                    {
                        if (adjMatrix[node][j] != 0)
                        {
                            if (!visited[j])
                            {
                                st.push(j);
                                parent[j] = node;
                            }
                            else if (parent[node] != j)
                            {
                                // Found a cycle, construct the cycle path
                                vector<size_t> cycle;
                                size_t v = node;
                                while (v != j)
                                {
                                    cycle.push_back(v);
                                    v = parent[v];
                                }
                                cycle.push_back(j);
                                cycle.push_back(node);

                                // Print the cycle path
                                cout << "Cycle found: ";
                                for (size_t i = 0; i < cycle.size(); ++i)
                                {
                                    cout << cycle[i];
                                    if (i != cycle.size() - 1)
                                        cout << "->";
                                }
                                cout << endl;

                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false; // No cycle found
}


/**
 * This function checks if a graph is bipartite or not.
 * A graph is bipartite if the vertices can be divided into two disjoint sets such that every edge connects a vertex in the first set to one in the second set.
 * It uses a Breadth-First Search (BFS) and colors the vertices with two different colors to check if the graph is bipartite.
 */
string Algorithms::isBipartite(const Graph &graph)
{
    vector<vector<int>> adjMatrix = graph.getAdjacencyMatrix();
    size_t n = adjMatrix.size();
    vector<int> color(n, -1);

    vector<int> setA, setB;

    for (size_t start = 0; start < n; ++start)
    {
        if (color[start] == -1)
        {
            queue<size_t> q;
            q.push(start);
            color[start] = 1;

            while (!q.empty())
            {
                size_t node = q.front();
                q.pop();

                for (size_t i = 0; i < n; ++i)
                {
                    if (adjMatrix[node][i] != 0)
                    {
                        if (color[i] == -1)
                        {
                            color[i] = 1 - color[node];
                            q.push(i);
                        }
                        else if (color[i] == color[node])
                        {
                            return "0"; // Not bipartite
                        }
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < n; ++i)
    {
        if (color[i] == 1)
            setA.push_back(i);
        else
            setB.push_back(i);
    }

    stringstream ss;
    ss << "The graph is bipartite: A={";
    for (size_t i = 0; i < setA.size(); ++i)
    {
        if (i != 0)
            ss << ", ";
        ss << setA[i];
    }
    ss << "}, B={";
    for (size_t i = 0; i < setB.size(); ++i)
    {
        if (i != 0)
            ss << ", ";
        ss << setB[i];
    }
    ss << "}";

    return ss.str();
}

/**
 * This function checks if a graph contains a negative cycle or not.
 * A negative cycle is a cycle whose edges sum to a negative value.
 * It uses the Bellman-Ford algorithm to detect negative cycles.
 * Returns true if a negative cycle is found, false otherwise.
 */
bool Algorithms::negativeCycle(const Graph& graph) {
    const vector<vector<int>>& neighborMatrix = graph.getAdjacencyMatrix();
    size_t numVertices = neighborMatrix.size(); // Use size_t for the number of vertices
    const int INF = numeric_limits<int>::max();

    vector<int> distance(numVertices, 0); // Initialize distance to 0
    for (size_t i = 0; i < numVertices - 1; ++i) {
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                if (neighborMatrix[u][v] != 0) {
                    if (distance[u] != INF && distance[u] + neighborMatrix[u][v] < distance[v]) {
                        // there is negative cycle
                        return true;
                    }
                }
            }
        }
    }

    return false; // no negative cycle
}
