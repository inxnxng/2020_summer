#include<iostream>
using namespace std;

void foo(int a) {
	cout << "foo : " << a << endl;
}

int main() {
	void(*f)(int);

	f = foo;
	f(10);
	(*f)(10);
}