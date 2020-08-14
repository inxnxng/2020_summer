#pragma once
#include<iostream>
using namespace std;

class heapNode {
	int key;
public:
	heapNode(int k = 0) : key(k) {}
	~heapNode() {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { cout << this->key; }
};