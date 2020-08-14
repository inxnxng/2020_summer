#pragma once

#include"10.1.h"

#define MAX 200

class MinHeap {
	heapNode node[MAX];
	int size;
public:
	MinHeap() : size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX - 1; }
	heapNode& getParent(int i) { return node[i / 2]; }
	heapNode& getLeft(int i) { return node[i * 2]; }
	heapNode& getRight(int i) { return node[i * 2 + 1]; }
	heapNode find() { return node[1]; }	//�迭�� �ּҴ� ù ��° ����� �ּ��̱� ������ find�� �� ������ �ּҸ� return �ϱ� ����

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				cout << endl;
				level *= 2;
			}node[i].display();
		}cout << "----------------------------" << endl;
	}

	void insert(int key) {
		if (isFull()) return;
		int i = ++size; // 0���� �����ϴϱ� ������ ��ü�θ� ������ + �켱 ������ �ϳ� �ø��� �������� insert�� ���̴�..
		while (i != 1 && key < getParent(i).getKey()) {	//size�� �ϳ� �÷��� 1�� �� ����ִ� ��� �� �ƴϿ��� �ϰ�
														//�������� key ���� �θ��尪���� �� ũ��
			node[i] = getParent(i);						//�θ� �ڽ��� ���� �������
			i /= 2;										//�θ� ����� ��ġ��(�� ���� ���� ���)
		}node[i].setKey(key);							//�ڽ��� ���� �ִ´�.
	}

	heapNode remove() {
		if (isEmpty()) return NULL;
		heapNode item = node[1];
		heapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) { //�ڽ��� ����� ����� �ʴ´� �� �� Ʈ���� ����� �ʴ� ����
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey()) child++;
			if (last.getKey() <= node[child].getKey()) break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}
};