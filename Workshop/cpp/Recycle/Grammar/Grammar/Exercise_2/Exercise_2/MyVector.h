//
//  Myvector.h
//  Exercise_2
//
//  Created by Yaozeng Wang on 2/2/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

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
    void initialize(void);
    void initialize(int n);
    void clear(void);

    MyVector& operator=(const MyVector &a);
    void replicate(const MyVector &a);

    int &at(int index);
    int& operator[](int index);
    int &front(void);
    int &back(void);

public:
    bool empty(void);
    int size(void);
    int capacity(void);
    void push_back(int a);
    void pop_back(void);
    void insert(int i, int value);
    void erase(int i);
    void resize(int n);

public:
    void swap(int i, int j);
    void sort(void);
    void bubbleSort(void);
    void selectionSort(void);
    void insertionSort(void);
    void shellSort(void);
    void mergeSort(void);
    void mergeSortPart(int begin, int end);
    void quickSort(void);
    void quickSortPart(int begin, int end); 
    void mergeTwoVectors(int begin, int middle, int end);
    void display(void);

protected:
    int *mVec;
    int mSize;
    int mCapacity;
};

