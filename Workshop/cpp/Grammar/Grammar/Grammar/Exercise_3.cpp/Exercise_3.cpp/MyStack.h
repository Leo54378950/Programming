//
//  MyStack.h
//  Exercise_3.cpp
//
//  Created by Yaozeng Wang on 2/9/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h
#endif /* MyStack_h */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyStack
{
public:
    MyStack(void);
    MyStack(const MyStack &a);
    virtual ~MyStack(void);

public:
    void initialize(void);
    void clear(void);
    MyStack& operator=(const MyStack &a);
    void replicate(const MyStack &a);

    int &top(void);

public:
    bool empty(void);
    int size(void);
    int capacity(void);
    void push(int a);
    void pop(void);
    void resize(int n);

protected:
    int *mVec;
    int mSize;
    int mCapacity;
};

