#pragma once

#include <QMainWindow>
#include <QVector>
#include "../Sequence/MutableSequence.h"
#include "../Sequence/DynamicArray.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UI; }
QT_END_NAMESPACE

class UI : public QMainWindow
{
    Q_OBJECT

public:
    UI(QWidget *parent = nullptr);
    ~UI();

private slots:
    void on_sortButton_clicked();

private:
    Ui::UI *ui;
    MutableSequence<int>* sequence;
};

