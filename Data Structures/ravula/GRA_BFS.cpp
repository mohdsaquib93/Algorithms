#include "GRA_CreateGraph.h"

unordered_set<char> visited;
unordered_map<char, char> path;
unordered_map<char, int> dist;
queue<char> Q;

void BFS(map<char, Graph::Node *>& graph, int src)
{
    Q.emplace(src);
    visited.insert(src);
    path[src] = '$';
    dist[src] = 0;

    while (!Q.empty()) {
        char src = Q.front();
        Q.pop();
        Graph::Node *start = graph[src];
        while (start) {
            if (visited.find(start->info) == visited.end()) {
                Q.emplace(start->info);
                visited.insert(start->info);
                path[start->info] = src;
                dist[start->info] = dist[src] + 1;
            }
            start = start->next;
        }
    }

}

int main()
{
    Graph *grph  = new Graph();
    grph->createAdjacencyList();

//    cout << "Graph: ";
//    for (pair<char, Graph::Node *> g: grp->graph) {
//        cout << g.first << ":";
//        while (g.second) {
//            cout << g.second->info << " ";
//            g.second = g.second->next;
//        }
//        cout << "\n";
//    }
    BFS(grph->graph, 'a');

    cout << "Path Matrix: ";
    for (pair<char, char> p: path) {
        cout << p.first << ":" << p.second;
        cout << "\n";
    }

    cout << "Distance Matrix: ";
    for (pair<char, int> d: dist) {
        cout << d.first << ":" << d.second;
        cout << "\n";
    }
    return 0;
}