/********************************************************************************
** Form generated from reading UI file 'UI.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UI
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputLineEdit;
    QComboBox *sorterComboBox;
    QPushButton *sortButton;
    QLineEdit *outputLineEdit;

    void setupUi(QMainWindow *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName("UI");
        UI->resize(400, 200);
        centralWidget = new QWidget(UI);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        inputLineEdit = new QLineEdit(centralWidget);
        inputLineEdit->setObjectName("inputLineEdit");

        verticalLayout->addWidget(inputLineEdit);

        sorterComboBox = new QComboBox(centralWidget);
        sorterComboBox->addItem(QString());
        sorterComboBox->addItem(QString());
        sorterComboBox->addItem(QString());
        sorterComboBox->setObjectName("sorterComboBox");

        verticalLayout->addWidget(sorterComboBox);

        sortButton = new QPushButton(centralWidget);
        sortButton->setObjectName("sortButton");

        verticalLayout->addWidget(sortButton);

        outputLineEdit = new QLineEdit(centralWidget);
        outputLineEdit->setObjectName("outputLineEdit");
        outputLineEdit->setReadOnly(true);

        verticalLayout->addWidget(outputLineEdit);

        UI->setCentralWidget(centralWidget);

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QMainWindow *UI)
    {
        UI->setWindowTitle(QCoreApplication::translate("UI", "Sorting Application", nullptr));
        inputLineEdit->setPlaceholderText(QCoreApplication::translate("UI", "Enter numbers separated by commas", nullptr));
        sorterComboBox->setItemText(0, QCoreApplication::translate("UI", "Quick Sort", nullptr));
        sorterComboBox->setItemText(1, QCoreApplication::translate("UI", "Heap Sort", nullptr));
        sorterComboBox->setItemText(2, QCoreApplication::translate("UI", "Shell Sort", nullptr));

        sortButton->setText(QCoreApplication::translate("UI", "Sort", nullptr));
        outputLineEdit->setPlaceholderText(QCoreApplication::translate("UI", "Sorted output will appear here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
