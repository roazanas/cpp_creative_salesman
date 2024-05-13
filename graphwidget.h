#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include "graph.h"

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWidget(Graph *graph, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Graph *graph;
};

#endif // GRAPHWIDGET_H
