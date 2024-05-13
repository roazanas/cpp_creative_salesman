#ifndef SALESMANPROBLEM_H
#define SALESMANPROBLEM_H

#include "graph.h"
#include <QString>
#include <QList>

class SalesmanProblem
{
public:
    SalesmanProblem(Graph *graph);
    ~SalesmanProblem();

    QString solve();

private:
    Graph *graph;

    int findMinInArray(const std::vector<int> &array) const;
    void reduceArray(std::vector<int> &array, int min) const;
    QString markZeroElements(std::vector<std::vector<int>> &matrix) const;
    void reduceTable(std::vector<std::vector<int>> &matrix, int row, int col) const;
};

#endif // SALESMANPROBLEM_H
