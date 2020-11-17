#include "GRA_CreateGraph.h"

typedef map<char, Graph::Node *> graph_map;

graph_map transpose(graph_map& g)
{
    graph_map grph_t;

    for (auto itr = g.begin(); itr != g.end(); ++itr)
        grph_t[itr->first] = nullptr;

    for (auto itr = g.begin(); itr != g.end(); ++itr) {
        char key = itr->first;
        Graph::Node *start = itr->second;
        while (start) {
            Graph::Node *node = new Graph::Node(key);
            node->next = grph_t[start->info];
            grph_t[start->info] = node;
            start = start->next;
        }
    }
    return grph_t;
}

int main()
{
    Graph *grph = new Graph();
    grph->createAdjacencyList();
//    cout << "Graph: ";
//    for (pair<char, Graph::Node *> g: grph->graph) {
//        cout << g.first << ":";
//        while (g.second) {
//            cout << g.second->info << " ";
//            g.second = g.second->next;
//        }
//        cout << "\n";
//    }
    Graph *grph_t = new Graph();
    grph_t->graph = transpose(grph->graph);
    cout << "Graph: ";
    for (pair<char, Graph::Node *> g: grph_t->graph) {
        cout << g.first << ":";
        while (g.second) {
            cout << g.second->info << " ";
            g.second = g.second->next;
        }
        cout << "\n";
    }
    return 0;
}