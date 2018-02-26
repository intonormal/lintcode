//
// Created by huangzewu on 08/02/2018.
//

#ifndef LINTCODE_MINISPANTREE_H
#define LINTCODE_MINISPANTREE_H

#include <climits>
#include <vector>
#include <set>

struct Arc {
    Arc();
    Arc(char v1, char v2, int cost, bool used=false);
    void operator=(Arc& right);
    int getCost();
    void setStatus(bool status);
    bool getStatus();
    char &getPoint1();
    char &getPoint2();

private:
    char v1_;
    char v2_;
    int cost_;
    bool used_;
};

struct Graph {
    void createGraph(std::vector<Arc> arc);

    Arc* findNotusedAndMinCostArc();
    bool isArcSameSubTree(Arc& arc);
    int getVecCnt();
    void kruskal();
    void print();
    void mergeSubTree();
private:
    std::vector<Arc> ori_arc_;
    std::vector<Arc> ret_arc_;
    std::vector<std::set<char>> subStree;
};
#endif //LINTCODE_MINISPANTREE_H
