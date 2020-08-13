#pragma once
#include<iostream>
using namespace std;
#define MAX 100
inline void error(string str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

class BinaryNode {
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(int val, BinaryNode* l = NULL, BinaryNode* r = NULL)
		:data(val), left(l), right(r) {}
	void setData(char val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return (left == NULL) && (right == NULL); }
	BinaryNode* search(int key) {}
};
class CircularQueue {
	int front;
	int rear;
	BinaryNode* data[MAX];

public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX == front; }
	//(rear+1) �� ������ front�� �� ���� ��Ҹ� ����Ű�� �ִ� ���� �ƴ϶� �� ���� ������ ����Ű�� �ֱ� �����̴�
	void enqueue(BinaryNode* n) {
		if (isFull()) error("��ȭ����");
		else {
			rear = (rear + 1) % MAX;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue() {
		if (isEmpty())error("�������");
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}
};
class BinaryTree {
	
public:
	BinaryNode* root;
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


class BinSrchTree : public BinaryTree {
public:
	BinSrchTree() {}
	~BinSrchTree() {}

	BinaryNode* searchRecur(BinaryNode* n, int key) {
		if (n == NULL) return NULL;
		else if (key == n->getData()) return n;
		else if (key < n->getData()) return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}
	//Ű������ ��带 Ž���ϴ� �Լ� (�ݺ����� ���)
	BinaryNode* searchIter(BinaryNode* n, int key) {
		while (n != NULL) {
			if (key == n->getData()) return n;
			else if (key < n->getData()) n = n->getLeft();
			else n = n->getRight();
		}return NULL;
	}

	void insertRecur(BinaryNode* r, BinaryNode* n) {
		if (n->getData() == r->getData()) return;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL) r->setLeft(n);
			else insertRecur(r->getLeft(), n);
		}
		else {
			if (r->getRight() == NULL) r->setRight(n);
			else insertRecur(r->getRight(), n);
		}
	}

	void remove(BinaryNode* parent, BinaryNode* node) {
		//case 1 : �ܸ� ����� ���
		if (node->isLeaf()) {
			if (parent == NULL) root = NULL;
			else {
				if (parent->getLeft() == node) parent->setLeft(NULL);
				else parent->setRight(NULL);
			}
		}
		//case 2 : ���ʿ� �ڽ� ��带 ���� ���
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight(); // ���ʿ� �ڽ��� �ִٸ� ���� �����͸� �����ʿ� �ִٸ� ������ �����͸�
			if (node == root) root = child;
			else {
				if (parent->getLeft() == node)parent->setLeft(child); //�����Ϸ��� ��尡 �θ� ����� ���� �ڽ��̾��ٸ� �θ� ��� ���ʿ� child �ڽ� ��� ����
				else parent->setRight(child);
			}
		}
		//case 3 : �����Ϸ��� ��尡 �ΰ��� �ڽ��� ��� �ִ� ���
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ->getLeft();
			}
			//���� �ڽ��̾��ٸ� 
			if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
			else succp->setRight(succ->getRight());
			node->setData(succ->getData());
			node = succ;
		}
		delete node;
	}
	BinaryNode* search(int key) {
		BinaryNode* node = searchRecur(root, key);
		if (node != NULL) cout << "Ž�� ���� : " << node->getData() << " = " << node << endl;
		else cout << "Ž�� ����" << endl;
		return node;
	}

	void insert(BinaryNode* node) {
		if (node == NULL) return;
		if (isEmpty()) root = node;
		else insertRecur(root, node);
	}

	void remove(int key) {
		if (isEmpty()) return;
		//���� ����� �θ�� �ڽ�
		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		while (node != NULL && node->getData() != key) {
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}
		if (node == NULL) {
			cout << "Ű�� �������� �ʴ´�" << endl;
			return;
		}
		else remove(parent, node);
	}

};

/*
//Ű������ ��带 Ž���ϴ� �Լ� (��ȯ���� ���)
BinaryNode* BinaryNode::search(int key) {
	if (key == data) return this;
	else if (key < data && left != NULL) return left->search(key);
	else if (key > data && right != NULL) return right->search(key); // ������� ������ �������� Ž���ϰڴ� ���� ������� �ٷ� return�ؾ߰��� ���°� Ž���ϰ� ���� ���� �����ϱ�
	else return NULL;
}
*/