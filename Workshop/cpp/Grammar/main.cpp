#include "MyVector.h"
#include "MyQueue.h"
#include "MyLink.h"
#include "MyBinaryTree.h"

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <ctime>
#include <random>
#include <algorithm>
#include "main.h"
using namespace std;

void displayVector(vector<int> &vec) {
    //for (vector<int>::iterator iter = vec.begin(); iter < vec.end(); iter++)
    //    cout << *iter << " ";
    
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}

void testSortMethod(void) {
    MyVector vec;
    //srand(time(NULL));
    for (int i = 0; i < 11; ++i) {
        vec.push_back(rand() % 1000);
    }

    vec.display();
    vec.sort();
    vec.display();
}

void testMyLink(void) {
    MyLink a;
    a.insert(0, 1);
    a.insert(0, 2);
    a.insert(0, 3);
    a.insert(0, 4);
    a.insert(0, 5);
    a.insert(0, 6);
    a.display();

    a.reverse();
    a.display();

    /*Node *tail = a.tail();
    tail->next = a.head->next;
    a.display();

    int len = a.size();
    cout << "len = " << len << endl;*/
    //for (int i = 0; i < len; i++) {
    //    cout << a[i] << ", ";
    //}
    //cout << endl;
}

void testMyBinaryTree(void) {
    MyBinaryTree bt;

    bt.root = new Node(1);
    bt.root->left = new Node(2);
    bt.root->right = new Node(3);
    bt.root->right->left = new Node(4);
    bt.root->right->right = new Node(5);

    //bt.root->value = 1;
    //bt.root->left->value = 2;
    //bt.root->right->value = 3;
    //bt.root->right->left->value = 4;
    //bt.root->right->right->value = 5;

    bt.display();
    cout << bt.depth() << endl;
}

int main(void) {
    testMyBinaryTree();
    
    system("PAUSE");
    return 0;
}