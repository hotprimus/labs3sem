#pragma once

#include "../HasseDiagram.h"
#include <cassert>
#include <iostream>

void runHasseDiagramTests() {
    std::cout << "Running Hasse Diagram tests..." << std::endl;
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
    const Graph& diagram = hasseDiagram.getGraph();
    assert(!diagram.hasEdge(1, 4));
    assert(!diagram.hasEdge(2, 5));
    assert(diagram.hasEdge(1, 2));
    assert(diagram.hasEdge(1, 3));
    assert(diagram.hasEdge(2, 4));
    assert(diagram.hasEdge(3, 4));
    assert(diagram.hasEdge(4, 5));
    assert(diagram.hasEdge(5, 6));

    std::cout << "Hasse Diagram tests passed!" << std::endl;
}
