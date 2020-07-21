#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

#define MAX 10

inline void error(string msg) {	//왜 string&은 작동하지 않는가?
	cout << msg << endl;
	exit(1);
}

class OperandStack {
	double data[MAX];
	int top;

public:
	OperandStack() { top = -1; }
	~OperandStack() { delete[] data; cout << "deleted" << endl; }
	bool isEmpty() {return top == -1;}
	bool isFull() { return top == MAX-1; }
	void push(double e) {
		if (!isFull()) {
			error("FULL");
			data[++top] = e;
		}
	}
	double pop() {
		if (isEmpty()) error("EMPTY");
		return data[top--];
	}
};