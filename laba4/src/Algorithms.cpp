#include "Algorithms.h"
#include <algorithm>
#include <queue>
#include <stack>

namespace Algorithms {

void DFSUtil(const Graph& graph, int vertex, std::set<int>& visited, std::vector<int>& visitedOrder) {
    visited.insert(vertex);
    visitedOrder.push_back(vertex);
    const auto& adjList = graph.getAdjacencyList();
    auto it = adjList.find(vertex);
    if (it != adjList.end()) {
        for (const auto& neighbor : it->second) {
            if (visited.find(neighbor.first) == visited.end()) {
                DFSUtil(graph, neighbor.first, visited, visitedOrder);
            }
        }
    }
}

void DFS(const Graph& graph, int startVertex, std::vector<int>& visitedOrder) {
    std::set<int> visited;
    DFSUtil(graph, startVertex, visited, visitedOrder);
}

void BFS(const Graph& graph, int startVertex, std::vector<int>& visitedOrder) {
    std::set<int> visited;
    std::queue<int> q;
    visited.insert(startVertex);
    q.push(startVertex);
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        visitedOrder.push_back(vertex);
        const auto& adjList = graph.getAdjacencyList();
        auto it = adjList.find(vertex);
        if (it != adjList.end()) {
            for (const auto& neighbor : it->second) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    q.push(neighbor.first);
                }
            }
        }
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int Find(int u, std::vector<int>& parent) {
    if (parent[u] != u)
        parent[u] = Find(parent[u], parent);
    return parent[u];
}

void Union(int u, int v, std::vector<int>& parent, std::vector<int>& rank) {
    int uRoot = Find(u, parent);
    int vRoot = Find(v, parent);
    if (uRoot != vRoot) {
        if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        } else if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }
}

std::vector<std::pair<int, int>> KruskalMST(const Graph& graph) {
    std::vector<Edge> edges;
    const auto& adjList = graph.getAdjacencyList();
    std::set<std::pair<int, int>> processedEdges;
    for (const auto& kv : adjList) {
        int u = kv.first;
        for (const auto& pair : kv.second) {
            int v = pair.first;
            int weight = pair.second;
            if (graph.isDirected() || processedEdges.find({v, u}) == processedEdges.end()) {
                edges.push_back({u, v, weight});
                processedEdges.insert({u, v});
            }
        }
    }
    std::sort(edges.begin(), edges.end());
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> vertices = graph.getVertices();
    int n = vertices.size();
    parent.resize(n);
    rank.resize(n, 0);
    std::map<int, int> vertexToIndex;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        vertexToIndex[vertices[i]] = i;
    }
    std::vector<std::pair<int, int>> mst;
    for (const auto& edge : edges) {
        int uIdx = vertexToIndex[edge.u];
        int vIdx = vertexToIndex[edge.v];
        if (Find(uIdx, parent) != Find(vIdx, parent)) {
            mst.push_back({edge.u, edge.v});
            Union(uIdx, vIdx, parent, rank);
        }
    }
    return mst;
}

void DFSConnectedComponents(const Graph& graph, int vertex, std::set<int>& visited, std::set<int>& component) {
    visited.insert(vertex);
    component.insert(vertex);
    const auto& adjList = graph.getAdjacencyList();
    auto it = adjList.find(vertex);
    if (it != adjList.end()) {
        for (const auto& neighbor : it->second) {
            if (visited.find(neighbor.first) == visited.end()) {
                DFSConnectedComponents(graph, neighbor.first, visited, component);
            }
        }
    }
}

std::vector<std::set<int>> ConnectedComponents(const Graph& graph) {
    std::vector<std::set<int>> components;
    std::set<int> visited;
    for (const auto& kv : graph.getAdjacencyList()) {
        int vertex = kv.first;
        if (visited.find(vertex) == visited.end()) {
            std::set<int> component;
            DFSConnectedComponents(graph, vertex, visited, component);
            components.push_back(component);
        }
    }
    return components;
}

void TarjanSCCUtil(const Graph& graph, int u, int& time,
                   std::map<int, int>& disc, std::map<int, int>& low,
                   std::stack<int>& st, std::set<int>& stackMember,
                   std::vector<std::set<int>>& scc) {
    const auto& adjList = graph.getAdjacencyList();
    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember.insert(u);
    auto it = adjList.find(u);
    if (it != adjList.end()) {
        for (const auto& neighbor : it->second) {
            int v = neighbor.first;
            if (disc[v] == -1) {
                TarjanSCCUtil(graph, v, time, disc, low, st, stackMember, scc);
                low[u] = std::min(low[u], low[v]);
            } else if (stackMember.find(v) != stackMember.end()) {
                low[u] = std::min(low[u], disc[v]);
            }
        }
    }
    int w = 0;
    if (low[u] == disc[u]) {
        std::set<int> component;
        while (st.top() != u) {
            w = st.top();
            component.insert(w);
            stackMember.erase(w);
            st.pop();
        }
        w = st.top();
        component.insert(w);
        stackMember.erase(w);
        st.pop();
        scc.push_back(component);
    }
}

std::vector<std::set<int>> StronglyConnectedComponents(const Graph& graph) {
    int time = 0;
    std::map<int, int> disc;
    std::map<int, int> low;
    std::stack<int> st;
    std::set<int> stackMember;
    std::vector<std::set<int>> scc;
    for (const auto& kv : graph.getAdjacencyList()) {
        int u = kv.first;
        disc[u] = -1;
        low[u] = -1;
    }
    for (const auto& kv : graph.getAdjacencyList()) {
        int u = kv.first;
        if (disc[u] == -1) {
            TarjanSCCUtil(graph, u, time, disc, low, st, stackMember, scc);
        }
    }
    return scc;
}

bool TopologicalSortUtil(const Graph& graph, int v, std::set<int>& visited, std::set<int>& recStack, std::vector<int>& result) {
    visited.insert(v);
    recStack.insert(v);
    const auto& adjList = graph.getAdjacencyList();
    auto it = adjList.find(v);
    if (it != adjList.end()) {
        for (const auto& neighbor : it->second) {
            int u = neighbor.first;
            if (recStack.find(u) != recStack.end()) {
                return false;
            }
            if (visited.find(u) == visited.end()) {
                if (!TopologicalSortUtil(graph, u, visited, recStack, result))
                    return false;
            }
        }
    }
    recStack.erase(v);
    result.push_back(v);
    return true;
}

bool TopologicalSort(const Graph& graph, std::vector<int>& sortedVertices) {
    std::set<int> visited;
    std::set<int> recStack;
    for (const auto& kv : graph.getAdjacencyList()) {
        int vertex = kv.first;
        if (visited.find(vertex) == visited.end()) {
            if (!TopologicalSortUtil(graph, vertex, visited, recStack, sortedVertices))
                return false;
        }
    }
    std::reverse(sortedVertices.begin(), sortedVertices.end());
    return true;
}

}
