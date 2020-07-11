#include "Head.h";
#include "MyHeap.h";
#include "MyVector.h";

void testHeap(void) {
    MyHeap heap;

    vector<int> a = { 3, 5, 1, 7,8, 4, 6, 2, 10 };
    for (int i = 0; i < a.size(); ++i) {
        heap.push(a[i]);
    }

    MyVector b;
    while (!heap.empty()) {
        b.push_back(heap.pop());
    }

    b.display();
}