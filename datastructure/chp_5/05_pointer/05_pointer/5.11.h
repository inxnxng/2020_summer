#pragma once
#include<iostream>
using namespace std;

class Node {
	Node* link;
	int data;
public:
	Node(int val = 0) : data(val), link(NULL) {}
	Node* getLink() { return link; }
	//�� link = node�� �����س��� ������..
	//���� link�� �ּҸ� �޴� ���̴ϱ� set�ϴ°� �̵��� ���� ���̹Ƿ� ��ġ �̵��� �ΰ���
	void setLink(Node* node) { link = node; }
	void display() { cout << data << "\t";}
};

class LinkedQueue {
	Node* front;
	Node* rear;
public:
	LinkedQueue() : front(NULL),rear(NULL){}
	//delete dequeue()�� ������ dequeue()�� return���� Node*�̱� ������
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); }
	bool isEmpty() { return front == NULL; }
	void enqueue(Node* p) {
		if (isEmpty()) front = rear = p;
		else {
			//���� rear�� p�� �̾��ְ�
			rear->setLink(p);
			//p�� rear�� �������ֱ�
			rear = p; 
		}
	}
	Node* dequeue() {
		if (isEmpty()) return NULL;
		//���ο� �۴�� ����
		Node* temp = front;
		//�۴�⸦ front�� ���� ��������
		front = front->getLink();
		if (front == NULL)rear == NULL;
		return temp;
	}

	Node* peek() { return front; }
	void display() {
		cout << "ť�� ���� : ";
		for (Node* p = front; p != NULL; p = p->getLink()) {
			p->display();
		}cout << endl;
	}
};