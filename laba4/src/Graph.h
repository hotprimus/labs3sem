#pragma once

#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>

class Graph {
public:
    Graph(bool directed = false);

    void addEdge(int u, int v, int weight = 1);
    void removeEdge(int u, int v);
    bool hasEdge(int u, int v) const;  
    void clear();
    const std::map<int, std::list<std::pair<int, int>>>& getAdjacencyList() const;
    std::vector<int> getVertices() const;
    bool isDirected() const;

    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

private:
    std::map<int, std::list<std::pair<int, int>>> adjacencyList;
    bool directed;
};

