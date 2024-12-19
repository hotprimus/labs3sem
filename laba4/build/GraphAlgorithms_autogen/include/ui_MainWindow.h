/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadGraphButton;
    QPushButton *saveGraphButton;
    QComboBox *algorithmComboBox;
    QLineEdit *startVertexLineEdit;
    QPushButton *runAlgorithmButton;
    QTextEdit *resultsTextEdit;
    QLabel *timeLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loadGraphButton = new QPushButton(centralwidget);
        loadGraphButton->setObjectName(QString::fromUtf8("loadGraphButton"));
        loadGraphButton->setGeometry(QRect(20, 20, 120, 30));
        saveGraphButton = new QPushButton(centralwidget);
        saveGraphButton->setObjectName(QString::fromUtf8("saveGraphButton"));
        saveGraphButton->setGeometry(QRect(160, 20, 120, 30));
        algorithmComboBox = new QComboBox(centralwidget);
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->addItem(QString());
        algorithmComboBox->setObjectName(QString::fromUtf8("algorithmComboBox"));
        algorithmComboBox->setGeometry(QRect(20, 70, 260, 30));
        startVertexLineEdit = new QLineEdit(centralwidget);
        startVertexLineEdit->setObjectName(QString::fromUtf8("startVertexLineEdit"));
        startVertexLineEdit->setGeometry(QRect(300, 70, 50, 30));
        runAlgorithmButton = new QPushButton(centralwidget);
        runAlgorithmButton->setObjectName(QString::fromUtf8("runAlgorithmButton"));
        runAlgorithmButton->setGeometry(QRect(370, 70, 120, 30));
        resultsTextEdit = new QTextEdit(centralwidget);
        resultsTextEdit->setObjectName(QString::fromUtf8("resultsTextEdit"));
        resultsTextEdit->setGeometry(QRect(20, 120, 540, 220));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(20, 360, 200, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Graph Algorithms", nullptr));
        loadGraphButton->setText(QCoreApplication::translate("MainWindow", "Load Graph", nullptr));
        saveGraphButton->setText(QCoreApplication::translate("MainWindow", "Save Graph", nullptr));
        algorithmComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Breadth-First Search", nullptr));
        algorithmComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Depth-First Search", nullptr));
        algorithmComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Connected Components", nullptr));
        algorithmComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Build Hasse Diagram", nullptr));

        startVertexLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Start Vertex", nullptr));
        runAlgorithmButton->setText(QCoreApplication::translate("MainWindow", "Run Algorithm", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "Time: 0 ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
