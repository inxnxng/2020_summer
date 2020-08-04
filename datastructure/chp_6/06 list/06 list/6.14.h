#pragma once
#include"6.13.h"

class LinkedList {
protected:
	Node org;
public:
	LinkedList() : org("") {}
	~LinkedList() { clear(); }
	void clear() { while (!isEmpty()) delete remove(0); }
	bool isEmpty() { return getHead() == NULL; }
	Node* getHead() { return org.getLink(); }
	Node* getEntry(int pos) {
		Node* node = &org;
		for (int i = -1; i < pos; i++, node = node->getLink()) {
			if (node == NULL) break;
		}return node;
	}
	void insert(int pos, Node* node) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNode(node);
		}
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	Node* find(string& str) {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(str)) return p;
		}return NULL;
	}
	void replace(int pos, Node* node) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNode(node);
		}
	}
	int size() {
		int count = 0; 
		for (Node* p = getHead(); p != NULL; p = p->getLink()) count++;
		return count;
	}
};