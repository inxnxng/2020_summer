#pragma once
#include "8.1.h"

inline void error(string str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

#define MAX 100

class CircularQueue {
	int front;
	int rear;
	BinaryNode* data[MAX];

public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX == front; }
	//(rear+1) �� ������ front�� �� ���� ��Ҹ� ����Ű�� �ִ� ���� �ƴ϶� �� ���� ������ ����Ű�� �ֱ� �����̴�
	void enqueue(BinaryNode* n) {
		if (isFull()) error("��ȭ����");
		else {
			rear = (rear + 1) % MAX;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue(){
		if (isEmpty())error("�������");
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}
};

