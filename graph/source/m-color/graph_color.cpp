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
    nodes_ = new Node[nodeCount_];
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

void GraphColor::clearColorSolution() {
    usedColor_.clear();
}

int GraphColor::selectColor(Node& node) {
    if(usedColor_.size() == 0) {
        usedColor_.insert(1);
        return 1;
    }
    set<int> neighboreColor;
    for(int i=0; i< nodeCount_; i++) {
        if(matrix_[node.id()][i] == 1 && nodes_[i].color() != 0) {
            neighboreColor.insert(nodes_[i].color());
        }
    }

    for(auto it = usedColor_.begin(); it != usedColor_.end(); ++it) {
        auto tempIter = neighboreColor.find(*it);
        if(tempIter == neighboreColor.end()) {
            return *it;
        }
    }

    int color = 0;
    for(auto it = usedColor_.begin(); it != usedColor_.end(); ++it) {
        if(color < *it) {
            color = *it;
        }
    }
    usedColor_.insert(++color);
    return color;
}

void GraphColor::setColoratNode(Node& node) {
    if (node.isSetColor()) return;

    int color = selectColor(node);
    for(int i=0; i< nodeCount_; i++) {
        if(nodes_[i].id() == node.id()) {
            nodes_[i].setColor(color);
        }
    }

    for(int i=0; i<nodeCount_;i++) {
        if(matrix_[node.id()][i] == 1) {
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

