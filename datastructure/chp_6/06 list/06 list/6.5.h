#pragma once
#include<iostream>
using namespace std;

class Node {
	int data;
	Node* link;		//node�� link�� ����������
public:
	Node(int val=0)
		: data(val), link(NULL) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }	//���� ����� �ּҰ� ���� ����� ���� �ּҷ� ����!!
	bool hasData(int val) { return val == data;}
	void insertNext(Node* node) {
		if (node != NULL) {
			//������ �����̰�
			node->link = link;
			//this�� ����Ű�� ��ũ�� node�� �����Ѵ� ��....
			link = node;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) {
			link = removed->link;
		}return removed;
	}
	void display() {
		cout << data << "\t";
	}
};