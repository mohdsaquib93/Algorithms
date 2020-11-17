#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    struct Node {
        char info;
        Node *next;
        Node(char c): info(c), next(nullptr) {}
    };

    map<char, Node *> graph;
    Node *createNode(char c);
    void createAdjacencyList();
};

Graph::Node *Graph::createNode(char info)
{
    Node *node = new Node(info);
    return node;
}

void Graph::createAdjacencyList()
{
    /* a -- b
     * | \  |
     * |  \ |
     * c -- d
     *      |
     *      |
     *      e
     *
     */

    this->graph['a'] = createNode('b');
    this->graph['a']->next = createNode('c');
    this->graph['a']->next->next = createNode('d');

    this->graph['b'] = createNode('d');
//    this->graph['b']->next = createNode('a'); //

    this->graph['c'] = createNode('d');
//    this->graph['c']->next = createNode('a'); //

    this->graph['d'] = createNode('e');
//    this->graph['d']->next = createNode('a'); //
//    this->graph['d']->next->next = createNode('b'); //
//    this->graph['d']->next->next->next = createNode('c'); //

//    this->graph['e'] = createNode('d');
    this->graph['e'] = nullptr;
}
