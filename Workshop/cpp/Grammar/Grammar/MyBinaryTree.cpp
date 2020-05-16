#include "MyBinaryTree.h"

MyBinaryTree::MyBinaryTree()
{
    root = NULL;
}

MyBinaryTree::~MyBinaryTree()
{
    clear(root);
    root = NULL;
}

void MyBinaryTree::clear(Node *pn)
{
    if (pn == NULL)
        return;
    
    if (pn->left != NULL)
        clear(pn->left);
    if (pn->right != NULL)
        clear(pn->right);

    delete pn;
}

int MyBinaryTree::depth(void)
{
    return depth(root);
}

int MyBinaryTree::depth(Node * pn)
{
    if (pn == NULL)
        return 0;

    int left_depth = 0;
    int right_depth = 0;
    if (pn->left != NULL)
        left_depth = depth(pn->left);
    if (pn->right != NULL)
        right_depth = depth(pn->right);

    return (left_depth >= right_depth ? left_depth : right_depth) + 1;
}

void MyBinaryTree::display(void)
{
    if (root == NULL)
        cout << "node: NULL" << endl;
    else
        display(root);
}

void MyBinaryTree::display(Node * pn)
{
    if (pn == NULL)
        return;

    cout << "node: " << pn->value;
    if (pn->left != NULL) {
        cout << ", left: " << pn->left->value;
    }
    if (pn->right != NULL) {
        cout << ", right: " << pn->right->value;
    }
    cout << endl;

    display(pn->left);
    display(pn->right);
}

int MyBinaryTree::getMax(void){
    return getMax(root);
}

int MyBinaryTree::getMax(Node *pn) {
    if (pn == NULL)
        return INT_MIN;
    
    int ret = pn->value;
    if (pn->left != NULL) {
        int temp = getMax(pn->left);
        ret = ret >= temp ? ret : temp;
        //ret = max(ret, getMax(pn->left));
    }
    if (pn->right != NULL) {
        int temp = getMax(pn->right);
        ret = ret >= temp ? ret : temp;
        //ret = max(ret, getMax(pn->right));
    }

    return ret;
}

int MyBinaryTree::getMin(void) {
    return getMin(root);
}

int MyBinaryTree::getMin(Node *pn) {
    if (pn == NULL)
        return INT_MAX;

    int ret = pn->value;
    if (pn->left != NULL) {
        int temp = getMin(pn->left);
        ret = ret < temp ? ret : temp;
        //ret = max(ret, getMax(pn->left));
    }
    if (pn->right != NULL) {
        int temp = getMin(pn->right);
        ret = ret < temp ? ret : temp;
        //ret = max(ret, getMax(pn->right));
    }

    return ret;
}



