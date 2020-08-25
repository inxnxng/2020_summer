#pragma once

#include"11.6.h"

class SrchALGraph : public AdjListGraph {
	bool visited[MAX];
public : 
	void resetVisited() {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}
	bool isLinked(int u, int v) {
		for (Node* p = adj[u]; p != NULL; p = p->getLink()) {
			if (p->getId() == v) return true;
		}return false;
	}

	void DFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << "\t";

		for (Node* p = adj[v]; p != NULL; p = p->getLink()) {
			if (visited[p->getId()] == false) DFS(p->getId());
		}
	}
};