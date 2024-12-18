// UI/UI.cpp

#include "UI.h"
#include "ui_UI.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

// Подключение заголовочных файлов сортировщиков
#include "../TypeOfSorts/ShellSorter.h"
#include "../TypeOfSorts/QuickSorter.h"
#include "../TypeOfSorts/HeapSorter.h"

// Подключение заголовочного файла DynamicArray
#include "../Sequence/DynamicArray.h"

#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <chrono>

UI::UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UI)
{
    ui->setupUi(this);

    // Инициализация таблиц
    ui->integerTableWidget->setColumnCount(1);
    ui->integerTableWidget->setHorizontalHeaderLabels(QStringList() << "Значение");

    ui->reverseIntegerTableWidget->setColumnCount(1);
    ui->reverseIntegerTableWidget->setHorizontalHeaderLabels(QStringList() << "Значение (Обратная)");

    ui->complexTableWidget->setColumnCount(2);
    ui->complexTableWidget->setHorizontalHeaderLabels(QStringList() << "Имя" << "Возраст");

    ui->fileSortTableWidget->setColumnCount(2);
    ui->fileSortTableWidget->setHorizontalHeaderLabels(QStringList() << "Имя" << "Возраст");
}

UI::~UI()
{
    delete ui;
}

void UI::on_sortIntegersButton_clicked()
{
    // Используем DynamicArray<int>
    DynamicArray<int> dynData;
    for (int i = 0; i < 10; ++i) {
        dynData.append(rand() % 100);
    }

    // Сортировка
    ShellSorter<int> sorter;
    sorter.sort(&dynData[0], dynData.getSize());

    // Конвертируем в std::vector для отображения
    std::vector<int> dataVec(dynData.getSize());
    for (size_t i = 0; i < dynData.getSize(); ++i) {
        dataVec[i] = dynData[i];
    }

    // Обновление таблицы
    updateIntegerTable(dataVec);
}

void UI::on_sortIntegersReverseButton_clicked()
{
    // Используем DynamicArray<int>
    DynamicArray<int> dynData;
    for (int i = 0; i < 10; ++i) {
        dynData.append(rand() % 100);
    }

    // Сортировка в обратном порядке
    ShellSorter<int> sorter;
    sorter.sort(&dynData[0], dynData.getSize(), std::greater<int>());

    // Конвертируем в std::vector для отображения
    std::vector<int> dataVec(dynData.getSize());
    for (size_t i = 0; i < dynData.getSize(); ++i) {
        dataVec[i] = dynData[i];
    }

    // Обновление таблицы
    updateReverseIntegerTable(dataVec);
}

void UI::on_sortComplexButton_clicked()
{
    // Используем DynamicArray<Person>
    DynamicArray<Person> dynData;
    dynData.append(Person("Alice", 30));
    dynData.append(Person("Bob", 25));
    dynData.append(Person("Charlie", 35));
    dynData.append(Person("David", 28));

    // Сортировка по возрасту
    QuickSorter<Person> sorter;
    sorter.sort(&dynData[0], dynData.getSize(), Person::compareByAge);

    // Конвертируем в std::vector для отображения
    std::vector<Person> dataVec(dynData.getSize());
    for (size_t i = 0; i < dynData.getSize(); ++i) {
        dataVec[i] = dynData[i];
    }

    // Обновление таблицы
    updateComplexTable(dataVec);
}

void UI::on_selectFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Text Files (*.txt);;All Files (*)");
    if (!fileName.isEmpty()) {
        ui->fileLineEdit->setText(fileName);
    }
}

void UI::on_sortFromFileButton_clicked()
{
    QString fileName = ui->fileLineEdit->text();
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите файл.");
        return;
    }

    std::ifstream file(fileName.toStdString());
    if (!file.is_open()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }

    // Чтение данных из файла
    DynamicArray<Person> dynData;
    while (!file.eof()) {
        Person p;
        p.readFromFile(file);
        if (!p.getName().empty()) {
            dynData.append(p);
        }
    }
    file.close();

    // Сортировка по имени
    HeapSorter<Person> sorter;
    sorter.sort(&dynData[0], dynData.getSize(), Person::compareByName);

    // Конвертируем в std::vector для отображения
    std::vector<Person> dataVec(dynData.getSize());
    for (size_t i = 0; i < dynData.getSize(); ++i) {
        dataVec[i] = dynData[i];
    }

    // Обновление таблицы
    updateFileSortTable(dataVec);
}
void UI::on_runBenchmarkButton_clicked()
{
    // Векторы для хранения данных бенчмарка для каждого сортировщика
    std::vector<std::pair<size_t, double>> shellData;
    std::vector<std::pair<size_t, double>> quickData;
    std::vector<std::pair<size_t, double>> heapData;

    // Проведение бенчмарка для разных размеров данных
    for (size_t size = 1000; size <= 5000000; size += 500000) {
        // Создание случайных данных
        std::vector<int> dataVec(size);
        for (size_t i = 0; i < size; ++i) {
            dataVec[i] = rand() % 10000;
        }

        // Сортировка Шелла
        {
            std::vector<int> data = dataVec; // Копируем данные
            auto start = std::chrono::high_resolution_clock::now();

            ShellSorter<int> sorter;
            sorter.sort(data.data(), data.size());

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            shellData.emplace_back(size, duration.count());
        }// Быстрая сортировка
        {
            std::vector<int> data = dataVec; // Копируем данные
            auto start = std::chrono::high_resolution_clock::now();

            QuickSorter<int> sorter;
            sorter.sort(data.data(), data.size());

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            quickData.emplace_back(size, duration.count());
        }

        // Сортировка кучей
        {
            std::vector<int> data = dataVec; // Копируем данные
            auto start = std::chrono::high_resolution_clock::now();

            HeapSorter<int> sorter;
            sorter.sort(data.data(), data.size());

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;

            heapData.emplace_back(size, duration.count());
        }
    }

    // Обновление графика с новыми данными
    updateBenchmarkChart(shellData, quickData, heapData);
}



void UI::updateIntegerTable(const std::vector<int>& data)
{
    ui->integerTableWidget->setRowCount(static_cast<int>(data.size()));
    for (size_t i = 0; i < data.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[i]));
        ui->integerTableWidget->setItem(static_cast<int>(i), 0, item);
    }
}

void UI::updateReverseIntegerTable(const std::vector<int>& data)
{
    ui->reverseIntegerTableWidget->setRowCount(static_cast<int>(data.size()));
    for (size_t i = 0; i < data.size(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[i]));
        ui->reverseIntegerTableWidget->setItem(static_cast<int>(i), 0, item);
    }
}

void UI::updateComplexTable(const std::vector<Person>& data)
{
    ui->complexTableWidget->setRowCount(static_cast<int>(data.size()));
    for (size_t i = 0; i < data.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(data[i].getName()));
        QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(data[i].getAge()));
        ui->complexTableWidget->setItem(static_cast<int>(i), 0, nameItem);
        ui->complexTableWidget->setItem(static_cast<int>(i), 1, ageItem);
    }
}

void UI::updateFileSortTable(const std::vector<Person>& data)
{
    ui->fileSortTableWidget->setRowCount(static_cast<int>(data.size()));
    for (size_t i = 0; i < data.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(QString::fromStdString(data[i].getName()));
        QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(data[i].getAge()));
        ui->fileSortTableWidget->setItem(static_cast<int>(i), 0, nameItem);
        ui->fileSortTableWidget->setItem(static_cast<int>(i), 1, ageItem);
    }
}

void UI::updateBenchmarkChart(
    const std::vector<std::pair<size_t, double>>& shellData,
    const std::vector<std::pair<size_t, double>>& quickData,
    const std::vector<std::pair<size_t, double>>& heapData)
{
    // Создание серий данных для каждого сортировщика
    QtCharts::QLineSeries *shellSeries = new QtCharts::QLineSeries();
    shellSeries->setName("Shell Sort");

    QtCharts::QLineSeries *quickSeries = new QtCharts::QLineSeries();
    quickSeries->setName("Quick Sort");

    QtCharts::QLineSeries *heapSeries = new QtCharts::QLineSeries();
    heapSeries->setName("Heap Sort");

    for (const auto& point : shellData) {
        shellSeries->append(static_cast<qreal>(point.first), static_cast<qreal>(point.second));
    }

    for (const auto& point : quickData) {
        quickSeries->append(static_cast<qreal>(point.first), static_cast<qreal>(point.second));
    }

    for (const auto& point : heapData) {
        heapSeries->append(static_cast<qreal>(point.first), static_cast<qreal>(point.second));
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(shellSeries);
    chart->addSeries(quickSeries);
    chart->addSeries(heapSeries);
    chart->setTitle("Бенчмарк сортировок");

    // Настройка осей
    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis();
    axisX->setTitleText("Размер данных");
    axisX->setLabelFormat("%d");

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Время (мс)");
    axisY->setLabelFormat("%.2f");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // Привязка серий к осям
    shellSeries->attachAxis(axisX);
    shellSeries->attachAxis(axisY);

    quickSeries->attachAxis(axisX);
    quickSeries->attachAxis(axisY);

    heapSeries->attachAxis(axisX);
    heapSeries->attachAxis(axisY);

    // Настройка легенды
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->benchmarkChartView->setChart(chart);
    ui->benchmarkChartView->setRenderHint(QPainter::Antialiasing);
}
