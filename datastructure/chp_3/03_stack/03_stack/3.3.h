#pragma once

#include<cstring>
#include<cstdio>
#include<cstdlib>

#define MAX_S 100

class Student {
	int id;
	char name[MAX_S];
	char dept[MAX_S];
public : 
	Student(int i = 0, char* n = "��", char* d="����") { set(i, n, d); }
	void set(int i, char* n, char* d) {
		id = i;
		strcpy(name, n);
		strcpy(dept, d);
	}
	void display() {
		printf("�й�:%-15d ����:%-10s �а�:%-20s\n", id, name, dept);
	}
};

