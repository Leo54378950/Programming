//
//  MyStack.cpp
//  Exercise_3.cpp
//
//  Created by Yaozeng Wang on 2/9/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//

#include "MyStack.h"

MyStack::MyStack(void){
     initialize();
}

MyStack::MyStack(const MyStack &a){
    initialize();
    replicate(a);
}

MyStack::~MyStack(void){
    clear();
}

void MyStack::initialize(void){
    mVec = NULL;
    mSize = 0;
    mCapacity = 0;
}

void MyStack::clear(void){
       if (mVec != NULL)
            delete[] mVec;
    
        initialize();
}

MyStack& MyStack::operator=(const MyStack &a){
    if (this != &a) {
          replicate(a);
      }
      return *this;
}
void MyStack::replicate(const MyStack &a){
    clear();
    
        mSize = a.mSize;
        mCapacity = a.mCapacity;
        mVec = new int[mCapacity];
        for (int i = 0; i < mSize; ++i) {
            mVec[i] = a.mVec[i];
        }
}

int& MyStack::top(void){
    if (0 == mSize){
        exit(1);
    }
    return mVec[mSize - 1];
}

bool MyStack::empty(void){
    if (mSize == 0) {
        return true;
    }
    return false;
}
int MyStack::size(void){
    return mSize;
}
int MyStack::capacity(void){
    return mCapacity;
}
void MyStack::push(int a){
    if (0 == mCapacity) {
        resize(1);
    }
    if (mSize >= mCapacity) {
        resize(2 * mCapacity);
    }
    
    mVec[mSize] = a;
    mSize++;
}

void MyStack::pop(void){

    if (mSize <= 0) {

        exit(1);

    }

    mSize--;

    if (mCapacity > 4 * mSize) {

        resize(mCapacity / 2);

    }

}

void MyStack::resize(int n){
    if (n < 0) {
        cout << "the new size should be non-negative." << endl;
        system("PAUSE");
        exit(1);
    }
    if (n == mCapacity){
        return;
    }
    int *newVec = new int[n];
    for (int i = 0; i < mSize; ++i) {
        newVec[i] = mVec[i];
    }
    delete[] mVec;
    mVec = newVec;
    mCapacity = n;
}
