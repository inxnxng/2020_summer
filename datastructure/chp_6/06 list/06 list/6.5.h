#pragma once
#include<iostream>
using namespace std;

class Node {
	int data;
	Node* link;
public:
	Node(int val)
		: data(val), link(NULL) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }	//���� ����� �ּҰ� ���� ����� ���� �ּҷ� ����!!
	bool hasData(int val) { return val == data;}
	void insertNext(Node* node) {
		if (node != NULL) {
			node = this->link;
			link = node;
		}
	
	}
	Node* removeNext() {}

};

class LinkedList {
	Node* head;
};