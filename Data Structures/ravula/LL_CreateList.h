struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    int length;
    Node *head;
    LinkedList();
    ~LinkedList();
    void add(int item);
    void print();
};

LinkedList::LinkedList() {
    this->length = 0;
    this->head = nullptr;
}

void LinkedList::add(int item) {
    Node *node = new Node();
    node->data = item;
    node->next = this->head;
    this->head = node;
    this->length++;
}

LinkedList::~LinkedList() {
    std::cout << "Deleting list...";
    Node *next;
    Node *curr = this->head;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::print() {
    Node *start = this->head;
    while(start) {
        std::cout << start->data << " ";
        start = start->next;
    }
    std::cout << std::endl;
}