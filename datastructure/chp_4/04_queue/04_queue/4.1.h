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
	//if���� �Ⱦ��� front�� rear�� ������ true�� ��ȯ�Ѵٰ� �� ��...
	bool isFull() { return (rear + 1) % MAX_SIZE == front; }
	void enqueue(int val) {
		if (isFull())	error("ť�� ��ȭ����");
		else {
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = val;
		}
	}
	int dequeue() {
		if (isEmpty())	error("ť�� �������");
		else {
			front = (front + 1) % MAX_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (isEmpty())	error("�������");
		else return data[(rear + 1) % MAX_SIZE];
	}
	void display() {
		cout << "ť ����" << endl;
		int max = (front < rear) ? rear : rear + MAX_SIZE;
		for (int i = front + 1; i <= max; i++) {
			cout << data[i % MAX_SIZE] << ", ";
		}cout << endl;
	}
};