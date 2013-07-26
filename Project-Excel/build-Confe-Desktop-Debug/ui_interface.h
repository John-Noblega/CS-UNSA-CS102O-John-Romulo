/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QStringLiteral("interface"));
        interface->resize(646, 551);
        centralWidget = new QWidget(interface);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 100)
            tableWidget->setColumnCount(100);
        if (tableWidget->rowCount() < 100)
            tableWidget->setRowCount(100);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setDragEnabled(true);
        tableWidget->setDragDropMode(QAbstractItemView::InternalMove);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setRowCount(100);
        tableWidget->setColumnCount(100);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        interface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(interface);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 25));
        interface->setMenuBar(menuBar);
        mainToolBar = new QToolBar(interface);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        interface->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(interface);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        interface->setStatusBar(statusBar);

        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QMainWindow *interface)
    {
        interface->setWindowTitle(QApplication::translate("interface", "interface", 0));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
