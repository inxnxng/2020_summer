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
	Student(int i = 0, char* n = "마", char* d="마과") { set(i, n, d); }
	void set(int i, char* n, char* d) {
		id = i;
		strcpy(name, n);
		strcpy(dept, d);
	}
	void display() {
		printf("학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};

