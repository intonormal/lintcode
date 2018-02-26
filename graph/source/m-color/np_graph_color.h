//
// Created by huangzewu on 26/02/2018.
//

#ifndef LINTCODE_NP_GRAPH_COLOR_H
#define LINTCODE_NP_GRAPH_COLOR_H
#include "graph_color.h"

struct NPGraphColor {
    int numOfAllPermutation(int num);

    void setColorForAllPermutation(int numofNode, GraphColor &graph);

    int **mallocMemoryForAllPermutation(int num, int numofNode);

    void freeMemoryForAllPermutation(int **pInt, int num);

    void initAllPermutation(int **permutations, int numofNode);
};


#endif //LINTCODE_NP_GRAPH_COLOR_H
