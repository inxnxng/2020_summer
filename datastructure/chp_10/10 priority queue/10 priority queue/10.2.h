#pragma once
#include"10.1.h"

#define MAX 200

class MaxHeap {
	heapNode node[MAX];
	int size;
public:
	MaxHeap() : size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX-1; }
	heapNode& getParent(int i) { return node[i / 2]; }
	heapNode& getLeft(int i) { return node[i * 2]; }
	heapNode& getRight(int i) { return node[i * 2 + 1]; }
	heapNode find() { return node[1]; }	//배열의 주소는 첫 번째 요소의 주소이기 때문에 find로 한 이유가 주소를 return 하기 위함

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				cout << endl;
				level *= 2;
			}node[i].display();
		}cout << "----------------------------"<<endl;
	}

	void insert(int key) {
		if (isFull()) return;
		int i = ++size; // 0부터 시작하니까 사이즈 자체로만 보려고 + 우선 사이즈 하나 늘리고 시작하자 insert할 것이니..
		while (i != 1 && key > getParent(i).getKey()) {	//size가 하나 늘려서 1이 된 비어있는 경우 가 아니여야 하고
														//넣으려는 key 값이 부모노드값보다 더 크면
			node[i] = getParent(i);						//부모를 자신의 노드로 끌어내리고
			i /= 2;										//부모 노드의 위치에(한 레벨 위로 상승)
		}node[i].setKey(key);							//자신의 값을 넣는다.
	} 

	heapNode remove() {
		if (isEmpty()) return NULL;
		heapNode item = node[1];
		heapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) { //자식이 사이즈를 벗어나지 않는다 즉 힙 트리를 벗어나지 않는 동안
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) child++;
			if (last.getKey() >= node[child].getKey()) break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}
};