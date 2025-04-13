#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

Graph::Graph(int vertices) : V(vertices) {
    adjMatrix.resize(V, vector<int>(V, 0));
    adjList.resize(V);
}

void Graph::addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::printAdjMatrix() const {
    cout << "Adjacency Matrix:\n";
    for (const auto& row : adjMatrix) {
        for (int val : row)
            cout << val << " ";
        cout << '\n';
    }
}

void Graph::printAdjList() const {
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i])
            cout << neighbor << " ";
        cout << '\n';
    }
}

void Graph::bfs(int source, int target) const {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
                if (neighbor == target) break;
            }
        }
    }

    if (!visited[target]) {
        cout << "No path between " << source << " and " << target << '\n';
        return;
    }

    vector<int> path;
    for (int at = target; at != -1; at = parent[at])
        path.push_back(at);

    cout << "BFS path from " << source << " to " << target << ": ";
    for (auto it = path.rbegin(); it != path.rend(); ++it)
        cout << *it << " ";
    cout << '\n';
}

void Graph::dfsIterative(int start) const {
    vector<bool> visited(V, false);
    stack<int> stk;

    stk.push(start);
    cout << "DFS (iterative) from " << start << ": ";

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;

            for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                if (!visited[*it])
                    stk.push(*it);
            }
        }
    }
    cout << '\n';
}

Graph Graph::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << '\n';
        exit(EXIT_FAILURE);
    }

    string line;
    getline(file, line);
    int vertices = stoi(line);
    Graph g(vertices);

    while (getline(file, line)) {
        istringstream iss(line);
        int u, v;
        if (iss >> u >> v)
            g.addEdge(u, v);
    }

    return g;
}
