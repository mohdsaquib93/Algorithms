#include "GRA_CreateGraph.h"

unordered_set<char> visited;
unordered_map<char, char> path;
unordered_map<char, pair<int, int>> time_map;
int t = 0;

void DFS_Vertex(map<char, Graph::Node *>& graph, char src)
{
    visited.insert(src);
    Graph::Node *start = graph.at(src);
    time_map[src].first = ++t;
    while (start) {
        if (visited.find(start->info) == visited.end()) {
            visited.insert(start->info);
            path[start->info] = src;
            DFS_Vertex(graph, start->info);
        }
        start = start->next;
    }
    time_map[src].second = ++t;
}


void DFS(map<char, Graph::Node *>& graph)
{
    char src = graph.begin()->first;
    path[src] = '$';
    DFS_Vertex(graph, graph.begin()->first);
}
int main()
{
    Graph *grph = new Graph();
    grph->createAdjacencyList();
    DFS(grph->graph);

    cout << "Path Matrix: ";
    for (pair<char, char> p: path) {
        cout << p.first << ":" << p.second;
        cout << "\n";
    }

    cout << "Time Map: ";
    for (pair<char, pair<int, int>> t: time_map) {
        cout << t.first << ":" << t.second.first << "," << t.second.second;
        cout << "\n";
    }
    return 0;
}
