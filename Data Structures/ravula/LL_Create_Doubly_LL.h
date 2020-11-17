#include <iostream>

template <typename T>
struct DNode {
    T data;
    DNode *left;
    DNode *right;
};

template <typename T>
struct DoublyList {
    int length;
    DNode<T> *head;
    DNode<T> *curr;
    DoublyList();
    ~DoublyList();
    void add_left(T item);
    void add_right(T item);
    void print();
};

template <typename T>
DoublyList<T>::DoublyList() {
    this->head = nullptr;
    this->length = 0;
}

template <typename T>
void DoublyList<T>::add_left(T item) {
    DNode<T> *node = new DNode<T>();
    node->data = item;
    node->right = this->head;
    node->left = nullptr;
    if(this->head)
        this->head->left = node;
    this->head = node;
    this->length++;
}

template <typename T>
void DoublyList<T>::add_right(T item)
{
    DNode<T> *node = new DNode<T>();
    node->data = item;
    node->right = nullptr;
    node->left = this->head;
    this->head->right = node;
    this->head = node;
    this->length++;
}

template <typename T>
void DoublyList<T>::print() {
    DNode<T> *start = this->head;
    while(start) {
        std::cout << start;
        start = start->right;
    }
}

template <typename T>
DoublyList<T>::~DoublyList() {
    DNode<T> *curr = this->head;
    while(curr) {
        curr = curr->right;
        free(this->head);
        this->head = curr;
    }
}