#include "Graph.h"
#include <fstream>
#include <sstream>
#include <string> // Добавьте эту строку, если получаете ошибки в этом файле

Graph::Graph(bool directed)
    : directed(directed) {}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyList[u].push_back({v, weight});
    if (!directed) {
        adjacencyList[v].push_back({u, weight});
    }
}

void Graph::removeEdge(int u, int v) {
    adjacencyList[u].remove_if([v](const auto& pair){ return pair.first == v; });
    if (!directed) {
        adjacencyList[v].remove_if([u](const auto& pair){ return pair.first == u; });
    }
}

bool Graph::hasEdge(int u, int v) const {
    auto it = adjacencyList.find(u);
    if (it != adjacencyList.end()) {
        for (const auto& neighbor : it->second) {
            if (neighbor.first == v) {
                return true;
            }
        }
    }
    return false;
}

void Graph::clear() {
    adjacencyList.clear();
}

const std::map<int, std::list<std::pair<int, int>>>& Graph::getAdjacencyList() const {
    return adjacencyList;
}

std::vector<int> Graph::getVertices() const {
    std::vector<int> vertices;
    for (const auto& kv : adjacencyList) {
        vertices.push_back(kv.first);
    }
    return vertices;
}

bool Graph::isDirected() const {
    return directed;
}

bool Graph::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    clear();
    int u, v, weight;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ss >> u >> v >> weight;
        addEdge(u, v, weight);
    }
    file.close();
    return true;
}

bool Graph::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    for (const auto& kv : adjacencyList) {
        int u = kv.first;
        for (const auto& pair : kv.second) {
            int v = pair.first;
            int weight = pair.second;
            if (directed || u <= v) {
                file << u << " " << v << " " << weight << "\n";
            }
        }
    }
    file.close();
    return true;
}
