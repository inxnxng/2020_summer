#pragma once
#include<iostream>
using namespace std;

class Node {
	int data;
	Node* link;		//node임 link가 ㅏㅏㅏㅏㅏ
public:
	Node(int val=0)
		: data(val), link(NULL) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }	//다음 노드의 주소가 현재 노드의 다음 주소로 들어가게!!
	bool hasData(int val) { return val == data;}
	void insertNext(Node* node) {
		if (node != NULL) {
			//포인터 복사이고
			node->link = link;
			//this가 가리키는 링크에 node를 저장한다 임....
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