#pragma once
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;
#define MAX_SIZE 100

inline void error(string str) {
	cout << str << endl;
	exit(1);
}

class CircleQ {
protected : 
	int front;
	int rear;
	int data[MAX_SIZE];
public:
	CircleQ() { front = rear = 0; }
	~CircleQ() {}
	bool isEmpty() { return front == rear; }	
	//if문을 안쓰고 front와 rear이 같으면 true를 반환한다고 한 것...
	bool isFull() { return (rear + 1) % MAX_SIZE == front; }
	void enqueue(int val) {
		if (isFull())	error("큐는 포화상태");
		else {
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {
		if (isEmpty())	error("큐는 공백상태");
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (isEmpty())	error("공백상태");
		else return data[(rear + 1) % MAX_SIZE];
	}
	void display() {
		cout << "큐 내용" << endl;
		int max = (front < rear) ? rear : rear + MAX_SIZE;
		for (int i = front + 1; i <= max; i++) {
			cout << data[i % MAX_SIZE] << ", ";
		}cout << endl;
	}
};