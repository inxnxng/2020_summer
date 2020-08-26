#pragma once
#include "11.8.h"

class ConnectedComponentGraph : public SrchAMGraph {
	int label[MAX];
public:
	void labelDFS(int v, int color) {
		SrchAMGraph::visited[v] = true;
		label[v] = color;
		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false) {
				labelDFS(w, color);
			}
		}
	}
	void findConnectedComponent() {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (visited[i] == false) labelDFS(i, ++count);
		}cout << "그래프 연결 성분 개수 = = " << count << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << "\t" << label[i];
		}cout << endl;
	}
};