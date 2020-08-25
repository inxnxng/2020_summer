#pragma once
#include"11.5.h"

#define MAX 256

class AdjListGraph {
protected : 
	int size;
	char vertices[MAX];
	Node* adj[MAX];		//각 정점의 인접 리스트

public:
	AdjListGraph() : size(0) {}
	~AdjListGraph() { reset(); }
	void reset() {
		for (int i = 0; i < size; i++) {
			if (adj[i] != NULL) delete adj[i];
		}size = 0; 
	}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX; }
	char getVertex(int i) { return vertices[i]; }
	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
	}
	void insertEdge(int u, int v) {		//간접삽입 연산
		adj[u] = new Node(v, adj[u]);	//인접 리스트에 추가
		//adj[v] = new Node(u, adj[v]);	//방향 그래프 ==> 주석 처리함
	}
	void display() {
		cout << "size : " << size << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << '\t';
			for (Node* v = adj[i]; v!= NULL; v = v->getLink()) {
				cout << getVertex(v->getId()) << '\t';
			}cout << endl;
		}
	}

	Node* adjacent(int v) { return adj[v]; }
};