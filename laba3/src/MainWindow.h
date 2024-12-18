#pragma once

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "Histogram.h"
#include "Person.h"
#include "HistogramBuilder.h"

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onChooseFile();
    void onBuildHistogram();

private:
    QComboBox *criterionComboBox;
    QLineEdit *minValueEdit;
    QLineEdit *maxValueEdit;
    QLineEdit *numberOfRangesEdit;
    QPushButton *chooseFileButton;
    QLabel *filePathLabel;
    QPushButton *buildHistogramButton;
    QChartView *chartView;
    QTableWidget *resultsTableWidget;
    QString csvFilePath;
    void setupUi();
    void displayHistogram(const Histogram<Person> &histogram);
};

