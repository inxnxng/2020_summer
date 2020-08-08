#pragma once
#include<iostream>
using namespace std;

class ThreadNode {
	int data;
	ThreadNode* left;
	ThreadNode* right;

public:
	bool bThread;
	ThreadNode(int val, ThreadNode* l, ThreadNode* r, bool bTH)
		: data(val), left(l), right(r), bThread(bTH) {}
	int getData() { return data; }
	void setRight(ThreadNode* node) { right = node; }
	void setLeft(ThreadNode* node) { left = node; }
	ThreadNode* getLeft() { return left; }
	ThreadNode* getRight() { return right; }
};

class ThreadTree {
	ThreadNode* root;
public:
	ThreadTree() :root(NULL) {}
	void setRoot(ThreadNode* node){ root = node; }
	bool isEmpty() { return root == NULL; }

	void threadInorder() {
		if (!isEmpty()) {
			cout << "������ ����Ʈ�� : ";
			ThreadNode* q = root;
			while (q->getLeft()) q = q->getLeft();
			//inorder����̹Ƿ� ���� �������� ���� �����ؾ��ϰŵ�.. �׷��� ���� �������� ���� ���� while�� �̿��߰�
			do { 
				cout << "[ " << q->getData() << " ]\t";
				q = findSuccessor(q);
			} while (q);
			cout << endl;
		}
	}
	//�ļ��� ȣ�� �Լ�
	ThreadNode* findSuccessor(ThreadNode* p) {
		ThreadNode* q = p->getRight();						//������ �ڽ� �����͸� �����ؿͶ󤿤�
		if (q == NULL || p->bThread) return q;				//���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ�Ͽ��󤿤���
		while (q->getLeft() != NULL) q = q->getLeft();		//���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵��Ͽ��󤿤�����
		return q;
	}
};