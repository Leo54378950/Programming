#pragma once

#include "Head.h"

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(void) : value(0), left(NULL), right(NULL) {}
    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

//Node a;
//Node b(3);

class MyBinaryTree
{
public:
    MyBinaryTree();
    virtual ~MyBinaryTree();

private:
    void clear(Node *pn);

public:
    int depth(void);
    int depth(Node *pn);
    int getMax(void);
    int getMax(Node *pn);
    int getMin(void);

public:
    void display(void);
    void display(Node *pn);

public:
    Node *root;
};

