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
		cout << "�й� : " << id << ", �̸� : " << name << ", ���� : " << dept << endl;
	}
};

class Node :public Student {
	Node* link;	//���� ��带 ����Ű�� ������ ����
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
	bool isEmpty() { return top == NULL; }		// ���� �� ǥ���� �ͼ�������
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

