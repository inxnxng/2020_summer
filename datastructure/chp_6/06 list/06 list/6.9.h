#pragma once
#include "6.8.h"

class DLinkedList {
	Node org;
public:
	DLinkedList() : org(0) {}
	~DLinkedList() { while (!isEmpty()) delete remove(0); }
	bool isEmpty() { return getHead() ==NULL; }
	Node* getHead() { return org.getNext(); }
	Node* getEntry(int pos) {
		Node* node = &org;
		for (int i = -1; i < pos; i++, node = node->getNext()) {
			if (node == NULL) break;
		}return node;
	}
	void insert(int pos, Node* node) {
		Node* prev = getEntry(pos - 1);
		if (node != NULL) prev->insertNext(node);
	}
	Node* remove(int pos) {
		Node* node = getEntry(pos);
		return node->remove();
	}
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getNext()) {
			if (p->hasData(val))return p;
		}return NULL;
	}
	void replace(int pos, Node* node) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->getNext()->remove();
			prev->setNext(node);
		}
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getNext()) count++;
		return count;
	}
	void display() {
		cout << "이중 연결 리스트" << endl;
		for (Node* p = getHead(); p != NULL; p = p->getNext()) { p->display(); }
		cout << endl;
	}
	void clear() {
		while (!isEmpty()) delete remove(0);
	}
};