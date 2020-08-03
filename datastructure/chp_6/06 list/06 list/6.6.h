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

	//�ּҸ� return �� ���̰�
	Node* getEntry(int pos) {
		//���� ��ġ�ϴ� (git�� HEAD ����) ��带 �켱 �����س���
		Node* node = &org;
		//���ΰ� �ƴ϶� ������� ���� �׷��� ����� ù��°���� õõ�� ���󰣴� --> node = node->getLink() like inline�Լ� ó��
		//������? pos��° node���� --> int i = -1; i < pos;
		//�����?  i < pos; i++  �� ������ �ݺ�
		for (int i = -1; i < pos; i++ , node = node->getLink()) {
			if (node == NULL) break;
		}//�׸��� node�� node->getLink()�� ���� ���� �ٲ������ �� �ƴ�
		//�� ��带 ��ȯ�ϸ� pos��°�� �ִ� node���� ��������
		return node;
	}
	void insert(int pos, Node* node) {
		//prev ��带 ���� �ڸ� pos-1�� ��������
		Node* prev = getEntry(pos-1);
		if (prev != NULL) {
			//Node class�� insertNext�� �̿��� ���� node �ֱ�
			prev->insertNext(node);
		}
	}
	//simple linked list�̱� ������ ��� �� ���θ� ������
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