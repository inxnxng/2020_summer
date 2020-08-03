#pragma once
#include <iostream>
using namespace std;

class Node {
	Node* prev;
	Node* next;
	int data;
public:
	Node(int val = 0) : data(val), prev(NULL), next(NULL) {}
	Node* getPrev() { return prev; }
	Node* getNext() { return next; }
	void setPrev(Node* node) { prev = node; }
	void setNext(Node* node) { next = node; }
	void display() { cout << this->data << "\t"; }
	bool  hasData(int val) { return data == val; }

	void insertNext(Node* node) {
		if (node != NULL) {
			node->prev = this;
			node->next = this->next;
			//(3)단계를 실행할 수 있느냐
			if (next != NULL) next->prev = node;
			this->next = node;
		}
	}
	Node* remove() {
		if (prev!= NULL) { prev->next = this->next; }
		if (next != NULL) { next->prev = this->prev; }
		return this;
	}
};