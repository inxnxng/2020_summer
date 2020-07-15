#include"3.4.h"

int main() {
	StudentStack a;
	a.push(Student(11121211, "가", "가과"));
	a.push(Student(22222222, "나", "나과"));
	a.push(Student(33333333, "다", "다과"));
	a.display();
	a.pop();
	a.display();
	return 0;
}