#pragma once

#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

#define MAX_S 100

class Student {
	int id;
	string name;
	string dept;
public:
	Student(int i = 0, string n = "", string d = "")
		:id(i), name(n), dept(d)
	{
		cout << "�����Ǿ����ϴ�" << endl;
	}

	void display() {
		cout << "�й� : " << id << " ���� : " << name << " �а� : " << dept << endl;

	}
};