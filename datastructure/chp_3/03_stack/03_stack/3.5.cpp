#include"3.4.h"

int main() {
	StudentStack a;
	a.push(Student(11121211, "��", "����"));
	a.push(Student(22222222, "��", "����"));
	a.push(Student(33333333, "��", "�ٰ�"));
	a.display();
	a.pop();
	a.display();
	return 0;
}