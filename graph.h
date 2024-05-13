#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
public:
    Graph(int vertexCount);
    ~Graph();

    int getVertexCount() const;
    int getEdgeWeight(int i, int j) const;
    void setEdgeWeight(int i, int j, int weight);

private:
    int vertexCount;
    std::vector<std::vector<int>> adjacencyMatrix;
};

#endif // GRAPH_H
