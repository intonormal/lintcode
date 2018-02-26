//
// Created by huangzewu on 26/02/2018.
//
#include <set>
#include <iostream>
#include "../m-color/graph_color.h"
using namespace std;
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

GraphColor::GraphColor(int nodeCount) : nodeCount_(nodeCount) {}

void GraphColor::init(vector<pair<int,int>> edges) {
    // allocate space
    color_ = new int[nodeCount_]();
    setColorStatus_= new bool[nodeCount_]();
    for(int i=0; i<nodeCount_;i++) {
        setColorStatus_[i] = false;
    }
    matrix_ = new int*[nodeCount_];
    for(int i=0; i<nodeCount_;i++) {
        matrix_[i] = new int[nodeCount_]();
    }

    //assign data
    for(auto it : edges) {
        matrix_[it.first][it.second] = 1;
        matrix_[it.second][it.first] = 1;
    }
}

GraphColor::~GraphColor() {
    delete[] color_;
    for(int i = 0; i < nodeCount_; i++) {
        delete[] matrix_[i];
    }
    delete  matrix_;
}
void GraphColor::setAllNodeColor() {
    for(int i=0; i < nodeCount_; i++) {
        setColoratNode(i);
    }
}
void GraphColor::setColoratNode(int node) {
    if (setColorStatus_[node]) return;
    int t = 1;
    bool flag;
    do {
        flag = false;
        for(int i=0; i< nodeCount_; i++) {
            if(matrix_[node][i] && color_[i] == t) {
                flag = true;
                t++;
                break;
            }
        }
    } while(flag);
    color_[node] = t;
    setColorStatus_[node] = true;

    for(int i=0; i<nodeCount_;i++) {
        if(matrix_[node][i] && !setColorStatus_[i]) {
            setColoratNode(i);
        }
    }
}

void GraphColor::printSolution() {
    set<int> temp;
    cout<<"Color Soluction is:"<<endl;
    int colorCount = 0;
    for(int i = 0; i < nodeCount_; i++) {
        temp.insert(color_[i]);
        cout<<color_[i]<<" ";
    }
    cout<<endl;
    cout<<"Color Count is: "<<temp.size()<<endl;

}
void GraphColor::printMatrix() {//for debug
    cout<<"Matrix is:"<<endl;
    for(int i = 0; i < nodeCount_; i++) {
        for(int j = 0; j < nodeCount_; j++) {
            cout<<matrix_[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

