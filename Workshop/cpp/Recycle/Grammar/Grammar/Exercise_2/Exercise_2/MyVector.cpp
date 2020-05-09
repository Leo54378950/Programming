//
//  Myvector.cpp
//  Exercise_2
//
//  Created by Yaozeng Wang on 2/2/20.
//  Copyright © 2020 Yaozeng Wang. All rights reserved.
//
#include "Myvector.h"

MyVector::MyVector(void) {
    initialize();
}

MyVector::MyVector(int n) {
    if (n <= 0)
        exit(1);

    initialize(n);
}

MyVector::MyVector(int n, int initial_value) {
    if (n <= 0)
        exit(1);

    initialize(n);
    for (int i = 0; i < n; ++i) {
        mVec[i] = initial_value;
    }
}

MyVector::~MyVector(void) {
    clear();
}

MyVector::MyVector(const MyVector &a) {
    replicate(a);
}

MyVector& MyVector::operator=(const MyVector &a) {
    if (this != &a) {
        replicate(a);
    }
    return *this;
}

int& MyVector::operator[](int index) {
    if (index < 0 || index >= mSize) {
        cout << "Invalid index" << endl;
        system("PAUSE");
        exit(1);
    }
    return mVec[index];
}

void MyVector::replicate(const MyVector &a) {
    clear();

    mSize = a.mSize;
    mCapacity = a.mCapacity;
    mVec = new int[mCapacity];
    for (int i = 0; i < mSize; ++i) {
        mVec[i] = a.mVec[i];
    }
}

void MyVector::initialize(void) {
    mVec = NULL;
    mSize = 0;
    mCapacity = 0;
}

void MyVector::initialize(int n) {
    mVec = new int[n];
    mSize = n;
    mCapacity = n;
}

void MyVector::clear(void) {
    if (mVec != NULL)
        delete[] mVec;

    initialize();
}

void MyVector::push_back(int a) {
    if (0 == mCapacity) {
        resize(1);
    }
    if (mSize >= mCapacity)
        resize(2 * mCapacity);
        
    mVec[mSize] = a;
    mSize++;
}

void MyVector::pop_back(void) {
    if (0 == mSize) {
        cout << "Cannot pop_back empty vector." << endl;
        system("PAUSE");
        exit(1);
    }

    mSize--;

    if (mSize < mCapacity / 4) {
        resize(mCapacity / 2);
    }
}

// new feature
void MyVector::resize(int n) {
    if (n < 0) {
        cout << "the new size should be non-negative." << endl;
        system("PAUSE");
        exit(1);
    }

    if (n == mCapacity)
        return;

    int *newVec = new int[n];
    mSize = mSize < n ? mSize : n;
    for (int i = 0; i < mSize; ++i) {
        newVec[i] = mVec[i];
    }
    delete[] mVec;
    mVec = newVec;
    mCapacity = n;
}

void MyVector::sort(void)
{
    //bubbleSort();
    selectionSort();
    //insertionSort();
    
}

void MyVector::swap(int i, int j){
    int temp = mVec[i];
    mVec[i] = mVec[j];
    mVec[j] = temp;
}

void MyVector::bubbleSort(void){
    for (int i = 0; i < mSize - 1; i++){
        for (int j = mSize - 1; j > i; j--){
            if (mVec[j] > mVec[j - 1]){
                swap(j, j - 1);
            }
        }
    }
}



void MyVector::selectionSort(void){
    for (int i = 0; i < mSize - 1; i++){
        int k = i;
        for (int j = i + 1; j < mSize; j++){
            if ( mVec[j] >= mVec[k] ){
                continue;
            }
            k = j;
        }
        swap (k, i);
    }
}

void MyVector::insertionSort(void){
    for (int i = 1; i < mSize ; i ++){
        int target = mVec[i];
        int k;
        for (k = i - 1; k >= 0; k --){
            if (mVec[k] > target){
               // mVec [k+1] = mVec[k];
                swap (k, k + 1);
            }
            else {
                break;
            }
        }
       // mVec[k + 1] = target;
    }
}


//void MyVector::shellSort(void){
//    for (int gap = mSize/2; gap > 0; gap /= 2){
//       for (int i = gap; i < mSize; i += 1){
//           int temp = mVec[i];
//           int j;
//           for (j = i; j >= gap && mVec[j - gap] > temp; j -= gap){
//               mVec[j] = mVec[j - gap];
//           }
//           mVec[j] = temp;
//       }
//    }
//}

void MyVector::mergeSort(void){
    mergeSortPart(0, size());
}

void MyVector::mergeSortPart(int begin, int end){
    int length = end - begin;
    int middle = (begin + end) / 2;
    if (length <= 1){
        return;
    }
    mergeSortPart(begin, middle);
    mergeSortPart(middle, end);
    mergeTwoVectors(begin, middle, end);
}

void MyVector::mergeTwoVectors(int begin, int middle, int end){
    vector<int> a;
    int i, j;
    for (i = begin, j = middle; i < middle && j < end; ){
        if (mVec[i] < mVec[j]){
            a.push_back(mVec[i++]);
        }
        else{
            a.push_back(mVec[j++]);
        }
    }

    for (; j < end; j++)
        a.push_back(mVec[j]);

    for (; i < middle; i++)
        a.push_back(mVec[i]);


    for (int k = begin, l = 0; k < end ; k++, l++)
        mVec[k] = a[l];
}

void MyVector::quickSort(void){
    quickSortPart(0, size());
}
void MyVector::quickSortPart(int begin, int end){
    int length = end - begin;
    while (length <= 1){
        return;
    }
    int le = begin;
    int ri = end - 1;
    int target = mVec[le];
    
    while (true){
        while (le < ri && target < mVec[ri]){
            ri --;
        }
        if (le >= ri){
            break;
        }
        mVec[le++] = mVec[ri];
        
        while (le < ri && target > mVec[le]){
            le ++;
        }
        if (le >= ri){
            break;
        }
        mVec[ri--] = mVec[le];
    }
    
    mVec[le] = target;
    quickSortPart(begin, le);
    quickSortPart(le + 1, end);
}


void MyVector::display(void){
    for (int i = 0; i < size(); ++i)
        cout << mVec[i] << " ";
    cout << endl;
}


int MyVector::size(void){
    return mSize;
}

int MyVector::capacity(void){
    return mCapacity;
}
     
bool MyVector:: empty(void){
    if (mSize == 0){
        return true;
    }
    return false;
}

int &MyVector::front(void){
    return mVec[0];
}
int &MyVector::back(void){
    return mVec[mSize - 1];
}

void MyVector:: insert(int i, int value){
    if (mSize < i){
        exit(1);
    }
    
    if (0 == mCapacity){
        resize(1);
    }
    
    if (mCapacity <= mSize){
        resize(2 * mCapacity);
    }
    
    for (int j = mSize; j > i; j --){
        mVec[j] = mVec[j-1];
    }
    mVec[i] = value;
    mSize ++;
}

void MyVector:: erase(int i){
    if (mSize <= i){
        exit(1);
    }

    for (int j = i; j < mSize - 1; j++){
        mVec[j] = mVec[j+1];
    }
    mSize --;
    if (mCapacity > 4*mSize){
        resize(mCapacity / 2);
    }
}



