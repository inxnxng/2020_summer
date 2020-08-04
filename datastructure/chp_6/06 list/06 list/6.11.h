#pragma once
#include"6.9.h"

//덱은 전단과 후단으로 요소의 삽입과 삭제가 가능하다.
//이중 연결 리스트로 구현한 리스트를 이용해 덱을 구현해보자.
class LinkedDeque : public DLinkedList {
public:
	void addFront(Node* node) { insert(0, node); }
	Node* deleteFront() { return remove(0); }	//front여서 위치부분에 0을 넣은 것

	Node* getFront() { return getEntry(0); }	//deleteFront()가 계속 맨 앞의 요소를 삭제하면서
												//다음 요소를 맨 앞으로 가져와서 우리는 계속 0부분의 요소만 가져오면 된다
	void addRear(Node* node) { insert(size(), node); }
	Node* deleteRear() { return remove(size() - 1); }
	Node* getRear() { return getEntry(size() - 1); }
};
