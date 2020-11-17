#include "GRA_CreateGraph.h"

typedef map<char, Graph::Node *> graph_map;
map<char, char> path;
map<char, int> visited;
stack<char> st;

bool DFS_Vertex(graph_map &g, char src)
{
    visited[src] = 1;
    Graph::Node *start = g.at(src);
    while (start) {
        if (visited.find(start->info) == visited.end()) {
            path[start->info] = src;
            if (DFS_Vertex(g, start->info))
                return true;
        }
        else if (path[src] != start->info) {
            st.push(src);
            return true;
        }
        start = start->next;
    }
    return false;
}

bool detectCycle(graph_map &g)
{
    path[g.begin()->first] = '$';
    for (auto itr = g.begin(); itr != g.end(); ++itr) {
        char src = itr->first;
        if (visited.find(src) == visited.end())
            if (DFS_Vertex(g, src))
                return true;
    }
    return false;
}

int main()
{
    Graph *grph = new Graph();
    grph->createAdjacencyList();
    if (detectCycle(grph->graph)) {
        cout << "Cycle is present: ";
        while (st.top() != '$')
            st.push(path[st.top()]);

        st.pop();
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }

    else
        cout << "No Cycle";

    return 0;
}

