#pragma once
#include"6.12.h"

class Node : public Line {
	Node* link;
public:
	Node(string str = "") :Line(str), link(NULL) {}
	~Node() {}
	void setLink(Node* node) { link = node; }
	Node* getLink() { return link; }
	void insertNode(Node* p) {
		if (p != NULL) {
			p->link = this->link;
			this->link = p;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) {this->link = removed->link;}
		// removed->link�� link->link->�̰���
		//���� ��带 ���� ����(link)���� �� link�� ���̴ϱ� ����� �ٴ��� ���
		return removed;
	}
};