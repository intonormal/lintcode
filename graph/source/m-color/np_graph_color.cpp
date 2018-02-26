//
// Created by huangzewu on 26/02/2018.
//

#include "np_graph_color.h"
using namespace std;

void NPGraphColor::setColorForAllPermutation(int numofNode, GraphColor &graph) {
    int num = numOfAllPermutation(numofNode);

    int **permutations = mallocMemoryForAllPermutation(num, numofNode);
    initAllPermutation(permutations, numofNode);
    for(int i=0; i<num; i++) {
        graph.initNodeList(permutations[i]);
        graph.setAllNodeColor();
        graph.printSolution();
    }

    freeMemoryForAllPermutation(permutations, num);
}

int NPGraphColor::numOfAllPermutation(int num) {
    if(num== 0 || num== 1) {
        return 1;
    } else {
        return num * numOfAllPermutation(num-1);
    }
}

int** NPGraphColor::mallocMemoryForAllPermutation(int num, int numofNode) {

    int** permutations = new int*[num];
    for(int i=0; i<num; i++) {
        permutations[i] = new int[numofNode];
    }
    return permutations;
}

void NPGraphColor::initAllPermutation(int** permutations, int numofNode) {
    int indOfNode[numofNode];
    for(int i=0; i<numofNode; i++) {
        indOfNode[i] = i;
    }
    int indOfpermutations=0;
    do
    {
        for(int i=0; i<numofNode; i++) {
            permutations[indOfpermutations][i] =  indOfNode[i];
        }
        indOfpermutations++;
    }while(next_permutation(indOfNode,indOfNode+numofNode));
}

void NPGraphColor::freeMemoryForAllPermutation(int** permutations, int num) {
    for(int i=0; i<num; i++) {
        delete[] permutations[i];
    }
    delete permutations;
}

