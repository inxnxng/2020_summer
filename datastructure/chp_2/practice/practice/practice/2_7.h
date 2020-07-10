#pragma once
#include<cstdio>

#define MAX_DEGREE 80


// �������� �ȵȴٸ� �Ӽ�>C++>��ó����>��ó���� ���� �� ;_CRT_SECURE_NO_WARNINGS; �� �Է��ϰ� ������
class Polynomial {
	int degree;
	float coef[MAX_DEGREE];
public:
	Polynomial() { degree = 0; }

	void read() {
		printf("���׽� �ְ� ������ �Է��Ͻÿ� : ");
		scanf( "%d" , &degree);
		printf("�� ���� ����� �Է��Ͻÿ� (�� %d��) : ", degree + 1);
		for (int i = 0; i <= degree; i++)
			scanf("%f", coef + i);
	}
	void display(const char* strl  = "Poly = ") {
		printf("\t%s", strl);
		for (int i = 0; i < degree; i++)
			printf("%5.1f x^%d + ", coef[i], degree - i);
		printf("%4.1f\n", coef[degree]);
	}
	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;	//a ���׽��� �ڱ� ��ü�� ����
			for (int i = 0; i < b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i < a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
	}
	bool isZero() { return degree == 0; }
	void negate() {
		for (int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}
};