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
	//(rear+1) 한 이유는 front는 맨 앞의 요소를 가리키고 있는 것이 아니라 맨 앞의 공백을 가리키고 있기 때문이다
	void enqueue(BinaryNode* n) {
		if (isFull()) error("포화상태");
		else {
			rear = (rear + 1) % MAX;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue(){
		if (isEmpty())error("공백상태");
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}
};

