//
// Created by huangzewu on 26/02/2018.
//

#ifndef LINTCODE_GRAPH_COLOR_H
#define LINTCODE_GRAPH_COLOR_H
#include <vector>
#include "node.h"

struct GraphColor {
    GraphColor(int nodeCount);
    void init(std::vector<std::pair<int,int>> edges);
    ~GraphColor();
    void setAllNodeColor();
    void printSolution();
    void printForDebug();
    void initNodeList(int *nodeNumList);
    void setColoratNode(Node node);

private:
    int nodeCount_;
    Node *nodes_;
    bool* setColorStatus_;
    int** matrix_;
};

#endif //LINTCODE_GRAPH_COLOR_H
