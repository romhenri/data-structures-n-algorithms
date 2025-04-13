#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::vector<int>> adjList;

public:
    explicit Graph(int vertices);

    void addEdge(int u, int v);
    void printAdjMatrix() const;
    void printAdjList() const;

    void bfs(int source, int target) const;
    void dfsIterative(int start) const;

    static Graph loadFromFile(const std::string& filename);
};

#endif // GRAPH_H
