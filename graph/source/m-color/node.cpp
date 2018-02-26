//
// Created by huangzewu on 26/02/2018.
//

#include "node.h"

Node::Node():id_(0), color_(0), isSetColor_(false) {/**/}

Node::Node(int id, int color) : id_(id), color_(color), isSetColor_(false) {/**/}

void Node::setColor(int color) {
    color_ = color;
    isSetColor_ = true;
}

bool Node::isSetColor() { return isSetColor_; }

int Node::id() { return id_; }

void Node::init(int id) {
    id_ = id;
    color_ = 0;
    isSetColor_ = false;
}

int Node::color() {
    return color_;
}
