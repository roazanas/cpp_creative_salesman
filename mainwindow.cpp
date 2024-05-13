#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "graphwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->calculateButton->hide();
    ui->adjacencyMatrixTableWidget->hide();
    ui->buildGraphButton->hide();
}

void MainWindow::setupTableWidget(int vertexCount)
{
    ui->adjacencyMatrixTableWidget->clear();
    ui->adjacencyMatrixTableWidget->setRowCount(vertexCount);
    ui->adjacencyMatrixTableWidget->setColumnCount(vertexCount);

    QStringList horizontalHeaders;
    QStringList verticalHeaders;
    for (int i = 1; i <= vertexCount; ++i) {
        horizontalHeaders << QString::number(i);
        verticalHeaders << QString::number(i);
    }
    ui->adjacencyMatrixTableWidget->setHorizontalHeaderLabels(horizontalHeaders);
    ui->adjacencyMatrixTableWidget->setVerticalHeaderLabels(verticalHeaders);

    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            if (i < j) {
                QTableWidgetItem *item = new QTableWidgetItem("0");
                ui->adjacencyMatrixTableWidget->setItem(i, j, item);
            } else {
                QTableWidgetItem *item = new QTableWidgetItem("");
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                ui->adjacencyMatrixTableWidget->setItem(i, j, item);
            }
        }
    }
}

void MainWindow::displayResults(const QString &result)
{
    ui->resultTextEdit->setPlainText(result);
}

void MainWindow::on_createGraphButton_clicked()
{
    bool ok;
    int vertexCount = ui->vertexCountLineEdit->text().toInt(&ok);
    if (!ok || vertexCount < 2 || vertexCount > 9) {
        QMessageBox::warning(this, "Предупреждение", "Количество вершин недопустимо");
        return;
    }

    setupTableWidget(vertexCount);
    graph = new Graph(vertexCount);
    salesmanProblem = new SalesmanProblem(graph);

    ui->adjacencyMatrixTableWidget->show();
    ui->buildGraphButton->show();
    ui->calculateButton->hide();
}

void MainWindow::on_buildGraphButton_clicked()
{
    for (int i = 0; i < graph->getVertexCount(); ++i) {
        for (int j = i + 1; j < graph->getVertexCount(); ++j) {
            QTableWidgetItem *item = ui->adjacencyMatrixTableWidget->item(i, j);
            if (item) {
                graph->setEdgeWeight(i, j, item->text().toInt());
            }
        }
    }

    // Создание и отображение виджета графа в новом окне
    GraphWidget *graphWidget = new GraphWidget(graph);
    graphWidget->show();

    ui->calculateButton->show();
}

void MainWindow::on_calculateButton_clicked()
{
    QString result = salesmanProblem->solve();
    displayResults(result);
}

void MainWindow::on_vertexCountLineEdit_textChanged(const QString &text)
{
    bool ok;
    int vertexCount = text.toInt(&ok);
    if ((!ok || vertexCount < 2 || vertexCount > 9) || ui->adjacencyMatrixTableWidget->isHidden()) {
        ui->buildGraphButton->hide();
        ui->calculateButton->hide();
        ui->adjacencyMatrixTableWidget->hide();
    } else {
        ui->buildGraphButton->show();
        ui->calculateButton->hide();
        ui->adjacencyMatrixTableWidget->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graph;
    delete salesmanProblem;
}
