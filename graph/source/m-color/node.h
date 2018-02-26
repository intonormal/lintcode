//
// Created by huangzewu on 26/02/2018.
//

#ifndef LINTCODE_NODE_H
#define LINTCODE_NODE_H

struct Node {
    Node();
    Node(int id, int color);
    void setColor(int color);
    bool isSetColor();
    int id();

    void init(int id);

    int color();

private:
    int id_;
    int color_;
    bool isSetColor_;
};



#endif //LINTCODE_NODE_H
