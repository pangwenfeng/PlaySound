/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *startButton;
    QLabel *label;
    QProgressBar *progressBarMusic;
    QPushButton *pushStop;
    QPushButton *pushFile;
    QTableWidget *listItem;
    QScrollBar *volumnBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 327);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(10, 220, 51, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 220, 41, 20));
        progressBarMusic = new QProgressBar(centralWidget);
        progressBarMusic->setObjectName(QStringLiteral("progressBarMusic"));
        progressBarMusic->setGeometry(QRect(10, 250, 381, 16));
        progressBarMusic->setValue(24);
        pushStop = new QPushButton(centralWidget);
        pushStop->setObjectName(QStringLiteral("pushStop"));
        pushStop->setGeometry(QRect(70, 220, 51, 23));
        pushFile = new QPushButton(centralWidget);
        pushFile->setObjectName(QStringLiteral("pushFile"));
        pushFile->setGeometry(QRect(310, 10, 75, 23));
        listItem = new QTableWidget(centralWidget);
        listItem->setObjectName(QStringLiteral("listItem"));
        listItem->setGeometry(QRect(10, 10, 256, 192));
        listItem->setColumnCount(0);
        volumnBar = new QScrollBar(centralWidget);
        volumnBar->setObjectName(QStringLiteral("volumnBar"));
        volumnBar->setGeometry(QRect(240, 220, 141, 17));
        volumnBar->setMaximum(100);
        volumnBar->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        startButton->setText(QApplication::translate("MainWindow", "START", 0));
        label->setText(QApplication::translate("MainWindow", "Volumn", 0));
        progressBarMusic->setFormat(QApplication::translate("MainWindow", "%p%", 0));
        pushStop->setText(QApplication::translate("MainWindow", "STOP", 0));
        pushFile->setText(QApplication::translate("MainWindow", "OpenFile", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
