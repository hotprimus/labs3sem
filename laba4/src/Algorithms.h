#pragma once

#include "Graph.h"
#include <vector>
#include <set>

namespace Algorithms {

void DFS(const Graph& graph, int startVertex, std::vector<int>& visitedOrder);
void BFS(const Graph& graph, int startVertex, std::vector<int>& visitedOrder);
std::vector<std::pair<int, int>> KruskalMST(const Graph& graph);
std::vector<std::set<int>> ConnectedComponents(const Graph& graph);
std::vector<std::set<int>> StronglyConnectedComponents(const Graph& graph);
bool TopologicalSort(const Graph& graph, std::vector<int>& sortedVertices);

}


