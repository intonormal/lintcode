//
// Created by huangzewu on 13/03/2018.
//

#ifndef LINTCODE_RBTREE_H
#define LINTCODE_RBTREE_H

#include <string>

enum Color {
    Red,
    Black
};

struct RBNode {
    RBNode(int key, Color color, RBNode* left, RBNode* right, RBNode* parent) :
            key_(key), color_(color), left_(left), right_(right), parent_(parent) {}
    void operator=(RBNode right) {
        key_ = right.key_;
        color_ = right.color_;
        left_ = right.left_;
        right_ = right.right_;
    }

    Color color() const { return color_; }
    int getKey() const { return key_; }
    RBNode* right() const { return right_; }
    RBNode* left() const { return left_; }
    RBNode* parent() const { return parent_; }

    void setColor(Color color) { color_ = color; }
    void setKey(int value) { key_ = value; }
    void setRight(RBNode* right) { right_ = right; }
    void setLeft(RBNode* left) { left_ = left; }
    void setParent(RBNode* parent) { parent_ = parent; }

    std::string toString() {
        return " key is "+std::to_string(key_) +", color is "
               + std::to_string(color_);
    }

private:
    int key_;
    Color color_;
    RBNode* left_;
    RBNode* right_;
    RBNode* parent_;
};

struct RBTree {
    RBTree() : root_(NULL) {/* */}

    void insert(int value) {
        RBNode* cur = NULL;
        RBNode* x = root_;

        while(x!=NULL) {
            cur = x;
            if(value < x->getKey()) {
                x=x->left();
            } else {
                x = x->right();
            }
        }

        RBNode* target = new RBNode(value, Color::Red, NULL, NULL, NULL);

        target->setParent(cur);

        if(cur != NULL) {
            if(cur->getKey() < value) {
                cur->setRight(target);
            } else {
                cur->setLeft(target);
            }
        } else {
            root_ = target;
        }

        //todo insertFixup(node);
    }

    void search(int value);

    void deleteAll(RBNode *pNode) {
        if(pNode != NULL) {
            deleteAll(pNode->right());
            deleteAll(pNode->left());

            delete pNode;
        }
    }

    ~RBTree() {
        deleteAll(root_);
    }

private:
//    RBNode* initNode(int value) {
//        RBNode* node = new RBNode;
//        node->setKey(value);
//        node->setLeft(NULL);
//        node->setRight(NULL);
//        node->setColor(Color::Red);
//
//        return node;
//    }

    RBNode* recursive_insertion(RBNode* node, int value) {
        if(node==NULL) {
            //return initNode(value);
        }

        if(node->getKey() < value) {
            node->setRight(recursive_insertion(node->right(), value));
        }
        if(node->getKey() > value) {
            node->setLeft(recursive_insertion(node->left(), value));
        }

        if(is_red(node->right())) {
            left_rotation(node);
        }

        if(is_red(node->left()) && is_red(node->left()->left())) {
            right_rotation(node);
        }

        if(is_red(node->left()) && is_red(node->right())) {
            flip_colors(node);
        }

        return node;
    }

    void right_rotation(RBNode* y) {
       RBNode* x = y->left();

        y->setLeft(x->right());
        if(x->right() != NULL) {
            x->right()->setParent(y);
        }

        x->setParent(y->parent());
        if(y->parent() == NULL) {
            root_ = x;
        } else {
            if(y->parent()->left() == y)
                y->parent()->setLeft(x);
            else
                y->parent()->setRight(x);
        }

        x->setRight(y);
        y->setParent(x);
    }

    void left_rotation(RBNode* x) {
        RBNode* y = x->right();
        x->setRight(y->left());

        if(y->left() != NULL)
            y->left()->setParent(x);

        y->setParent(x->parent());

        if(x->parent() == NULL) {
            root_ = y;
        } else {
            if(x == x->parent()->left())
                x->parent()->setLeft(y);
            else
                x->parent()->setRight(y);
        }


        y->setRight(x);
        x->setParent(y);
    }
    bool is_red(RBNode* node);
    void flip_colors(RBNode* node);

    RBNode* recursive_search(RBNode* node, int value);

    void print_node(RBNode* node, int height);
    int test_rb_properties(RBNode* node);

private:
    RBNode* root_;
};


#endif //LINTCODE_RBTREE_H
