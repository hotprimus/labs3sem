#pragma once

#include <QMainWindow>
#include "Graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void loadGraph();
    void saveGraph();
    void runAlgorithm();
private:
    Ui::MainWindow *ui;
    Graph graph;
    void displayGraph();
    void displayResults(const std::vector<int>& result);
    void displayResults(const std::vector<std::pair<int, int>>& edges);
    void displayComponents(const std::vector<std::set<int>>& components);
    void displayHasseDiagram(const Graph& hasseGraph);
};

