#pragma once
#include"8.5.h"



class BinaryTree {
	BinaryNode* root;
public:
	BinaryTree() :root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void inorder() { cout << "inorder : " << endl; inorder(root); }
	void inorder(BinaryNode* node) {
		if (node != NULL) {
			inorder(node->getLeft());
			cout << "[ " << node->getData() << " ]" << "\t";
			inorder(node->getRight());
		}
	}
	void preorder() { cout << "preorder : " << endl; preorder(root); }
	void preorder(BinaryNode* node) {
		if (node != NULL) {
			cout << "[ " << node->getData() << " ]" << "\t";
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}
	void postorder() { cout << "postorder : " << endl; postorder(root); }
	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			cout << "[ " << node->getData() << " ]" << "\t";
		}
	}
	void levelorder() {
		cout << "levelorder : " << endl;
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					cout << "[ " << n->getData() << " ]\t";
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}cout << endl;
		}
	}
	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* n) {
		if (n == NULL) return 0;
		if (n->isLeaf()) return 1;
		else return getLeafCount(n->getLeft()) + getLeafCount(n->getRight());
	}

	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* n) {
		if (n == NULL) return 0;
		int hLeft = getHeight(n->getLeft());
		int hRight = getHeight(n->getRight());
		return (hLeft > hRight ? hLeft + 1 : hRight + 1);
	}

	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode* n) {
		if (n == NULL) return 0;
		if (n->isLeaf()) return n->getData();	//�ܸ� ���� ���ڰ� �����ݾ�
												//�ܸ� ��尡 �ƴ϶�� ���� �Ǵ� �����ڰ� �� ����
		else {									//�ܸ� ��尡 �ƴ϶���� ����
			int op1 = evaluate(n->getLeft());	//���� ����Ʈ���� ����Ͽ� ����� op1�� ����. ��ȯ ȣ���� ����� ��
			int op2 = evaluate(n->getRight());	//������ ����Ʈ���� ����Ͽ� ����� op2�� ����. ��ȯ ȣ�⿡ ����� ��
			switch (n->getData()) {
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
			}
			return 0;
		}
	}
};
