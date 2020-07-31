#include "5.9.h"

int main() {
	LinkedStack stack;
	stack.push(new Node(20191, "가", "가과"));
	stack.push(new Node(20192, "나", "가과"));
	stack.push(new Node(20193, "다", "가과"));
	stack.push(new Node(20194, "라", "가과"));
	stack.push(new Node(20195, "마", "가과"));
	stack.push(new Node(20196, "바", "가과"));
	stack.push(new Node(20197, "사", "가과"));
	stack.push(new Node(20198, "아", "가과"));
	stack.display();

	Node* node = stack.pop();
	cout << "pop" << endl;
	node->display();
	cout << endl;

	delete node;
	stack.display();
}