//
// Created by huangzewu on 26/02/2018.
//

#ifndef LINTCODE_GRAPH_COLOR_H
#define LINTCODE_GRAPH_COLOR_H
#include <vector>
//struct Node {
//    Node(int num, int color) : num_(num), color_(color), isSetColor_(false) {}
//    void setColor(int color) {
//        color_ = color;
//        isSetColor_ = true;
//    }
//    bool isSetColor() { return isSetColor_; }
//private:
//    int num_;
//    int color_;
//    bool isSetColor_;
//};


struct GraphColor {
    GraphColor(int nodeCount);
    void init(std::vector<std::pair<int,int>> edges);
    ~GraphColor();
    void setAllNodeColor();
    void setColoratNode(int node);
    void printSolution();
    void printMatrix();
private:
    int nodeCount_;
    int* color_;
    bool* setColorStatus_;
    int** matrix_;
};

#endif //LINTCODE_GRAPH_COLOR_H
