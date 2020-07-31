#pragma once
#include<iostream>
using namespace std;

class Node {
	Node* link;
	int data;
public:
	Node(int val = 0) : data(val), link(NULL) {}
	Node* getLink() { return link; }
	//왜 link = node만 설정해놓은 것인지..
	//현재 link의 주소를 받는 것이니까 set하는게 이동할 때만 쓰이므로 위치 이동용 인거지
	void setLink(Node* node) { link = node; }
	void display() { cout << data << "\t";}
};

class LinkedQueue {
	Node* front;
	Node* rear;
public:
	LinkedQueue() : front(NULL),rear(NULL){}
	//delete dequeue()한 이유는 dequeue()의 return형이 Node*이기 때문임
	~LinkedQueue() { while (!isEmpty()) delete dequeue(); }
	bool isEmpty() { return front == NULL; }
	void enqueue(Node* p) {
		if (isEmpty()) front = rear = p;
		else {
			//원래 rear과 p를 이어주고
			rear->setLink(p);
			//p를 rear로 연결해주기
			rear = p; 
		}
	}
	Node* dequeue() {
		if (isEmpty()) return NULL;
		//새로운 작대기 생성
		Node* temp = front;
		//작대기를 front에 새로 연결해줌
		front = front->getLink();
		if (front == NULL)rear == NULL;
		return temp;
	}

	Node* peek() { return front; }
	void display() {
		cout << "큐의 내용 : ";
		for (Node* p = front; p != NULL; p = p->getLink()) {
			p->display();
		}cout << endl;
	}
};