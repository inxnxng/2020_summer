#include <iostream>
using namespace std;

struct MyNewType {
	int i;
	float f;
};

int main() {
	MyNewType s, * ps;

	//��ü s�� �ּҸ� ps�� �����Ѵ�
	ps = &s;
	//(*ps).i = 2 �� ����
	ps->i = 2;
	//(*ps).f = 3.14f �� ����
	ps->f = 3.14f;
}