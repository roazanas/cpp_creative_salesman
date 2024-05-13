#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTableWidget>
#include <QStyleFactory>
#include "graph.h"
#include "salesmanproblem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createGraphButton_clicked();
    void on_buildGraphButton_clicked();
    void on_calculateButton_clicked();
    void on_vertexCountLineEdit_textChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    Graph *graph;
    SalesmanProblem *salesmanProblem;

    void setupTableWidget(int vertexCount);
    void displayResults(const QString &result);
    // void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
