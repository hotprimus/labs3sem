/********************************************************************************
** Form generated from reading UI file 'UI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_UI
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *sortIntegersButton;
    QPushButton *sortIntegersReverseButton;
    QPushButton *sortComplexButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *selectFileButton;
    QLineEdit *fileLineEdit;
    QPushButton *sortFromFileButton;
    QPushButton *runBenchmarkButton;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *integerTableWidget;
    QTableWidget *reverseIntegerTableWidget;
    QTableWidget *complexTableWidget;
    QTableWidget *fileSortTableWidget;
    QtCharts::QChartView *benchmarkChartView;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName(QString::fromUtf8("UI"));
        UI->resize(800, 600);
        centralWidget = new QWidget(UI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sortIntegersButton = new QPushButton(centralWidget);
        sortIntegersButton->setObjectName(QString::fromUtf8("sortIntegersButton"));

        horizontalLayout->addWidget(sortIntegersButton);

        sortIntegersReverseButton = new QPushButton(centralWidget);
        sortIntegersReverseButton->setObjectName(QString::fromUtf8("sortIntegersReverseButton"));

        horizontalLayout->addWidget(sortIntegersReverseButton);

        sortComplexButton = new QPushButton(centralWidget);
        sortComplexButton->setObjectName(QString::fromUtf8("sortComplexButton"));

        horizontalLayout->addWidget(sortComplexButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        selectFileButton = new QPushButton(centralWidget);
        selectFileButton->setObjectName(QString::fromUtf8("selectFileButton"));

        horizontalLayout_2->addWidget(selectFileButton);

        fileLineEdit = new QLineEdit(centralWidget);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));

        horizontalLayout_2->addWidget(fileLineEdit);

        sortFromFileButton = new QPushButton(centralWidget);
        sortFromFileButton->setObjectName(QString::fromUtf8("sortFromFileButton"));

        horizontalLayout_2->addWidget(sortFromFileButton);

        runBenchmarkButton = new QPushButton(centralWidget);
        runBenchmarkButton->setObjectName(QString::fromUtf8("runBenchmarkButton"));

        horizontalLayout_2->addWidget(runBenchmarkButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        integerTableWidget = new QTableWidget(centralWidget);
        integerTableWidget->setObjectName(QString::fromUtf8("integerTableWidget"));
        integerTableWidget->setColumnCount(1);

        horizontalLayout_3->addWidget(integerTableWidget);

        reverseIntegerTableWidget = new QTableWidget(centralWidget);
        reverseIntegerTableWidget->setObjectName(QString::fromUtf8("reverseIntegerTableWidget"));
        reverseIntegerTableWidget->setColumnCount(1);

        horizontalLayout_3->addWidget(reverseIntegerTableWidget);

        complexTableWidget = new QTableWidget(centralWidget);
        complexTableWidget->setObjectName(QString::fromUtf8("complexTableWidget"));
        complexTableWidget->setColumnCount(2);

        horizontalLayout_3->addWidget(complexTableWidget);

        fileSortTableWidget = new QTableWidget(centralWidget);
        fileSortTableWidget->setObjectName(QString::fromUtf8("fileSortTableWidget"));
        fileSortTableWidget->setColumnCount(2);

        horizontalLayout_3->addWidget(fileSortTableWidget);


        verticalLayout->addLayout(horizontalLayout_3);

        benchmarkChartView = new QtCharts::QChartView(centralWidget);
        benchmarkChartView->setObjectName(QString::fromUtf8("benchmarkChartView"));

        verticalLayout->addWidget(benchmarkChartView);

        UI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        UI->setMenuBar(menuBar);
        statusBar = new QStatusBar(UI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UI->setStatusBar(statusBar);

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QMainWindow *UI)
    {
        UI->setWindowTitle(QCoreApplication::translate("UI", "Sorting Application", nullptr));
        sortIntegersButton->setText(QCoreApplication::translate("UI", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\206\320\265\320\273\321\213\320\265 \321\207\320\270\321\201\320\273\320\260", nullptr));
        sortIntegersReverseButton->setText(QCoreApplication::translate("UI", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\206\320\265\320\273\321\213\320\265 \321\207\320\270\321\201\320\273\320\260 \320\262 \320\276\320\261\321\200\320\260\321\202\320\275\320\276\320\274 \320\277\320\276\321\200\321\217\320\264\320\272\320\265", nullptr));
        sortComplexButton->setText(QCoreApplication::translate("UI", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202\321\213 Person", nullptr));
        selectFileButton->setText(QCoreApplication::translate("UI", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        sortFromFileButton->setText(QCoreApplication::translate("UI", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        runBenchmarkButton->setText(QCoreApplication::translate("UI", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\261\320\265\320\275\321\207\320\274\320\260\321\200\320\272", nullptr));
        integerTableWidget->setHorizontalHeaderLabels(QStringList()
            << QCoreApplication::translate("UI", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        reverseIntegerTableWidget->setHorizontalHeaderLabels(QStringList()
            << QCoreApplication::translate("UI", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 (\320\236\320\261\321\200\320\260\321\202\320\275\320\260\321\217)", nullptr));
        complexTableWidget->setHorizontalHeaderLabels(QStringList()
            << QCoreApplication::translate("UI", "\320\230\320\274\321\217", nullptr)
            << QCoreApplication::translate("UI", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        fileSortTableWidget->setHorizontalHeaderLabels(QStringList()
            << QCoreApplication::translate("UI", "\320\230\320\274\321\217", nullptr)
            << QCoreApplication::translate("UI", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
