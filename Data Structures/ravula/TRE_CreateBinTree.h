struct Node {
    char data;
    Node *left;
    Node *right;
    Node(char d) : data(d) {}
};

struct Tree {
    int num_nodes;
    Node *root;
    Tree();
    ~Tree();
    void populate();
    void preorder(Node *t);
    void inorder(Node *t);
    void postorder(Node *t);
};

Tree::Tree() : num_nodes(7), root(nullptr) {}

void Tree::populate() {
    // Populating elements a,b,c,d,e,f,g
    this->root = new Node('a');
    Node *nodeB = new Node('b');
    Node *nodeC = new Node('c');
    Node *nodeD = new Node('d');
    Node *nodeE = new Node('e');
    Node *nodeF = new Node('f');
    Node *nodeG = new Node('g');

    this->root->left = nodeB;
    this->root->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;
    nodeC->right = nodeG;
    nodeD->left = nullptr;
    nodeD->right = nullptr;
    nodeE->left = nullptr;
    nodeE->right = nullptr;
    nodeF->left = nullptr;
    nodeF->right = nullptr;
    nodeG->left = nullptr;
    nodeG->right = nullptr;
}

void Tree::preorder(Node *t) {
    if(t) {
        std::cout << t->data;
        preorder(t->left);
        preorder(t->right);
    }
}


void Tree::inorder(Node *t) {
    if(t) {
        inorder(t->left);
        std::cout << t->data;
        inorder(t->right);
    }
}


void Tree::postorder(Node *t) {
    if(t) {
        postorder(t->left);
        postorder(t->right);
        std::cout << t->data;
    }
}

Tree::~Tree() {
    std::cout << "Deleting all tree nodes..." << std::endl;
    delete this->root->left->left;
    delete this->root->left->right;
    delete this->root->left;
    delete this->root->right->left;
    delete this->root->right->right;
    delete this->root->right;
    delete this->root;
}