//
// Created by huangzewu on 26/02/2018.
//
#include <set>
#include <iostream>
#include "../m-color/graph_color.h"
using namespace std;

GraphColor::GraphColor(int nodeCount) : nodeCount_(nodeCount) {}

void GraphColor::init(vector<pair<int,int>> edges) {
    // allocate space
    setColorStatus_= new bool[nodeCount_];
    nodes_ = new Node[nodeCount_];
    matrix_ = new int*[nodeCount_];
    for(int i=0; i<nodeCount_;i++) {
        setColorStatus_[i] = false;
        matrix_[i] = new int[nodeCount_]();
    }

    //assign data
    for(auto it : edges) {
        matrix_[it.first][it.second] = 1;
        matrix_[it.second][it.first] = 1;
    }
}

void GraphColor::initNodeList(int* nodeNumList) {
    for(int i=0; i<nodeCount_;i++) {
        nodes_[i].init(nodeNumList[i]);
    }
}

GraphColor::~GraphColor() {
    delete[] nodes_;
    for(int i = 0; i < nodeCount_; i++) {
        delete[] matrix_[i];
    }
    delete  matrix_;
}



void GraphColor::setAllNodeColor() {
    for(int i=0; i < nodeCount_; i++) {
        setColoratNode(nodes_[i]);
    }
}

void GraphColor::setColoratNode(Node node) {
    if (node.isSetColor()) return;
    int t = 1;
    bool flag;
    do {
        flag = false;
        for(int i=0; i< nodeCount_; i++) {
            if(matrix_[node.id()][i] == 1 && nodes_[i].color() == t) {
                flag = true;
                t++;
                break;
            }
        }
    } while(flag);
    nodes_[node.id()].setColor(t);
    setColorStatus_[node.id()] = true;

    for(int i=0; i<nodeCount_;i++) {
        if(matrix_[node.id()][i] && !setColorStatus_[i]) {
            setColoratNode(nodes_[i]);
        }
    }
}

void GraphColor::printSolution() {
    set<int> temp;
    cout<<"Color Soluction is:"<<endl;
    for(int i = 0; i < nodeCount_; i++) {
        temp.insert(nodes_[i].color());
        cout<<nodes_[i].id()<<" has "<<nodes_[i].color()<<" color"<<endl;
    }
    cout<<"Color Count is: "<<temp.size()<<endl;

}
void GraphColor::printForDebug() {//for debug
    cout<<"Matrix is:"<<endl;
    for(int i = 0; i < nodeCount_; i++) {
        for(int j = 0; j < nodeCount_; j++) {
            cout<<matrix_[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Nodes are:"<<endl;
    for(int i = 0; i < nodeCount_; i++) {
        cout<<"id is: "<<nodes_[i].id()<<" color is: "<<nodes_[i].color()<<" isSetColor: "<<nodes_[i].isSetColor()<<endl;
    }
}

