#include<iostream>
using namespace std;
#define MAX 100

inline void error(string msg) {
	cout << "¿À·ù : " << msg << endl;
	exit(1);
}
class ArrayStack {
	int top;
	int data[MAX];
public:
	ArrayStack() { top = -1; }
	ArrayStack() { delete[] data; }
	void push(int& e) {
		if (!isFull()) {
			top += 1;
			data[(top)] = e;
		}
		else error("Already Full");
	}
	int pop(int& e) {
		if (!isEmpty()) {
			top -= 1;
			return data[top + 1];
		}
	}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	bool isFull() {
		if (top == MAX) return true;
		else return false;
	}

	int peek() {
		if (!isEmpty()) {
			return data[top];
		}
	}
	int size() {
		return (top + 1);
	}
	void display() {
		cout << "Displaying all data" << endl;
		for (int i = 0; i <= top; i++) {
			cout << data[i] << endl;
		}
	}
};