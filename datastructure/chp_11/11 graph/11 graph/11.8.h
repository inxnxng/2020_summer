#pragma once
#include"11.1.h"

class SrchAMGraph : public AdjMatGraph {
	
public:
	bool visited[MAX];
	void resetVisited() {
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v) {
		visited[v] = true;
		cout << getVertex(v) << "\t";
		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false) DFS(w);
		}
	}
};