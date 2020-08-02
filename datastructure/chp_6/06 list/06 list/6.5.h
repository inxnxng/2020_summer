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
	void setLink(Node* next) { link = next; }	//다음 노드의 주소가 현재 노드의 다음 주소로 들어가게!!
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