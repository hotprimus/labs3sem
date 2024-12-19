#pragma once

#include "Graph.h"
#include <set>
#include <vector>

class HasseDiagram {
public:
    HasseDiagram();
    ~HasseDiagram();
    void buildFromPartialOrder(const std::set<int>& elements, const std::vector<std::pair<int, int>>& relations);
    const Graph& getGraph() const;
    void transitiveReduction();
private:
    Graph diagram;
};
