#pragma once
#include"6.5.h"

class LinkedList {
	Node org;
public:
	LinkedList():org(0) {}
	~LinkedList() { clear(); }
	void clear() { while (!isEmpty()) delete remove(0); }
	bool isEmpty() { return getHead() == NULL; }
	Node* getHead() { return org.getLink(); }

	//주소를 return 할 것이고
	Node* getEntry(int pos) {
		//현재 위치하는 (git의 HEAD 느낌) 노드를 우선 복사해놓고
		Node* node = &org;
		//벡턱가 아니라서 순서대로 못감 그래서 노드의 첫번째부터 천천히 따라간다 --> node = node->getLink() like inline함수 처리
		//어디까지? pos번째 node까지 --> int i = -1; i < pos;
		//몇번을?  i < pos; i++  일 때까지 반복
		for (int i = -1; i < pos; i++ , node = node->getLink()) {
			if (node == NULL) break;
		}//그리고 node가 node->getLink()를 따라서 값이 바뀌어있을 것 아님
		//그 노드를 반환하면 pos번째에 있는 node값이 나오겠지
		return node;
	}
	void insert(int pos, Node* node) {
		//prev 노드를 넣을 자리 pos-1에 만들어놓고
		Node* prev = getEntry(pos-1);
		if (prev != NULL) {
			//Node class의 insertNext를 이용해 넣을 node 넣기
			prev->insertNext(node);
		}
	}
	//simple linked list이기 때문에 계속 전 노드로만 움직임
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(val))return p;
		}return NULL;
	}
	void replace(int pos, Node* node) {
		Node* prev = getEntry(pos - 1);
		if (prev!= NULL) {
			delete prev->removeNext();
			prev->insertNext(node);
		}
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			count++;
		}return count;
	}
	void display() {
		cout << "display" << endl;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			p->display();
		}cout << endl;
	}
}; 