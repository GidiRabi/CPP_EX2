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


            // Comparison Operators
            bool operator>(const Graph &other);
            bool operator>=(const Graph &other);
            bool operator<(const Graph &other);
            bool operator<=(const Graph &other);
            bool operator==(const Graph &other);
            bool operator!=(const Graph &other);

            // Increment and Decrement Operators
            Graph& operator++();
            Graph& operator--();

            // Arithmetic Operators
            Graph operator+(const Graph &other);
            Graph& operator+=(const Graph &other);
            Graph operator+();

            Graph operator-(const Graph &other);
            Graph& operator-=(const Graph &other);
            Graph operator-();

            Graph operator/(int scalar);
            Graph& operator/=(int scalar);
            
            Graph& operator*=(int scalar);
            Graph operator*(const Graph &other);

            // Output Operator
            friend ostream& operator<<(ostream &os, const Graph &graph);

        };
    }
    #endif