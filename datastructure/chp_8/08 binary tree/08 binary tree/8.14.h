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
			cout << "스레드 이진트리 : ";
			ThreadNode* q = root;
			while (q->getLeft()) q = q->getLeft();
			//inorder방식이므로 가장 왼쪽으로 가서 시작해야하거든.. 그래서 가장 왼쪽으로 가는 것은 while을 이용했고
			do { 
				cout << "[ " << q->getData() << " ]\t";
				q = findSuccessor(q);
			} while (q);
			cout << endl;
		}
	}
	//후속자 호출 함수
	ThreadNode* findSuccessor(ThreadNode* p) {
		ThreadNode* q = p->getRight();						//오른쪽 자신 포인터를 복사해와라ㅏㅏ
		if (q == NULL || p->bThread) return q;				//만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환하여라ㅏㅏㅏ
		while (q->getLeft() != NULL) q = q->getLeft();		//만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동하여라ㅏㅏㅏㅏ
		return q;
	}
};