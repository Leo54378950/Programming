#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyVector
{
public:
    MyVector(void);
    MyVector(int n);
    MyVector(int n, int initial_value);
    MyVector(const MyVector &a);
    virtual ~MyVector(void);

public:
    MyVector& operator=(const MyVector &a);
    int& operator[](int index);
    void replicate(const MyVector &a);
    void initialize(void);
    void initialize(int n);
    void finalize(void);

public:
    void push_back(int a);
    void pop_back(void);

public:
    void resize(int n);

public:
    int *mVec;
    int mSize;
    int mCapacity;
};

