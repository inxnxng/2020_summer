#include<iostream>
#include<cstdio>

class Car {
protected:
	int speed;
	char name[40];
public:
	int gear;
	Car() {}//생성자
	~Car() {}//소멸자
	Car(int s, int g, char* n)
		: speed(s), gear(g) {	//멤버 초기화 리스트(멤변 초기화
		strcpy(name, n);		//생성자 함수 몸체(name 멤버 초기화
	}
	void changeGear(int g = 4) {
		gear = g;
	}
	void speedUp() {
		speed += 5;
	}
	void display() {
		printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed);
	}
	void whereAmI() {
		printf("객체 주소 = %x\n", this);		//오호 this를 써서 객체 주소를 가져오는구만
	}
};