#include <bits/stdc++.h>
#include "LL_CreateList.h"

using namespace std;

int detectLoop(LinkedList *list) {
    Node *slowPtr, *fastPtr;
    int count = 0;
    slowPtr = fastPtr = list->head;
    int n = list->length;
    while(fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        count++;
        fastPtr = fastPtr->next->next;
        if(slowPtr == fastPtr)
            return list->length - count;
    }
    return -1;
}
int main() {
    int num;
    LinkedList *list = new(nothrow) LinkedList();
    cout << "Enter number of elements: ";
    cin >> num;
    srand(time(nullptr));
    for(int i = 0; i < num; ++i)
        list->add(rand() % 20);

    Node *node = list->head;
//    while(node->next)
//        node = node->next;
//    node->next = list->head->next->next->next->next->next->next;

    int index = detectLoop(list);
    if(index == -1)
        cout << "No loop present" << endl;
    else
        cout << "Loop at index: " << index << endl;
    return 0;
}
