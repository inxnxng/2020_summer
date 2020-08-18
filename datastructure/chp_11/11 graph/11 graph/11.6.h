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
};