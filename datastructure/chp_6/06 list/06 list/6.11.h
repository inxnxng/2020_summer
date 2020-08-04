#pragma once
#include"6.9.h"

//���� ���ܰ� �Ĵ����� ����� ���԰� ������ �����ϴ�.
//���� ���� ����Ʈ�� ������ ����Ʈ�� �̿��� ���� �����غ���.
class LinkedDeque : public DLinkedList {
public:
	void addFront(Node* node) { insert(0, node); }
	Node* deleteFront() { return remove(0); }	//front���� ��ġ�κп� 0�� ���� ��

	Node* getFront() { return getEntry(0); }	//deleteFront()�� ��� �� ���� ��Ҹ� �����ϸ鼭
												//���� ��Ҹ� �� ������ �����ͼ� �츮�� ��� 0�κ��� ��Ҹ� �������� �ȴ�
	void addRear(Node* node) { insert(size(), node); }
	Node* deleteRear() { return remove(size() - 1); }
	Node* getRear() { return getEntry(size() - 1); }
};
