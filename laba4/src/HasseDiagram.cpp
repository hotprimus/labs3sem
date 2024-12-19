#include "HasseDiagram.h"
#include <queue>

HasseDiagram::HasseDiagram() : diagram(true) {
}

HasseDiagram::~HasseDiagram() {
}

void HasseDiagram::buildFromPartialOrder(const std::set<int>& elements, const std::vector<std::pair<int, int>>& relations) {
    diagram.clear();
    for (int element : elements) {
        diagram.addEdge(element, element);
    }
    for (const auto& relation : relations) {
        int u = relation.first;
        int v = relation.second;
        if (u != v) {
            diagram.addEdge(u, v);
        }
    }
    transitiveReduction();
}

const Graph& HasseDiagram::getGraph() const {
    return diagram;
}

void HasseDiagram::transitiveReduction() {
    const auto& adjList = diagram.getAdjacencyList();
    std::set<std::pair<int, int>> edgesToRemove;
    for (const auto& u_pair : adjList) {
        int u = u_pair.first;
        std::set<int> visited;
        std::queue<int> q;
        visited.insert(u);
        q.push(u);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            auto it = adjList.find(current);
            if (it != adjList.end()) {
                for (const auto& neighbor : it->second) {
                    int v = neighbor.first;
                    if (v != u && visited.find(v) == visited.end()) {
                        visited.insert(v);
                        q.push(v);
                        if (diagram.hasEdge(u, v) && u != current) {
                            edgesToRemove.insert({u, v});
                        }
                    }
                }
            }
        }
    }
    for (const auto& edge : edgesToRemove) {
        diagram.removeEdge(edge.first, edge.second);
    }
}
