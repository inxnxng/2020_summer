#include "5.9.h"

int main() {
	LinkedStack stack;
	stack.push(new Node(20191, "��", "����"));
	stack.push(new Node(20192, "��", "����"));
	stack.push(new Node(20193, "��", "����"));
	stack.push(new Node(20194, "��", "����"));
	stack.push(new Node(20195, "��", "����"));
	stack.push(new Node(20196, "��", "����"));
	stack.push(new Node(20197, "��", "����"));
	stack.push(new Node(20198, "��", "����"));
	stack.display();

	Node* node = stack.pop();
	cout << "pop" << endl;
	node->display();
	cout << endl;

	delete node;
	stack.display();
}