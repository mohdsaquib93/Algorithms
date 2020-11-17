#include <iostream>
#include <unordered_set>
#include <queue>
#include "Graph.h"

unordered_set<char> V;
unordered_map<char, char> P;
unordered_map<char, int> D;
queue<char> Q;

typedef unordered_map<char, Graph::Node *> G;
void bfs(G &graph, char src)
{

	Q.emplace(src);
	V.insert(src);
	P.insert(make_pair(src, '$'));
	D.insert(make_pair(src, 0));

	while (!Q.empty()) {
		src = Q.front();
		Q.pop();
		Graph::Node *adjList = graph.at(src);
		while (adjList) {
			char key = adjList->key;
		
			if (V.find(key) == V.end()) {
				Q.emplace(key);
				V.insert(key);
				P.insert(make_pair(key, src));
				D.insert(make_pair(key, D.at(src) + 1));
			}
			
			adjList = adjList->next;
		}
	}
}

int main() {
	Graph *g = new Graph();
	g->createAdjacencyList();
	bfs(g->graph, 'a');

	cout << "Parent Matrix\n";
	auto itr = P.begin();
	while (itr != P.end()) {
		cout << itr->first << "->" << itr->second << endl;
		++itr;
	}
	
	cout << "Distance Matrix\n";
	auto itr_d = D.begin();
	while (itr_d != D.end()) {
		cout << itr_d->first << "->" << itr_d->second << endl;
		++itr_d;
	}

	return 0;
}
