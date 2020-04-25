//
//  MyStack.cpp
//  Exercise_3.cpp
//
//  Created by Yaozeng Wang on 2/9/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

#include <MyStack.h>


    MyStack(void);
    MyStack(const MyStack &a);
    virtual ~MyStack(void);


    void initialize(void);
    void clear(void);
    MyStack& operator=(const MyStack &a);
    void replicate(const MyStack &a);

    int &top(void);


    bool empty(void);
    int size(void);
    int capacity(void);
    void push(int a);
    void pop(void);
    void resize(int n);


    int *mVec;
    int mSize;
    int mCapacity;

