#include "8.2.h"

int main() {
	/*
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D', NULL, NULL);
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* b = new BinaryNode('B', d, e);
	BinaryNode* f = new BinaryNode('F', NULL, NULL);
	BinaryNode* c = new BinaryNode('C', f, NULL);
	BinaryNode* a = new BinaryNode('A', b, c);
	tree.setRoot(a);

	tree.inorder();
	cout << endl << endl;
	tree.preorder();
	cout << endl << endl;
	tree.postorder();
	cout << endl << endl;

	tree.levelorder();

	cout << "��� : " << tree.getCount() << endl;
	cout << "�ܸ� : " << tree.getLeafCount() << endl;
	cout << "���� : " << tree.getHeight() << endl;

	*/

	BinaryTree tree2;
	BinaryNode* n1 = new BinaryNode(3, NULL, NULL);
	BinaryNode* n2 = new BinaryNode(2, NULL, NULL);
	BinaryNode* n3 = new BinaryNode('*', n1, n2);
	BinaryNode* n4 = new BinaryNode(5, NULL, NULL);
	BinaryNode* n5 = new BinaryNode(6, NULL, NULL);
	BinaryNode* n6 = new BinaryNode('-', n4, n5);
	BinaryNode* n7 = new BinaryNode('+', n3, n6);

	tree2.setRoot(n7);
	cout << "��� ��� : " << tree2.evaluate() << endl;
}