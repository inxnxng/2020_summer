#include <iostream>
using namespace std;

struct MyNewType {
	int i;
	float f;
};

int main() {
	MyNewType s, * ps;

	//객체 s의 주소를 ps에 저장한다
	ps = &s;
	//(*ps).i = 2 와 동일
	ps->i = 2;
	//(*ps).f = 3.14f 와 동일
	ps->f = 3.14f;
}