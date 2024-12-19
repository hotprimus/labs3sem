#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Algorithms.h"
#include "HasseDiagram.h"
#include <QFileDialog>
#include <QMessageBox>
#include <chrono>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->loadGraphButton, &QPushButton::clicked, this, &MainWindow::loadGraph);
    connect(ui->saveGraphButton, &QPushButton::clicked, this, &MainWindow::saveGraph);
    connect(ui->runAlgorithmButton, &QPushButton::clicked, this, &MainWindow::runAlgorithm);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadGraph() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Graph File", "", "Graph Files (*.txt *.csv)");
    if (!fileName.isEmpty()) {
        if (graph.loadFromFile(fileName.toStdString())) {
            displayGraph();
            QMessageBox::information(this, "Success", "Graph loaded successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to load graph.");
        }
    }
}

void MainWindow::saveGraph() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Graph File", "", "Graph Files (*.txt *.csv)");
    if (!fileName.isEmpty()) {
        if (graph.saveToFile(fileName.toStdString())) {
            QMessageBox::information(this, "Success", "Graph saved successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to save graph.");
        }
    }
}

void MainWindow::runAlgorithm() {
    if (graph.getAdjacencyList().empty()) {
        QMessageBox::warning(this, "Error", "Graph is empty.");
        return;
    }
    int algorithmIndex = ui->algorithmComboBox->currentIndex();
    auto start = std::chrono::high_resolution_clock::now();
    switch (algorithmIndex) {
    case 0: {
        int startVertex = ui->startVertexLineEdit->text().toInt();
        std::vector<int> visitedOrder;
        Algorithms::DFS(graph, startVertex, visitedOrder);
        auto end = std::chrono::high_resolution_clock::now();
        displayResults(visitedOrder);
        std::chrono::duration<double> duration = end - start;
        ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        break;
    }
    case 1: {
        int startVertex = ui->startVertexLineEdit->text().toInt();
        std::vector<int> visitedOrder;
        Algorithms::BFS(graph, startVertex, visitedOrder);
        auto end = std::chrono::high_resolution_clock::now();
        displayResults(visitedOrder);
        std::chrono::duration<double> duration = end - start;
        ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        break;
    }
    case 2: {
        if (graph.isDirected()) {
            QMessageBox::warning(this, "Error", "MST can be found only for undirected graphs.");
            return;
        }
        auto mst = Algorithms::KruskalMST(graph);
        auto end = std::chrono::high_resolution_clock::now();
        displayResults(mst);
        std::chrono::duration<double> duration = end - start;
        ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        break;
    }
    case 3: {
        if (graph.isDirected()) {
            QMessageBox::warning(this, "Error", "Connected components can be found only for undirected graphs.");
            return;
        }
        auto components = Algorithms::ConnectedComponents(graph);
        auto end = std::chrono::high_resolution_clock::now();
        displayComponents(components);
        std::chrono::duration<double> duration = end - start;
        ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        break;
    }
    case 4: {
        if (!graph.isDirected()) {
            QMessageBox::warning(this, "Error", "Strongly connected components can be found only for directed graphs.");
            return;
        }
        auto scc = Algorithms::StronglyConnectedComponents(graph);
        auto end = std::chrono::high_resolution_clock::now();
        displayComponents(scc);
        std::chrono::duration<double> duration = end - start;
        ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        break;
    }
    case 5: {
        if (!graph.isDirected()) {
            QMessageBox::warning(this, "Error", "Topological sort can be performed only on directed graphs.");
            return;
        }
        std::vector<int> sortedVertices;
        bool acyclic = Algorithms::TopologicalSort(graph, sortedVertices);
        auto end = std::chrono::high_resolution_clock::now();
        if (!acyclic) {
            QMessageBox::warning(this, "Error", "Graph contains a cycle, topological sort is not possible.");
        } else {
            displayResults(sortedVertices);
            std::chrono::duration<double> duration = end - start;
            ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        }
        break;
    }
    case 6: {
        std::set<int> elements = {1, 2, 3, 4, 5, 6};
        std::vector<std::pair<int, int>> relations = {
            {1, 2},
            {1, 3},
            {2, 4},
            {3, 4},
            {4, 5},
            {5, 6}
        };
        HasseDiagram hasseDiagram;
        hasseDiagram.buildFromPartialOrder(elements, relations);
        auto end = std::chrono::high_resolution_clock::now();
        displayHasseDiagram(hasseDiagram.getGraph());
        std::chrono::duration<double> duration = end - start;
        ui->timeLabel->setText(QString::number(duration.count(), 'f', 6) + " seconds");
        break;
    }
    default:
        QMessageBox::warning(this, "Error", "Invalid algorithm selected.");
        break;
    }
}

void MainWindow::displayGraph() {
    // Здесь можно реализовать отображение графа
}

void MainWindow::displayResults(const std::vector<int>& result) {
    ui->resultsTextEdit->clear();
    for (int v : result) {
        ui->resultsTextEdit->append(QString::number(v));
    }
}

void MainWindow::displayResults(const std::vector<std::pair<int, int>>& edges) {
    ui->resultsTextEdit->clear();
    for (const auto& edge : edges) {
        ui->resultsTextEdit->append(QString("%1 - %2").arg(edge.first).arg(edge.second));
    }
}

void MainWindow::displayComponents(const std::vector<std::set<int>>& components) {
    ui->resultsTextEdit->clear();
    for (size_t i = 0; i < components.size(); ++i) {
        ui->resultsTextEdit->append(QString("Component %1:").arg(i + 1));
        for (int v : components[i]) {
            ui->resultsTextEdit->insertPlainText(QString::number(v) + " ");
        }
        ui->resultsTextEdit->append("");
    }
}

void MainWindow::displayHasseDiagram(const Graph& hasseGraph) {
    ui->resultsTextEdit->clear();
    const auto& adjList = hasseGraph.getAdjacencyList();
    for (const auto& kv : adjList) {
        int u = kv.first;
        for (const auto& neighbor : kv.second) {
            int v = neighbor.first;
            if (u != v) {
                ui->resultsTextEdit->append(QString("%1 -> %2").arg(u).arg(v));
            }
        }
    }
}
