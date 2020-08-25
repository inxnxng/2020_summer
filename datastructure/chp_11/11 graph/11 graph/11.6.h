#pragma once
#include"11.5.h"

#define MAX 256

class AdjListGraph {
protected : 
	int size;
	char vertices[MAX];
	Node* adj[MAX];		//�� ������ ���� ����Ʈ

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
	void insertEdge(int u, int v) {		//�������� ����
		adj[u] = new Node(v, adj[u]);	//���� ����Ʈ�� �߰�
		//adj[v] = new Node(u, adj[v]);	//���� �׷��� ==> �ּ� ó����
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