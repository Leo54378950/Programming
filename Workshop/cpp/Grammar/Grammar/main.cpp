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
using namespace std;

void testHeap(void);

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
    cout << bt.getMax() << endl;
}



void preorderTraversal(Node *root, vector<int> &path) {
    if (root == NULL)
        return;

    path.push_back(root->value);
    if (root->left != NULL)
        preorderTraversal(root->left, path);
    if (root->right != NULL)
        preorderTraversal(root->right, path);
}

void inorderTraversal(Node *root, vector<int> &path) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        inorderTraversal(root->left, path);
    path.push_back(root->value);
    if (root->right != NULL)
        inorderTraversal(root->right, path);
}

void postorderTraversal(Node *root, vector<int> &path) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        postorderTraversal(root->left, path);
    if (root->right != NULL)
        postorderTraversal(root->right, path);
    path.push_back(root->value);
}

//int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//int *pa = &a[3];
//
//int *pb = (ClassA *)(((ClassB *)pa) + 1);
//pb[0] = 6

//Node *buildTreeByPreorderAndInroder(vector<int> &preorder, int pre_begin, 
//                                    vector<int> &inorder, int in_begin, int len) 
//{
//    if (len <= 0)
//        return NULL;
//
//    Node *root = new Node;
//    root->value = preorder[pre_begin];
//    root->left = root->right = NULL;
//
//    if (len == 1) 
//        return root;
//    
//    int i = 0;
//    for (; i < len; ++i) {
//        if (inorder[in_begin + i] == root->value)
//            break;
//    }
//
//    // inorder[in_begin + i] == preorder[pre_begin];
//    root->left = buildTreeByPreorderAndInroder(preorder, pre_begin + 1, inorder, in_begin, i);
//    root->right = buildTreeByPreorderAndInroder(preorder, pre_begin + 1 + i, inorder, in_begin + 1 + i, len - 1 - i);
//    return root;
//}

Node *buildTreeByPreorderAndInroder(vector<int>::iterator preorder, 
                                    vector<int>::iterator inorder, int len)
{
    if (len <= 0)
        return NULL;

    Node *root = new Node(preorder[0]);

    if (len == 1)
        return root;

    int i = 0;
    for (; i < len; ++i) {
        if (inorder[i] == root->value)
            break;
    }

    // inorder[i] == preorder[0];
    root->left = buildTreeByPreorderAndInroder(preorder + 1, inorder, i);
    root->right = buildTreeByPreorderAndInroder(preorder + 1 + i, inorder + 1 + i, len - 1 - i);
    return root;
}

Node *buildTreeByPreorderAndInroder(vector<int> &preorder, vector<int> &inorder)
{
    int len = preorder.size();
    if (len <= 0)
        return NULL;
    //return buildTreeByPreorderAndInroder(preorder, 0, inorder, 0, len);
    return buildTreeByPreorderAndInroder(preorder.begin(), inorder.begin(), len);
}

Node *buildTreeByInorderAndPostorder(vector<int> &inorder, vector<int> &postorder)
{
    return NULL;
}

int main(void) {
    testHeap();
    
    system("PAUSE");
    return 0;
}
