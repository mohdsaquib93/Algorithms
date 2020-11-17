#include <unordered_map>

using namespace std;

class Graph {
public:
    struct Node {
        char key;
        Node *next;
        Node(char c): key(c), next(nullptr) {}
    };
	
	unordered_map<char, Graph::Node *> graph;
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
    this->graph['b']->next = createNode('a');

    this->graph['c'] = createNode('d');
    this->graph['c']->next = createNode('a');

    this->graph['d'] = createNode('e');
    this->graph['d']->next = createNode('a');
    this->graph['d']->next->next = createNode('b');
    this->graph['d']->next->next->next = createNode('c');

    this->graph['e'] = createNode('d');
}
