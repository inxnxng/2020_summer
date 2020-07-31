#include"5.11.h"

int main() {
	LinkedQueue que;

	for (int i = 1; i <= 10; i++) {
		que.enqueue(new Node(i));
	}
	que.display();
	delete que.dequeue();
	delete que.dequeue();
	delete que.dequeue();
	delete que.dequeue();
	que.display();
	que.enqueue(new Node(4));
	que.enqueue(new Node(5));
	que.enqueue(new Node(6));
	que.enqueue(new Node(7));
	que.enqueue(new Node(8));
	que.display();
}