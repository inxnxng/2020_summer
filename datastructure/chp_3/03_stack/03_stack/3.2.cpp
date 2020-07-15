#include "3.1.h"

int main() {
	ArrayStack stack;
	for (int i = 1; i <= 10; i++) {
		stack.push(i);
	}
	stack.display();
	stack.pop();
	stack.pop();
	stack.size();
	stack.pop();
	stack.push(2323);
	stack.size();
	stack.display();
}