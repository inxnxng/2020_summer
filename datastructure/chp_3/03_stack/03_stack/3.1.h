#include <iostream>
#include <cstdio>
#include <cstdlib>

//오류 상황이 발생하더라도 프로그램을 종료하고 싶지 않아서 처리기 추가
inline void error(char* msg) {
	std::cout << msg << std::endl;
	exit(1);
}

const int MAX_SIZE = 20;
class ArrayStack {
private : 
	int top;
	int data[MAX_SIZE];
public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}
	void wrong() { std::cout << "잘못된 입력" << std::endl; }
	void push(int item) {
		if (!isFull()) {
			data[top + 1] = item;
			top += 1;
		}
		else wrong();
	}
	int pop() {
		if (!isEmpty()) {
			int e = data[top];
			top -= 1;
			return e;
		}
		else return 0;
	}
	int peek() {
		if (!isEmpty()) {
			return data[top];
		}
		else return 0;
	}
	void size() {
		if (isEmpty()) std::cout << "empty" << std::endl;
		else if (isFull()) std::cout << "full" << std::endl;
		else  std::cout << "stack has "<<top+1 << " size" << std::endl;
	}
	bool isEmpty() { if (top == -1) return true; else return false; }
	bool isFull() { if (top == MAX_SIZE-1) return true; else return false; }
	void display() {
		if (isEmpty()) std::cout << "empty" << std::endl;
		else if (isFull()) std::cout << "full" << std::endl;
		else {
			std::cout << "stack has ";
			for (int i = 0; i <= top; i++) {
				std::cout<< data[i] << " ";
			}
			std::cout << " element(s)" << std::endl;
		}
	}
};