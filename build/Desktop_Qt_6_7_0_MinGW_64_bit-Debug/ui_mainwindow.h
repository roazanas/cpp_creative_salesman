/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *vertexCountLineEdit;
    QPushButton *createGraphButton;
    QTableWidget *adjacencyMatrixTableWidget;
    QPushButton *buildGraphButton;
    QPushButton *calculateButton;
    QTextEdit *resultTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        vertexCountLineEdit = new QLineEdit(centralwidget);
        vertexCountLineEdit->setObjectName("vertexCountLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vertexCountLineEdit->sizePolicy().hasHeightForWidth());
        vertexCountLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(vertexCountLineEdit);

        createGraphButton = new QPushButton(centralwidget);
        createGraphButton->setObjectName("createGraphButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createGraphButton->sizePolicy().hasHeightForWidth());
        createGraphButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(createGraphButton);


        verticalLayout->addLayout(horizontalLayout);

        adjacencyMatrixTableWidget = new QTableWidget(centralwidget);
        adjacencyMatrixTableWidget->setObjectName("adjacencyMatrixTableWidget");
        adjacencyMatrixTableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
        adjacencyMatrixTableWidget->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(adjacencyMatrixTableWidget);

        buildGraphButton = new QPushButton(centralwidget);
        buildGraphButton->setObjectName("buildGraphButton");

        verticalLayout->addWidget(buildGraphButton);

        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName("calculateButton");

        verticalLayout->addWidget(calculateButton);

        resultTextEdit = new QTextEdit(centralwidget);
        resultTextEdit->setObjectName("resultTextEdit");
        resultTextEdit->setReadOnly(true);

        verticalLayout->addWidget(resultTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Salesman", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\320\276\321\200\320\276\320\264\320\276\320\262:", nullptr));
        createGraphButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        buildGraphButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
