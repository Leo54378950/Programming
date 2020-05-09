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

int& MyVector::at(int index) {
    if (index < 0 || index >= mSize) {
        cout << "Invalid index" << endl;
        system("PAUSE");
        exit(1);
    }
    return mVec[index];
}

int& MyVector::operator[](int index) {
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
    //insertionSort();
    //mergeSort();
    quickSort();
}

void MyVector::bubbleSort(void)
{
    for (int i = 0; i < size() - 1; ++i) {// 限制了循环轮数，同时指定了最小循环到第i位
        for (int j = size() - 1; j > i; --j) {
            if (mVec[j - 1] > mVec[j]) {
                int temp = mVec[j - 1];
                mVec[j - 1] = mVec[j];
                mVec[j] = temp;
            }
        }
    }
}

void MyVector::selectionSort(void)
{
    for (int i = 0; i < size() - 1; ++i) {// 限制了循环轮数，同时指定了最小循环到第i位
        // choose the minium value among [i, end)
        int minValue = mVec[i];
        int minJ = i;
        for (int j = i; j < size(); j++) {
            if (mVec[j] < minValue) {
                minValue = mVec[j];
                minJ = j;
            }
        }

        // swap mVec[i] and minValue;
        int temp = mVec[i];
        mVec[i] = mVec[minJ];
        mVec[minJ] = temp;
    }
}

/* Yaozeng -- begin */
void MyVector::swap(int i, int j) {
    int temp = mVec[i];
    mVec[i] = mVec[j];
    mVec[j] = temp;
}

//void MyVector::bubbleSort(void)
//{
//    for (int i = 0; i < size() - 1; ++i) {
//        for (int j = size() - 1; j > i; --j) {
//            if (mVec[j - 1] > mVec[j]) {
//                swap(j - 1, j);
//            }
//        }
//    }
//}

//void MyVector::selectionSort(void) {
//    for (int i = 0; i < size() - 1; ++i) {
//        // choose the minium value among [i, end)
//        int minValue = mVec[i];
//        int minJ = i;
//        for (int j = i; j < size(); j++) {
//            if (mVec[j] < minValue) {
//                minValue = mVec[j];
//                minJ = j;
//            }
//        }
//        swap(i, minJ);
//    }
//}

void MyVector::insertionSort(void) {
    for (int i = 1; i < size(); ++i) {
        int j = mVec[i];
        //// i = 4
        //// 1 2 4 5 (3)
        //// 1 2 3 4 5
        //// target_position = 2
        //// 1 2 4 5 => 1 2 _ 4 5 => 1 2 3 4 5
        //int target_position = 0;
        //for (int k = 0; k < i; k++) {
        //    if (mVec[k] < j) {
        //        target_position++;
        //    }
        //    else {
        //        break;
        //    }
        //}

        //int temp = mVec[target_position];
        //for (int k = target_position; k < i; k++) {
        //    int temp2 = mVec[k + 1];
        //    mVec[k + 1] = temp;
        //    temp = temp2;
        //}

        //mVec[target_position] = j;



        int k;
        for (k = i - 1; k >= 0; --k) {
            if (mVec[k] <= j)
                break;
            mVec[k + 1] = mVec[k];
        }
        mVec[k + 1] = j;
    }
}

void MyVector::shellSort(void) {
    for (int gap = mSize / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < mSize; i += 1) {
            int temp = mVec[i];
            int j;
            for (j = i; j >= gap && mVec[j - gap] > temp; j -= gap) {
                mVec[j] = mVec[j - gap];
            }
            mVec[j] = temp;
        }
    }
}

void MyVector::mergeSort(void)
{
    mergeSortPart(0, size());
}

void MyVector::quickSort(void)
{
    quickSortPart(0, size());
}

void MyVector::quickSortPart(int begin, int end) 
{
    if (end - begin <= 1)
        return;

    int target = mVec[begin];
    int le = begin;
    int ri = end - 1;
    while (true) {
        while (le < ri && mVec[ri] > target)
            ri--;

        if (le >= ri)
            break;

        mVec[le++] = mVec[ri];

        while (le < ri && mVec[le] < target)
            le++;

        if (le >= ri)
            break;

        mVec[ri--] = mVec[le];
    }

    mVec[le] = target;
    quickSortPart(begin, le);
    quickSortPart(le + 1, end);
}

void MyVector::mergeSortPart(int begin, int end)
{
    if (end - begin <= 1)
        return;

    int middle = (begin + end) / 2;
    mergeSortPart(begin, middle);
    mergeSortPart(middle, end);

    mergeTwoVector(begin, middle, end);
}

void MyVector::mergeTwoVector(int begin, int middle, int end)
{
    MyVector temp;
    int le = begin;
    int ri = middle;
    
    while (le < middle && ri < end) {
        if (mVec[le] < mVec[ri]) {
            temp.push_back(mVec[le]);
            le++;
        }
        else {
            temp.push_back(mVec[ri]);
            ri++;
        }
    }

    while (le < middle) {
        temp.push_back(mVec[le]);
        le++;
    }

    while (ri < end) {
        temp.push_back(mVec[ri]);
        ri++;
    }

    for (int i = begin; i < end; i++) {
        mVec[i] = temp[i - begin];
    }
}

/* Yaozeng -- end */




























void MyVector::display(void)
{
    for (int i = 0; i < size(); ++i)
        cout << mVec[i] << " ";
    cout << endl;
}

int MyVector::size(void) {
    return mSize;
}

int MyVector::capacity(void) {
    return mCapacity;
}

bool MyVector::empty(void) {
    if (mSize == 0) {
        return true;
    }
    return false;
}

int &MyVector::front(void) {
    if (0 == mSize)
        exit(1);
    return mVec[0];
}
int &MyVector::back(void) {
    if (0 == mSize)
        exit(1);
    return mVec[mSize - 1];
}

void MyVector::insert(int i, int value) {
    if (mSize < i) {
        exit(1);
    }

    if (0 == mCapacity) {
        resize(1);
    }

    if (mCapacity <= mSize) {
        resize(2 * mCapacity);
    }

    for (int j = mSize; j > i; j--) {
        mVec[j] = mVec[j - 1];
    }
    mVec[i] = value;
    mSize++;
}

void MyVector::erase(int i) {
    if (mSize <= i) {
        exit(1);
    }

    for (int j = i; j < mSize - 1; j++) {
        mVec[j] = mVec[j + 1];
    }
    mSize--;
    if (mCapacity > 4 * mSize) {
        resize(mCapacity / 2);
    }
}
