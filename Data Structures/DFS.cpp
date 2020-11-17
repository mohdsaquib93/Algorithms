#include <iostream>
#include <unordered_set>
#include <stack>
#include "Graph.h"

typedef unordered_map<char, Graph::Node *> G;
unordered_set<char> V;
unordered_map<char, pair<int, int>> T;
stack<pair<char, Graph::Node *>> st;
int t = 0;

void DFS(G &graph, char src)
{
	T[src].first = t++;
	V.insert(src);
	Graph::Node *adjList = graph.at(src);
	while (adjList) {
		char key = adjList->key;
		if (V.find(key) == V.end())
			DFS(graph, key);
		adjList = adjList->next;
	}
	T[src].second = t++;
}

void Iter_DFS(G &graph, char src)
{
	st.push(make_pair(src, nullptr));
	V.insert(src);
	T[src].first = t++;
	Graph::Node *adjList = graph.at(src);
	while (!st.empty()) {
		while (adjList) {
			src = adjList->key;
			if (V.find(src) == V.end()) {
				V.insert(src);
				st.push(make_pair(src, adjList));
				T[src].first = t++;
				adjList = graph.at(src);
				continue;
			}
			adjList = adjList->next;
		}

		if (st.top().second)
			adjList = st.top().second->next;
		T[st.top().first].second = t++;
		st.pop();
	}
}


int main()
{
	Graph *g = new Graph();
	g->createAdjacencyList();
	Iter_DFS(g->graph, 'a');

	auto itr = T.begin();
	while (itr != T.end()) {
		cout << itr->first << " -> (" << itr->second.first << ", " << itr->second.second << ")" << endl;
		++itr;
	}

	return 0;
}
