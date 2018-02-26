//
// Created by huangzewu on 26/02/2018.
//

#include "gtest.h"
#include "../source/m-color/np_graph_color.h"

using namespace std;

TEST(GraphColor, firsttest) {
    int vexnum = 4;
    std::vector<std::pair<int,int>> edges;
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(1,3));
    GraphColor graph(vexnum);
    graph.init(edges);
    NPGraphColor npGraphColor;
    npGraphColor.setColorForAllPermutation(4, graph);
}