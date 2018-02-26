//
// Created by huangzewu on 07/02/2018.
//
#include "gtest.h"
#include "../source/dijkstra/dijkstra.h"
using namespace std;

TEST(Dijkstra, Dijkstra) {
    int vexnum = 6;
    int edge = 7;
    Graph_DG graph(vexnum, edge);
    graph.createGraph();
    graph.print();
    graph.Dijkstra(1);
    graph.print_path();
}
