//
// Created by huangzewu on 08/02/2018.
//
#include "minispantree.h"
#include <climits>
#include <iostream>
using namespace std;
Arc::Arc() : v1_(' '), v2_(' '), cost_(0), used_(false) {}

Arc::Arc(char v1, char v2, int cost, bool used) : v1_(v1), v2_(v2), cost_(cost), used_(used) {}

void Arc::operator=(Arc& right) {
    v1_ = right.v1_;
    v2_ = right.v2_;
    cost_ = right.cost_;
    used_ = right.used_;
}

int Arc::getCost() {
    return cost_;
}

void Arc::setStatus(bool status) {
    used_ =  status;
}
bool Arc::getStatus() {
    return used_;
}

char& Arc::getPoint1() {
    return v1_;
}

char& Arc::getPoint2() {
    return v2_;
}

void Graph::createGraph(std::vector<Arc> arc) {
    for(std::vector<Arc>::iterator iter= arc.begin(); iter != arc.end(); iter++) {
        ori_arc_.push_back(*iter);
    }
}

Arc* Graph::findNotusedAndMinCostArc() {
    int cost = INT_MAX;
    Arc* temp = NULL;
    for(std::vector<Arc>::iterator iter= ori_arc_.begin(); iter != ori_arc_.end(); iter++) {
        if(!iter->getStatus() && iter->getCost() < cost) {
            temp = (Arc*)&(*iter);
            cost =  iter->getCost();
        }
    }
    return temp;
}

bool Graph::isArcSameSubTree(Arc& arc) {
    for(std::vector<std::set<char>>::iterator it = subStree.begin(); it != subStree.end(); it++) {
        bool flag1= false;
        bool flag2= false;
        for(std::set<char>::iterator chit = it->begin(); chit != it->end(); chit++) {
            if(arc.getPoint1() == *chit)
                flag1 = true;
            if(arc.getPoint2() == *chit)
                flag2 = true;
        }
        if(flag1 && flag2) {
            return true;
        }
        if(!flag1 && flag2) {
            it->insert(arc.getPoint1());
            return false;
        }
        if(flag1 && !flag2) {
            it->insert(arc.getPoint2());
            return false;
        }
    }
    std::set<char> temp;
    temp.insert(arc.getPoint1());
    temp.insert(arc.getPoint2());
    subStree.push_back(temp);
    return false;
}

namespace {
    bool isIntersect(std::set<char> right, std::set<char> left) {
        for (std::set<char>::iterator it=right.begin(); it!=right.end(); ++it) {
            if(left.count(*it) != 0) {
                return true;
            }
        }
        return false;
    }

    void combain(std::set<char> right, std::set<char> left) {
        for (std::set<char>::iterator it=right.begin(); it!=right.end(); ++it) {
            left.insert(*it);
        }
    }
}
void Graph::mergeSubTree() {
    for(int i = 0; i < subStree.size(); i++) {
        for(int j = 0; j < subStree.size() && i != j; j++) {
            if(isIntersect(subStree[i], subStree[j])) {
                combain(subStree[i], subStree[j]);
                subStree[i].clear();
            }
        }
    }
}

int Graph::getVecCnt() {
    std::set<char> temp;
    for(std::vector<Arc>::iterator iter= ori_arc_.begin(); iter != ori_arc_.end(); iter++) {
        temp.insert(iter->getPoint1());
        temp.insert(iter->getPoint2());
    }
    return temp.size();
}
void Graph::kruskal() {
    int arcNum = getVecCnt()-1;
    for(int i=0; i < arcNum; i++) {
        Arc* temp = findNotusedAndMinCostArc();
        if(!isArcSameSubTree(*temp)) {
            mergeSubTree();
            temp->setStatus(true);
            ret_arc_.push_back(*temp);
        }
    }
}

void Graph::print() {
    for(std::vector<Arc>::iterator iter= ret_arc_.begin(); iter != ret_arc_.end(); iter++) {
        cout<<iter->getPoint1()<<"<-->"<<iter->getPoint2()<<endl;
    }
}