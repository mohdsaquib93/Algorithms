#include <bits/stdc++.h>
#include "LL_CreateList.h"

using namespace std;

int main()
{
    int num, count = 0;
    LinkedList *list1 = new LinkedList();
    LinkedList *list2 = new LinkedList();
    Node *node1, *node2;
    srand(time(nullptr));
    cout << "Enter no of elements in list 1: ";
    cin >> num;
    for(int i = 0; i < num; ++i)
        list1->add(rand() % 20);
    cout << "Enter no of elements in list 2: ";
    cin >> num;
    for(int i = 0; i < num; ++i)
        list2->add(rand() % 20);

    node1 = list1->head;
    node2 = list2->head;
    node2->next->next->next->next = node1->next->next->next->next->next;

    node2 = list2->head;
    while(node2) {
        count++;
        node2 = node2->next;
    }
    list2->length = count;
    pair<int, bool>diff = (list1->length >= list2->length) ? make_pair(list1->length - list2->length, 0)
                            : make_pair(list2->length - list1->length, 1);
    if(diff.second) {
        node1 = list1->head;
        node2 = list2->head;
    }
    else {
        node1 = list2->head;
        node2 = list1->head;
    }

    for(int i = 0; i < diff.first; ++i)
        node2 = node2->next;

    count = 0;
    while(node2 != node1) {
        count++;
        node2 = node2->next;
        node1 = node1->next;
    }

    cout << "Lists intersect at index: " << count << endl;
    return 0;
}
