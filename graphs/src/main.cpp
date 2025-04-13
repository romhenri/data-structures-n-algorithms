#include "graph.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <graph_file.txt>\n";
        return 1;
    }

    std::string filename = argv[1];

    Graph g = Graph::loadFromFile(filename);

    g.printAdjMatrix();
    g.printAdjList();

    g.bfs(0, 4);
    g.dfsIterative(0);

    return 0;
}