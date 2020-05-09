#include "MyLink.h"

MyLink::MyLink() {
    head = NULL;
}


MyLink::~MyLink() {
    clear();
}

void MyLink::clear(void) {
    if (hasCircle()) {
        Node *t = tail();
        while (head != t) {
            Node *next = head->next;
            delete head;
            head = next;
        }
        delete head;
        head = NULL;
        return;
    }

    while (head != NULL) {
        Node *next = head->next;
        delete head;

        head = next;
    }
}

int &MyLink::at(int index) {
    Node *pn = head;
    for (int i = 0; i < index; ++i) {
        if (pn == NULL)
            exit(1);
        pn = pn->next;
    }
    if (pn == NULL)
        exit(1);
    return pn->value;
}

int &MyLink::operator[](int index) {
    Node *pn = head;
    for (int i = 0; i < index; ++i) {
        if (pn == NULL)
            exit(1);
        pn = pn->next;
    }
    if (pn == NULL)
        exit(1);
    return pn->value;
}

void MyLink::display(void) {
    if (hasCircle()) {
        Node *pn = head;
        Node *t = tail();
        while (pn != t) {
            cout << pn->value << " ";
            pn = pn->next;
        }
        cout << pn->value << " [" << pn->next->value << "] ..." << endl;
        return;
    }

    Node *pn = head;
    while (pn != NULL) {
        cout << pn->value << " ";
        pn = pn->next;
    }
    cout << endl;
}

Node * MyLink::tail(void)
{
    if (hasCircle()) {
        Node *entry = getCircleEntry();

        Node *p1 = entry;
        Node *p2 = entry;
        int len = 0;
        while (true) {
            p1 = p1->next;
            p2 = p2->next->next;
            len++;
            if (p1 == p2)
                break;
        }
        Node *t = entry;
        for (int i = 0; i < len - 1; i++) {
            t = t->next;
        }
        return t;
    }

    if (head == NULL)
        return NULL;
    Node *t = head;

    while (t->next != NULL)
        t = t->next;
    return t;
}

bool MyLink::hasCircle(void)
{
    if (empty())
        return false;

    Node *p1 = head;
    Node *p2 = head;
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

Node * MyLink::getCircleEntry(void)
{
    if (empty())
        return NULL;

    Node *p1 = head;
    Node *p2 = head;
    while (true) {
        p2 = p2->next;
        if (p2 == NULL)
            return NULL;
        p1 = p1->next;
        p2 = p2->next;
        if (p2 == NULL)
            return NULL;

        if (p1 == p2)
            break;
    }

    Node *p3 = head;
    while (p1 != p3) {
        p1 = p1->next;
        p3 = p3->next;
    }
    return p1;
}

bool MyLink::empty(void) {
    return head == NULL;
}

int MyLink::size(void) {
    if (hasCircle())
        return -1;

    Node *pn = head;
    int len = 0;
    while (pn != NULL) {
        len++;
        pn = pn->next;
    }
    return len;
}

void MyLink::insert(int i, int value) {
    if (hasCircle())
        exit(1);

    if (i == 0) {
        Node *pn = new Node;
        pn->value = value;
        pn->next = head;
        head = pn;
        return;
    }

    Node *pn = head;
    for (int j = 0; j < i - 1; j++) {
        if (pn == NULL)
            exit(1);
        pn = pn->next;
    }
    if (pn == NULL)
        exit(1);

    Node *nn = new Node;
    nn->value = value;
    nn->next = pn->next;
    pn->next = nn;
}

void MyLink::erase(int i) {
    if (hasCircle())
        exit(1);

    if (head == NULL)
        exit(1);
    
    if (i == 0) {
        Node *next = head->next;
        delete head;
        head = next;
        return;
    }

    Node *pn = head;
    for (int j = 0; j < i - 1; ++j) {
        pn = pn->next;
        if (pn == NULL)
            exit(1);
    }
    if (pn->next == NULL)
        exit(1);

    Node *target = pn->next;
    //pn->next = target->next;
    pn->next = pn->next->next;
    delete target;
}

