#include"4.3.h"

void main(){
	CircleD deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2) deq.addFront(i);
		else deq.addRear(i);
	}
	deq.display();

}