#pragma once
#include "Head.h";

class MyHeap
{
public:
    MyHeap();
    virtual ~MyHeap();

public:
    bool empty(void);
    int size(void);

    void push(int a); // go up
    int pop(void); // go down

private:
    void goUp(void);
    void goUp(int index);
    void goDown(void);
    void goDown(int index);

private:
    vector<int> mHeap;
};

