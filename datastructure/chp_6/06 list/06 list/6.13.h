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
		// removed->link는 link->link->이거지
		//다음 노드를 향한 상태(link)에서 또 link한 것이니까 결과는 다다음 노드
		return removed;
	}
};