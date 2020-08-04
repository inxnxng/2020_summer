#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 1000

class Line {
	string data;
public:
	Line(string& line) {  data = line; }
	void print(FILE* fp = stdout) { fprintf(fp, "%s", data); }
	bool hasData(string& str) { return data.compare(str) == 0; }
};