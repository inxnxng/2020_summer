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
			cout << "什傾球 戚遭闘軒 : ";
			ThreadNode* q = root;
			while (q->getLeft()) q = q->getLeft();
			//inorder号縦戚糠稽 亜舌 図楕生稽 亜辞 獣拙背醤馬暗窮.. 益掘辞 亜舌 図楕生稽 亜澗 依精 while聖 戚遂梅壱
			do { 
				cout << "[ " << q->getData() << " ]\t";
				q = findSuccessor(q);
			} while (q);
			cout << endl;
		}
	}
	//板紗切 硲窒 敗呪
	ThreadNode* findSuccessor(ThreadNode* p) {
		ThreadNode* q = p->getRight();						//神献楕 切重 匂昔斗研 差紫背人虞たた
		if (q == NULL || p->bThread) return q;				//幻鉦 神献楕 匂昔斗亜 NULL戚暗蟹 什傾球戚檎 神献楕 匂昔斗研 鋼発馬食虞たたた
		while (q->getLeft() != NULL) q = q->getLeft();		//幻鉦 神献楕 切縦戚檎 陥獣 亜舌 図楕 葛球稽 戚疑馬食虞たたたた
		return q;
	}
};