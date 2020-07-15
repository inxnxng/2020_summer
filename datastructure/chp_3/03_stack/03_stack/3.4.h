#pragma once
# include "3.3.h"
const int MAX_Si = 100;




class StudentStack {
	int top;
	Student data[MAX_Si];
public:
	StudentStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_Si; }

	void push(Student e) {
		if (isFull()) exit(1);
		data[++top] = e;
	}
	Student pop() {
		if (isEmpty()) exit(1);
		return data[top--];
		//return은 top으로 받고 그 후 -- 실행된다
	}
	Student peek() {
		if (isEmpty()) exit(1);
		return data[top];
	}
	void display() {
		printf("전체 학생 수 %d\n", top + 1);
		for (int i = 0; i <= top; i++) {
			data[i].display();
		}
	}
};