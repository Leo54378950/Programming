#include "MyHeap.h"



MyHeap::MyHeap()
{
}


MyHeap::~MyHeap()
{
    mHeap.clear();
}

bool MyHeap::empty(void) {
    return mHeap.empty();
}

int MyHeap::size(void) {
    return mHeap.size();
}

void MyHeap::push(int a) {
    mHeap.push_back(a);
    goUp();
}

int MyHeap::pop(void) {
    if (empty())
        exit(1); // exit with error code.

    int ret = mHeap[0];

    swap(mHeap[0], mHeap.back());
    mHeap.pop_back();

    goDown();
    return ret;
}

void MyHeap::goUp(void) {
    goUp(size() - 1);
}

void MyHeap::goUp(int index) {
    if (index <= 0)
        return;

    int parent_index = (index - 1) / 2;
    if (mHeap[parent_index] >= mHeap[index])
        return;
    
    swap(mHeap[parent_index], mHeap[index]);
    goUp(parent_index);
}

void MyHeap::goDown(void) {
    goDown(0);
}

void MyHeap::goDown(int index) {
    if (2 * index + 1 >= size())
        return;

    int next = 2 * index + 1;
    if (2 * index + 2 == size()) {
        if (mHeap[index] < mHeap[next])
            swap(mHeap[index], mHeap[next]);

        return;
    }

    if (mHeap[next] < mHeap[next + 1])
        next++;

    if (mHeap[index] >= mHeap[next])
        return;

    swap(mHeap[index], mHeap[next]);
    goDown(next);
}

