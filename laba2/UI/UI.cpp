#include "UI.h"
#include "ui_UI.h"
#include "../TypeOfSorts/QuickSorter.h"
#include "../TypeOfSorts/HeapSorter.h"
#include "../TypeOfSorts/ShellSorter.h"
#include <QInputDialog>
#include <QMessageBox>

UI::UI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UI)
    , sequence(new DynamicArray<int>())
{
    ui->setupUi(this);

    // Connect the sort button
    connect(ui->sortButton, &QPushButton::clicked, this, &UI::on_sortButton_clicked);
}

UI::~UI()
{
    delete ui;
    delete sequence;
}

void UI::on_sortButton_clicked()
{
    sequence->resize(0);

    QString input = ui->inputLineEdit->text();
    QStringList inputList = input.split(',', Qt::SkipEmptyParts);

    for (const QString& s : inputList)
        sequence->append(s.trimmed().toInt());

    ISorter<int>* sorter = nullptr;
    QString sorterType = ui->sorterComboBox->currentText();

    if (sorterType == "Quick Sort")
        sorter = new QuickSorter<int>();
    else if (sorterType == "Heap Sort")
        sorter = new HeapSorter<int>();
    else if (sorterType == "Shell Sort")
        sorter = new ShellSorter<int>();
    else
    {
        QMessageBox::warning(this, "Error", "Invalid sorter selected");
        return;
    }

    sorter->sort(sequence, [](const int& a, const int& b) { return a < b; });

    QStringList sortedList;
    for (int i = 0; i < sequence->getSize(); ++i)
        sortedList << QString::number((*sequence)[i]);

    ui->outputLineEdit->setText(sortedList.join(", "));

    delete sorter;
}
