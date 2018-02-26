//
// Created by huangzewu on 08/02/2018.
//

#include "gtest.h"
#include "../source/MiniSpanTree/minispantree.h"
#include <vector>
using namespace std;

TEST(minispantree, minispantree) {
    EXPECT_TRUE(1==1);
    vector<Arc> data;

    data.push_back(Arc('A', 'B', 6));
    data.push_back(Arc('A', 'C', 1));
    data.push_back(Arc('A', 'D', 5));
    data.push_back(Arc('B', 'C', 5));
    data.push_back(Arc('B', 'E', 3));
    data.push_back(Arc('C', 'D', 5));
    data.push_back(Arc('C', 'E', 6));
    data.push_back(Arc('C', 'F', 4));
    data.push_back(Arc('D', 'F', 2));
    data.push_back(Arc('C', 'F', 6));
    Graph graph;
    graph.createGraph(data);

    graph.kruskal();

    graph.print();

}

