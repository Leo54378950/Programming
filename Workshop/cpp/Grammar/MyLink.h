#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node *next;
};

class MyLink
{
public:
    MyLink(void);
    virtual ~MyLink(void);

public:
    void clear(void);

    int &at(int index);
    int& operator[](int index);
    void display(void);

public:
    Node *tail(void);
    bool hasCircle(void);
    Node *getCircleEntry(void);
    bool empty(void);
    int size(void);
    void insert(int i, int value);
    void erase(int i);

public:
    Node *head;
};

