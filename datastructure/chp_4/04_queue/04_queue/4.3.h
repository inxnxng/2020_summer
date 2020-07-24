#pragma once
#include "4.1.h"

class CircleD : public CircleQ {
public : 
	CircleD() {}
	void addRear(int val) { enqueue(val); }
	int deleteFront() { return dequeue(); }
	int getFront() { return peek(); }
	void addFront(int val) {
		if (isFull())	error("µ¦ Æ÷È­");
		else {
			data[front] = val;
			front = (front - 1+MAX_SIZE) % MAX_SIZE;
		}
	}
	int deleteRear() {
		if (isEmpty())	error("µ¦ °ø¹é");
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
			return ret;
		}
	}
	int getRear() {
		if (isEmpty())	error("µ¦ °ø¹é");
		else return data[rear];
	}
	void display() {
		cout << "µ¦ »óÅÂ" << endl;
		int max = (front < rear) ? rear : rear + MAX_SIZE;
		for (int i = front + 1; i <= max; i++) {
			cout << data[i + MAX_SIZE] << ", ";
		}cout << endl;
	}
};