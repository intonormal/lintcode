//
// Created by huangzewu on 07/02/2018.
//

#ifndef LINTCODE_DIJKSTRA_H
#define LINTCODE_DIJKSTRA_H

#include<iostream>

struct Dis {
    Dis(): path_(""), value_(0), visit_(false) {}

    void setPath(std::string path) { path_ = path; }

    std::string getPath() { return path_; }

    void setValue(int value) { value_ = value; }

    int getValue() { return value_; }

    void setVisit(bool status) { visit_ = status; }

    bool isVisit() { return visit_; }

    void print() {
        std::cout<< "path:"<<path_<<"value"<<value_<<"visit"<<visit_<<std::endl;
    }

private:
    std::string path_;
    int value_;
    bool visit_;
};

struct Graph_DG {
    Graph_DG(int vexnum, int edge);
    ~Graph_DG();

    bool check_edge_value(int start, int end, int weight);
    void createGraph();

    void print();

    void Dijkstra(int begin);
    void print_path();

private:
    int vexnum;
    int edge;
    int ** arc;
    Dis* dis;
};

#endif //LINTCODE_DIJKSTRA_H
