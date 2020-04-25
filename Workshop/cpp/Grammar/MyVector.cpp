#include "MyVector.h"

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
    finalize();
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
    finalize();

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

void MyVector::finalize(void) {
    if (mVec != NULL)
        delete[] mVec;

    initialize();
}

void MyVector::push_back(int a) {
    if (0 == mSize) {
        mVec = new int[1];
        mCapacity = 1;
        mSize = 1;
        mVec[0] = a;
    }
    else {
        if (mSize >= mCapacity)
            resize(2 * mCapacity);

        mVec[mSize] = a;
        mSize++;
    }
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