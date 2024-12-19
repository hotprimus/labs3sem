#pragma once

#include "../Algorithms.h"
#include <cassert>
#include <iostream>

void runAlgorithmsTests() {
    std::cout << "Running Algorithms tests..." << std::endl;
    Graph graph(false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    std::vector<int> dfsOrder;
    Algorithms::DFS(graph, 0, dfsOrder);
    assert(dfsOrder.size() == 4);
    std::vector<int> bfsOrder;
    Algorithms::BFS(graph, 0, bfsOrder);
    assert(bfsOrder.size() == 4);
    auto mstEdges = Algorithms::KruskalMST(graph);
    assert(mstEdges.size() == 3);
    auto components = Algorithms::ConnectedComponents(graph);
    assert(components.size() == 1);
    Graph dag(true);
    dag.addEdge(5, 2);
    dag.addEdge(5, 0);
    dag.addEdge(4, 0);
    dag.addEdge(4, 1);
    dag.addEdge(2, 3);
    dag.addEdge(3, 1);
    std::vector<int> topoSortResult;
    bool acyclic = Algorithms::TopologicalSort(dag, topoSortResult);
    assert(acyclic);
    assert(topoSortResult.size() == 6);
    dag.addEdge(1, 5);
    topoSortResult.clear();
    acyclic = Algorithms::TopologicalSort(dag, topoSortResult);
    assert(!acyclic);
    std::cout << "Algorithms tests passed!" << std::endl;
}


