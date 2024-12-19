#include "MainWindow.h"
#include <QMessageBox>
#include "Utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUi();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    QGroupBox *paramsGroup = new QGroupBox("Параметры гистограммы");
    QGridLayout *paramsLayout = new QGridLayout();

    QLabel *criterionLabel = new QLabel("Критерий:");
    criterionComboBox = new QComboBox();
    criterionComboBox->addItems({"Возраст", "Рост", "Вес"});

    QLabel *minValueLabel = new QLabel("Минимальное значение:");
    minValueEdit = new QLineEdit();

    QLabel *maxValueLabel = new QLabel("Максимальное значение:");
    maxValueEdit = new QLineEdit();

    QLabel *numberOfRangesLabel = new QLabel("Количество диапазонов:");
    numberOfRangesEdit = new QLineEdit();

    chooseFileButton = new QPushButton("Выбрать файл CSV");
    connect(chooseFileButton, &QPushButton::clicked, this, &MainWindow::onChooseFile);

    filePathLabel = new QLabel("Файл не выбран");

    buildHistogramButton = new QPushButton("Построить гистограмму");
    connect(buildHistogramButton, &QPushButton::clicked, this, &MainWindow::onBuildHistogram);

    paramsLayout->addWidget(criterionLabel, 0, 0);
    paramsLayout->addWidget(criterionComboBox, 0, 1);
    paramsLayout->addWidget(minValueLabel, 1, 0);
    paramsLayout->addWidget(minValueEdit, 1, 1);
    paramsLayout->addWidget(maxValueLabel, 2, 0);
    paramsLayout->addWidget(maxValueEdit, 2, 1);
    paramsLayout->addWidget(numberOfRangesLabel, 3, 0);
    paramsLayout->addWidget(numberOfRangesEdit, 3, 1);
    paramsLayout->addWidget(chooseFileButton, 4, 0);
    paramsLayout->addWidget(filePathLabel, 4, 1);
    paramsLayout->addWidget(buildHistogramButton, 5, 0, 1, 2);

    paramsGroup->setLayout(paramsLayout);

    chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);

    resultsTableWidget = new QTableWidget();
    resultsTableWidget->setColumnCount(4);
    resultsTableWidget->setHorizontalHeaderLabels({"Диапазон", "Количество", "Среднее", "Ср.квад.откл."});
    resultsTableWidget->horizontalHeader()->setStretchLastSection(true);

    mainLayout->addWidget(paramsGroup);
    mainLayout->addWidget(chartView);
    mainLayout->addWidget(resultsTableWidget);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle("Генератор гистограмм");
    resize(800, 600);
}

void MainWindow::onChooseFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл CSV", "", "CSV Files (*.csv)");
    if (!fileName.isEmpty()) {
        csvFilePath = fileName;
        filePathLabel->setText(fileName);
    }
}

void MainWindow::onBuildHistogram() {
    QString criterion = criterionComboBox->currentText();
    bool minOk, maxOk, rangesOk;
    double minValue = minValueEdit->text().toDouble(&minOk);
    double maxValue = maxValueEdit->text().toDouble(&maxOk);
    size_t numberOfRanges = numberOfRangesEdit->text().toUInt(&rangesOk);

    if (!minOk || !maxOk || !rangesOk || minValue >= maxValue || numberOfRanges == 0) {
        QMessageBox::warning(this, "Некорректные параметры", "Пожалуйста, введите корректные параметры гистограммы.");
        return;
    }

    if (csvFilePath.isEmpty()) {
        QMessageBox::warning(this, "Файл не выбран", "Пожалуйста, выберите CSV файл.");
        return;
    }

    auto ranges = Utils::createUniformRanges(minValue, maxValue, numberOfRanges);
    std::vector<Person> data = Utils::readPersonsFromCSV(csvFilePath.toStdString());

    if (data.empty()) {
        QMessageBox::warning(this, "Ошибка загрузки данных", "Не удалось загрузить данные из CSV файла.");
        return;
    }

    HistogramBuilder<Person> builder;
    builder.setData(data);
    builder.setRanges(ranges);

    if (criterion == "Возраст") {
        builder.setCriterion([](const Person& p) { return static_cast<double>(p.getAge()); });
    } else if (criterion == "Рост") {
        builder.setCriterion([](const Person& p) { return p.getHeight(); });
    } else if (criterion == "Вес") {
        builder.setCriterion([](const Person& p) { return p.getWeight(); });
    } else {
        QMessageBox::warning(this, "Некорректный критерий", "Пожалуйста, выберите корректный критерий.");
        return;
    }

    Histogram<Person> histogram = builder.build();
    displayHistogram(histogram);
}

void MainWindow::displayHistogram(const Histogram<Person> &histogram) {
    resultsTableWidget->setRowCount(0);

    QBarSet *barSet = new QBarSet("Количество");
    QStringList categories;

    int row = 0;
    for (const auto& entry : histogram.getBins()) {
        const auto& range = entry.first;
        const auto& binData = entry.second;

        resultsTableWidget->insertRow(row);
        QString rangeStr = QString("[%1, %2)").arg(range.first).arg(range.second);
        resultsTableWidget->setItem(row, 0, new QTableWidgetItem(rangeStr));
        resultsTableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(binData.count)));
        resultsTableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(binData.mean)));
        resultsTableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(binData.stdDev)));

        *barSet << binData.count;
        categories << rangeStr;

        ++row;
    }

    QBarSeries *series = new QBarSeries();
    series->append(barSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Гистограмма");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(false);

    chartView->setChart(chart);
}
