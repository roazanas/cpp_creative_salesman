#include "graphwidget.h"
#include <QPainter>
#include <QPen>
#include <cmath>

GraphWidget::GraphWidget(Graph *graph, QWidget *parent) : QWidget(parent), graph(graph)
{
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if (graph) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        int vertexCount = graph->getVertexCount();
        int centerX = width() / 2;
        int centerY = height() / 2;
        int radius = qMin(centerX, centerY) * 0.7;

        // Рисование ребер
        for (int i = 0; i < vertexCount; ++i) {
            for (int j = i + 1; j < vertexCount; ++j) {
                int weight = graph->getEdgeWeight(i, j);
                if (weight > 0) {
                    double angle1 = 2 * M_PI * i / vertexCount;
                    int x1 = centerX + radius * cos(angle1);
                    int y1 = centerY + radius * sin(angle1);

                    double angle2 = 2 * M_PI * j / vertexCount;
                    int x2 = centerX + radius * cos(angle2);
                    int y2 = centerY + radius * sin(angle2);

                    // Выбор цвета ребра
                    QColor edgeColor = QColor(43,43,43);

                    QPen pen(edgeColor);
                    pen.setWidth(2);
                    painter.setPen(pen);
                    painter.drawLine(x1, y1, x2, y2);

                    // Отображение веса ребра
                    int midX = (x1 + x2) / 2;
                    int midY = (y1 + y2) / 2;
                    painter.setPen(Qt::white);
                    painter.drawText(QPoint(midX + 5, midY - 5), QString::number(weight));
                }
            }
        }

        // Рисование вершин
        for (int i = 0; i < vertexCount; ++i) {
            double angle = 2 * M_PI * i / vertexCount;
            int x = centerX + radius * cos(angle);
            int y = centerY + radius * sin(angle);

            QPen pen(QColor(142,45,197));
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawEllipse(QPoint(x, y), 10, 10);

            painter.setPen(Qt::white);
            painter.drawText(QPoint(x - 1, y + 5), QString::number(i + 1));
        }
    }
}
