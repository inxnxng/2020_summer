#include<iostream>
using namespace std;

void swap_r(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap_a(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_a2(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
}


int main() {
	int a = 1; 
	int b = 2;
	cout << a << ", " << b << endl;
	cout << &a << ", " << &b << endl;

	swap_a(&a, &b);
	cout << a << ", " << b << endl;
	cout << &a << ", " << &b << endl;

	//작동 안한다
	swap_a2(&a, &b);				
	cout << a << ", " << b << endl;
	cout << &a << ", " << &b << endl;

	swap_r(a, b);
	cout << a << ", " << b << endl;
	cout << &a << ", " << &b << endl;

	//std에 있는 swap
	swap(a, b);
	cout << a << ", " << b << endl;
	cout << &a << ", " << &b << endl;
}


