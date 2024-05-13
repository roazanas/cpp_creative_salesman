#include "salesmanproblem.h"
#include <limits>
#include <queue>
#include <algorithm>

SalesmanProblem::SalesmanProblem(Graph *graph) : graph(graph)
{
}

SalesmanProblem::~SalesmanProblem()
{
}


QString SalesmanProblem::solve()
{
    int vertexCount = graph->getVertexCount();
    std::vector<int> path;
    std::vector<bool> visited(vertexCount, false);

    // Начинаем с вершины 0
    visited[0] = true;
    path.push_back(0);

    int totalDistance = 0;

    for (int i = 0; i < vertexCount - 1; ++i) {
        int currentVertex = path.back();
        int nearestVertex = -1;
        int minDistance = std::numeric_limits<int>::max();

        for (int j = 0; j < vertexCount; ++j) {
            if (!visited[j] && graph->getEdgeWeight(currentVertex, j) < minDistance && graph->getEdgeWeight(currentVertex, j) != 0) {
                nearestVertex = j;
                minDistance = graph->getEdgeWeight(currentVertex, j);
            }
        }

        if (nearestVertex != -1) {
            visited[nearestVertex] = true;
            path.push_back(nearestVertex);
            totalDistance += minDistance;
        }
    }

    // Возвращаемся к начальной вершине
    totalDistance += graph->getEdgeWeight(path.back(), 0);
    path.push_back(0);

    QString result = "Возможные передвижения:\n";
    for (size_t i = 0; i < path.size() - 1; ++i) {
        result += QString("%1→").arg(path[i] + 1);
    }
    result += QString("%1").arg(path.back() + 1);
    result += QString("\nДлина кратчайшего пути = %1").arg(totalDistance);

    return result;
}
