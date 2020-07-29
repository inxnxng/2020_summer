#include <iostream>
using namespace std;

int main() {
	char* str;
	str = new char [100];
	if (str == NULL) {
		cout << "this char is empty" << endl;
	}
	else {
		cout << "allocated" << endl;
		delete[] str;
		cout << "memory freed" << endl;
	}
}