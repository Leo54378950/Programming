#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
};

class MyLink
{
public:
    MyLink(void);
    virtual ~MyLink(void);

public:
    void clear(void);

    int &at(int index);
    int& operator[](int index);
    void display(void);

public:
    ListNode *tail(void);
    bool hasCircle(void);
    ListNode *getCircleEntry(void);
    bool empty(void);
    int size(void);
    void insert(int i, int value);
    void erase(int i);

    void reverse(void);

public:
    ListNode *head;
};

