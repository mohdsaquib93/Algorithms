#include <bits/stdc++.h>
#include "LL_CreateList.h"

using namespace std;

void method1()
{
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();

    for(int i = 10; i > 0; --i)
        i%2 ? l1->add(i) : l2->add(i);

    Node *ptr1 = l1->head;
    Node *ptr2 = l2->head;

    while(ptr2) {
        l2->head = ptr2->next;
        if(ptr2->data < ptr1->data) {
            l1->add(ptr2->data);
            continue;
        }
        ptr1 = l1->head;
        while(ptr1->next && ptr2->data >= ptr1->next->data)
                ptr1 = ptr1->next;
        ptr2->next = ptr1->next;
        ptr1->next = ptr2;
        ptr2 = l2->head;
    }

    ptr1 = l1->head;
    while(ptr1) {
        cout << ptr1->data;
        ptr1 = ptr1->next;
    }
}

void method2() {
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();

    for(int i = 20; i > 10; --i)
        i%2 ? l1->add(i) : l2->add(i);

    l2->add(8);
    l2->add(6);
    l2->add(4);
    l2->add(2);
    l2->add(0);
    Node *ptr1 = l1->head;
    Node *ptr2 = l2->head;
    Node *start = nullptr;
    Node *visited;
    if(!ptr1 || !ptr2) {
        start = (!ptr1) ? ptr2 : ptr1;
        goto end;
    }

    if(ptr1->data <= ptr2->data) {
        start = ptr1;
        ptr1 = ptr1->next;
    }
    else {
        start = ptr2;
        ptr2 = ptr2->next;
    }

    visited = start;
    while(ptr1 && ptr2) {
        if(ptr1->data <= ptr2->data) {
            visited->next = ptr1;
            ptr1 = ptr1->next;
        }
        else {
            visited->next = ptr2;
            ptr2 = ptr2->next;
        }
        visited = visited->next;
    }

    visited->next = ptr1 ? ptr1 : ptr2;
    end:
    while(start) {
        cout << start->data << " ";
        start = start->next;
    }
}

int main()
{
//    method1();
    method2();
    return 0;
}