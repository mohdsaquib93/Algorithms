#include <bits/stdc++.h>
#include "TRE_CreateBinTree.h"
#include "LL_Create_Doubly_LL.h"

struct SNode {
    char data;
    SNode *next;
};

using namespace std;

int numOfNodes(Node *t)
{
    if(!t)
        return 0;

    return numOfNodes(t->left) + numOfNodes(t->right) + 1;
}

int numOfLeafNodes(Node *t)
{
    if(!t)
        return 0;

    if (!t->left && !t->right)
        return 1;

    return numOfLeafNodes(t->left) + numOfLeafNodes(t->right);
}

int numOfNonLeafNodes(Node *t)
{
    if(!t)
        return 0;

    if (!t->left && !t->right)
        return 0;

    return 1 + numOfNonLeafNodes(t->left) + numOfNonLeafNodes(t->right);
}

int numOfFullNodes(Node *t)
{
    if(!t)
        return 0;

    return numOfFullNodes(t->left) + numOfFullNodes(t->right) + (t->left && t->right);
}
int numOfNonFullNodes(Node *t)
{
    if(!t)
        return 0;

    return numOfNonFullNodes(t->left) + numOfNonFullNodes(t->right) + (!t->left || !t->right);
}

int height(Node *t)
{
    if(!t)
        return 0;

    return max(height(t->left), height(t->right)) + (t->left || t->right);
}

void recordHorizontalDistanceRange(Node *t, int d, int &min, int &max)
{
    if(t) {
        if (d < min)
            min = d;
        if (d > max)
            max = d;
        recordHorizontalDistanceRange(t->left, d - 1, min, max);
        recordHorizontalDistanceRange(t->right, d + 1, min, max);
    }
}

void printVerticalOrder(Node *t, int d, int hd)
{
    if(t) {
        if(d == hd)
            cout << t->data << " ";
        printVerticalOrder(t->left, d - 1, hd);
        printVerticalOrder(t->right, d + 1, hd);
    }
}
void verticalOrderTraversal(Node *t, int min, int max)
{
    if(t) {
        recordHorizontalDistanceRange(t, 0, min, max);
        for (int i = min; i <= max; ++i)
            printVerticalOrder(t, 0, i);
        cout << endl;
    }
}

void verticalOrderTraversal2(Node *t, int d, unordered_map<int, forward_list<char>> &hash)
{
    if(t) {
        hash[d].push_front(t->data);
        verticalOrderTraversal2(t->left, d - 1, hash);
        verticalOrderTraversal2(t->right, d + 1, hash);
    }
}

SNode *createSNode(Node *t)
{
    SNode *node = new SNode();
    node->next = nullptr;
    node->data = t->data;
    return node;
}

void extendList(DNode<SNode *> *head, Node *t)
{
    SNode *node = createSNode(t);
    node->next = head->data;
    head->data = node;
}

void verticalOrderTraversal3(Node *t, int d, DoublyList<SNode *> &list, int dir)
{
    if(t) {
        DNode<SNode *> *head = list.head;
        if(!dir) {
            list.add_left(createSNode(t));
            head = list.head;
        }

        if(dir == -1) {
            if (!head->left) {
                list.add_left(createSNode(t));
            }
            else
                extendList(head->left, t);
            head = list.head;
        }

        else if(dir == 1) {
            if(!head->right) {
                list.add_right(createSNode(t));
            }
            else
                extendList(head->right, t);
            head = list.head;
        }
        verticalOrderTraversal3(t->left, d - 1, list, -1);
        list.head = head;
        verticalOrderTraversal3(t->right, d + 1, list, 1);
    }
}

void levelOrderTraversal(Node *t)
{
    if(t) {
        queue<Node *> q;
        q.push(t);

        while(!q.empty()) {
            Node *tmp = q.front();
            q.pop();
            cout << tmp->data;
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
        }
    }
}

int main()
{
    Tree *tree = new Tree();
    int min, max;
    unordered_map<int, forward_list<char>> hash;
    DoublyList<SNode *> list;
    tree->populate();
    Node *root = tree->root;
//    cout << numOfNodes(root) << endl;
//    cout << numOfLeafNodes(root) << endl;
//    cout << numOfNonLeafNodes(root) << endl;
//    cout << numOfFullNodes(root) << endl;
//    cout << numOfNonFullNodes(root) << endl;
//    cout << height(root) << endl;

//    min = max = 0;
//    verticalOrderTraversal(root, min, max);

//    verticalOrderTraversal2(root, 0, hash);
//    auto min_r = min_element(hash.begin(), hash.end());
//    auto max_r = max_element(hash.begin(), hash.end());
//    for(int i = min_r->first; i <= max_r->first; ++i)
//        for(auto itr = hash[i].begin(); itr != hash[i].end(); ++itr)
//            cout << *itr << " ";
//    cout << endl;

//    verticalOrderTraversal3(root, 0, list, 0);
//    DNode<SNode *> *curr = list.head;
//    while(curr->left)
//        curr = curr->left;
//
//    while(curr) {
//        SNode *node = curr->data;
//        while(node) {
//            cout << node->data << " ";
//            node = node->next;
//        }
//        curr = curr->right;
//    }

    levelOrderTraversal(root);
    return 0;
}
