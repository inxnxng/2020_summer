#include"6.11.h"

int main(){
	LinkedDeque deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2)deq.addFront(new Node(i));
		else deq.addRear(new Node(i));
	}
	deq.display();
	delete deq.deleteFront();
	delete deq.deleteRear();
	delete deq.deleteFront();
	deq.display();
}