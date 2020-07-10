#include<iostream>
#include<cstdio>

class Car {
protected:
	int speed;
	char name[40];
public:
	int gear;
	Car() {}//������
	~Car() {}//�Ҹ���
	Car(int s, int g, char* n)
		: speed(s), gear(g) {	//��� �ʱ�ȭ ����Ʈ(�⺯ �ʱ�ȭ
		strcpy(name, n);		//������ �Լ� ��ü(name ��� �ʱ�ȭ
	}
	void changeGear(int g = 4) {
		gear = g;
	}
	void speedUp() {
		speed += 5;
	}
	void display() {
		printf("[%s] : ���=%d�� �ӵ�=%dkmph\n", name, gear, speed);
	}
	void whereAmI() {
		printf("��ü �ּ� = %x\n", this);		//��ȣ this�� �Ἥ ��ü �ּҸ� �������±���
	}
};