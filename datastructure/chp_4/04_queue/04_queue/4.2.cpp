#include "4.1.h"

void main() {
	CircleQ que;
	for (int i = 1; i < 10; i++) {
		que.enqueue(i);
	}
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
	que.enqueue(3);
	que.display();
	que.display();
}