#include "graph.h"

Graph::Graph(int vertexCount) : vertexCount(vertexCount), adjacencyMatrix(vertexCount, std::vector<int>(vertexCount, 0))
{
}

Graph::~Graph()
{
}

int Graph::getVertexCount() const
{
    return vertexCount;
}

int Graph::getEdgeWeight(int i, int j) const
{
    return adjacencyMatrix[i][j];
}

void Graph::setEdgeWeight(int i, int j, int weight)
{
    adjacencyMatrix[i][j] = weight;
    adjacencyMatrix[j][i] = weight;
}
