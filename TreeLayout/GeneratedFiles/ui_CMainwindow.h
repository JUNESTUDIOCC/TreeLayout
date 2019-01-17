/********************************************************************************
** Form generated from reading UI file 'CMainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CTreeView.h"

QT_BEGIN_NAMESPACE

class Ui_CMainwindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    CTreeView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainwindowClass)
    {
        if (CMainwindowClass->objectName().isEmpty())
            CMainwindowClass->setObjectName(QStringLiteral("CMainwindowClass"));
        CMainwindowClass->resize(600, 400);
        centralWidget = new QWidget(CMainwindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new CTreeView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        CMainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainwindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        CMainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainwindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CMainwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainwindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainwindowClass->setStatusBar(statusBar);

        retranslateUi(CMainwindowClass);

        QMetaObject::connectSlotsByName(CMainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainwindowClass)
    {
        CMainwindowClass->setWindowTitle(QApplication::translate("CMainwindowClass", "CMainwindow", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainwindowClass: public Ui_CMainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
