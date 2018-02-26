//
// Created by huangzewu on 07/02/2018.
//
//http://blog.csdn.net/qq_35644234/article/details/60870719
#include "dijkstra.h"
#include <iostream>
using namespace std;

Graph_DG::Graph_DG(int vexnum, int edge) : vexnum(vexnum), edge(edge) {
    arc = new int*[vexnum];
    for(int i = 0; i < vexnum; i++) {
        arc[i] = new int[vexnum];
        for(int j = 0; j < vexnum; j++) {
            arc[i][j] = INT_MAX;
        }
    }
    dis = new Dis[vexnum];
}

Graph_DG::~Graph_DG() {
    delete[] dis;
    for(int i = 0; i < vexnum; i++){
        delete arc[i];
    }
    delete arc;
}

bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if(start < 1 || end < 1 || start > vexnum || end > vexnum || weight < 0)
        return false;
    return true;
}

void Graph_DG::createGraph() {
    int points = 6;
    int data[6][6] = {{0, -1, 10, -1, 30, 100}, {-1,0, 5, -1, -1, -1}, {-1, -1, 0, 50, -1, -1},
                      {-1, -1, -1, 0, -1, 30}, {-1, -1, -1, 20, 0, 60}, {-1, -1, -1, -1,-1,0} };

    for(int i = 0; i < points; i++) {
        for(int j = 0; j < points; j++) {
            if(data[i][j] != -1) {
                arc[i][j] = data[i][j];
            }
        }
    }

//    cout<< "please input start, end and wight for each edge"<<endl;
//    int start, end, weight;
//    int count = 0;
//    while(count != edge) {
//        cout<<"abc"<<endl;
//        count++;
//        cin>>start>>end>>weight;
//        while(!check_edge_value(start, end, weight)){
//            cout<< "invalid input, please check and input again"<<endl;
//            cin>>start>>end>>weight;
//        }
//        arc[start-1][end-1] = weight;
//    }
}

void Graph_DG::print() {
    cout<<"Graph neighbour is:"<<endl;
    int row = 0;
    while (row < vexnum) {
        int col = 0;
        while(col < vexnum) {
            if (arc[row][col] == INT_MAX)
                cout<<"% ";
            else
                cout<<arc[row][col]<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}

void Graph_DG::Dijkstra(int begin) {
    for(int i = 0; i < vexnum; i++) {
        dis[i].setPath("v"+to_string(begin)+"-->v"+to_string(i+1));
        dis[i].setValue(arc[begin-1][i]);
    }
    dis[begin-1].setValue(0);
    dis[begin-1].setVisit(true);

    int count = 1;
    while(count != vexnum) {
        int temp = 0;
        int min = INT_MAX;
        for(int i = 0; i < vexnum; i++) {
            if(!dis[i].isVisit() && dis[i].getValue() < min) {
                min = dis[i].getValue();
                temp = i;
            }
        }
        dis[temp].setVisit(true);
        count++;

        for(int i = 0; i < vexnum; i++) {
            if(!dis[i].isVisit() && arc[temp][i] != INT_MAX && dis[temp].getValue() + arc[temp][i] < dis[i].getValue()) {
                dis[i].setValue(dis[temp].getValue() + arc[temp][i]);
                dis[i].setPath(dis[temp].getPath()+"-->v"+to_string(i+1));
            }
        }
    }
}

void Graph_DG::print_path() {
    cout<<"min path of begin as start:"<<endl;
    for(int i = 0; i != vexnum; i++) {
        if(dis[i].getValue() != INT_MAX) {
            cout<<dis[i].getPath()<<"="<<dis[i].getValue()<<endl;
        } else {
            cout<<dis[i].getPath()<<"hasn't min path"<<endl;
        }
    }
}