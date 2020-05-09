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

int MyBinaryTree::getMax(Node *pn){
    if (pn == NULL){
        return 0;
    }
    
    int le_max = 0;
    int ri_max = 0;
    if (pn -> left != NULL){

    }
    if (pn -> right != NULL){
        ri_max = getMax(pn->right);
    }
    return (le_max > ri_max ? le_max : ri_max);
}


int MyBinaryTree::getMin(void){
    return 0;
}
