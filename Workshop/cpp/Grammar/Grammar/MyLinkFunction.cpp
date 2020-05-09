#include "MyLinkFunction.h"

bool HasCircle(MyLink a)
{
    if (a.empty())
        return false;

    Node *p1 = a.head;
    Node *p2 = a.head;
    while (true) {
        p2 = p2->next;
        if (p2 == NULL)
            return false;
        
        p1 = p1->next;

        p2 = p2->next;
        if (p2 == NULL)
            return false;

        if (p1 == p2)
            return true;
    }
}

bool HasCrossing(MyLink a, MyLink b)
{
    Node *pa = a.tail();
    Node *pb = b.tail();

    return pa == pb;
}
