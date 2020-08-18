#pragma once
#include<iostream>
#include<cstdio>

using namespace std;

#define MAX 256

class AdjMatGraph {
protected:
	int size;				//정점의 개수
	char vertices[MAX];		//정점의 이름
	int adj[MAX][MAX];		//인접 행렬

public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX; }
	void reset() {
		size = 0; 
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				setEdge(i, j, 0);
			}
		}
	}
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else cout << "그래프 정점 개수 초과" << endl;
	}
	//간선 삽입 연산 : 무방향 그래프의 경우임
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);	//방향 그래프에서라면 이 라인은 삭제된다
	}
	void display(FILE* fp = stdout) {
		cout << "정점의 개수 : " << size << endl;
		for (int i = 0; i < size; i++) {
			cout << getVertex(i) << "\t";
			for (int j = 0; j < size; j++) {
				cout << getEdge(i, j) << "\t";
			}cout << endl;
		}
	}

	void load(char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n;
			fscanf(fp, "%d", &n);
			
			for (int i = 0; i < n; i++) {
				char str[80];
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for (int k = 0; k < n; k++) {
					int val;
					fscanf(fp, "%d", &val);
					if (val != 0) insertEdge(i, k);
				}
			}
			fclose(fp);
		}
	}
	void store(char* filename) {
		FILE* fp = fopen(filename, "w");
		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}
};