#include<iostream>
using namespace std;

class Student {
	int id;
	string name;
	string dept;

public:
	Student()
		: id(0), name(""), dept("") {}

	Student(int i, string& n, string& d)
		:id(i), name(n), dept(d) {}

	~Student() {}

	void display() {
		cout << "학번 : " << id << ", 이름 : " << name << ", 전공 : " << dept << endl;
	}
};

class Node :public Student {
	Node* link;	//다음 노드를 가리키는 포인터 변수
public:
	Node(int i,string n, string d)
		: Student(i, n, d) {
		link = NULL;
	}
	~Node() {}

	Node* getlink() { return link; }
	void setLink(Node* next) { link = next; }
};

class LinkedStack {
	Node* top;
public:
	LinkedStack() { top = NULL; }
	~LinkedStack() { while (!isEmpty()) delete pop(); }
	bool isEmpty() { return top == NULL; }		// 제발 이 표현에 익숙해지자
	void push(Node* item) {
		if (isEmpty()) top = item;
		else {
			item->setLink(top);
			top = item;
		}
	}
	Node* pop() {
		if (isEmpty()) return NULL;
		Node* p = top;
		top = top->getlink();
		return p;
	}

	void display() {
		cout << "[Linked Stack]" << endl;
		for (Node* p = top; p != NULL; p = p->getlink()) {
			p->display();
		}cout << endl;
	}
};

