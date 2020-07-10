#include<cstdio>
#include<iostream>

void swap(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void main() {
	int a = 1, b = 2;
	printf("swap Àü a = %d, b = %d\n", a, b);
	swap(a, b);
	printf("swap ÈÄ a = %d, b = %d\n", a, b);
}