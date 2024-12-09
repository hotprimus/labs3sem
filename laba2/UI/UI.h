#pragma once

#include <QMainWindow>
#include <QTableWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "../Person/Person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UI; }
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class UI : public QMainWindow {
    Q_OBJECT

public:
    explicit UI(QWidget *parent = nullptr);
    ~UI();

private slots:
    void on_sortIntegersButton_clicked();
    void on_sortIntegersReverseButton_clicked();
    void on_sortComplexButton_clicked();
    void on_selectFileButton_clicked();
    void on_sortFromFileButton_clicked();
    void on_runBenchmarkButton_clicked();

private:
    Ui::UI *ui;

    void updateIntegerTable(const std::vector<int>& data);
    void updateReverseIntegerTable(const std::vector<int>& data);
    void updateComplexTable(const std::vector<Person>& data);
    void updateFileSortTable(const std::vector<Person>& data);
    void updateBenchmarkChart(
        const std::vector<std::pair<size_t, double>>& shellData,
        const std::vector<std::pair<size_t, double>>& quickData,
        const std::vector<std::pair<size_t, double>>& heapData);
};
