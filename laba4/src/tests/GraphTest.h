#pragma once

#include "../Graph.h"
#include <cassert>
#include <iostream>

void runGraphTests() {
    std::cout << "Running Graph tests..." << std::endl;
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    assert(graph.getAdjacencyList().size() == 3);
    graph.removeEdge(2, 3);
    graph.removeEdge(1, 2); 
    assert(graph.getAdjacencyList().at(2).size() == 0);
    graph.clear();
    assert(graph.getAdjacencyList().empty());
    std::cout << "Graph tests passed!" << std::endl;
}


