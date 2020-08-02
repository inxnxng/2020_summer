#pragma once
#include <iostream>
using namespace std;

# define MAX 100

class ArrayList {
private : 
	int data[MAX];
	int length;
public:
	ArrayList() { length = 0; }
	~ArrayList() {}

	//pos�� ��ġ ������
	void insert(int pos, int item) {
		if (!isFull() && pos >= 0 && pos <=length) {
			for (int i = length; i >= pos; i--) {
				data[i] = data[i - 1];
			}
			data[pos] = item;
			length += 1;
		}else error_code();
	}
	void remove(int pos) {
		if (!isEmpty() && pos >= 0 && pos < length) {
			for (int i = pos; i < length; i++) {
				data[i] = data[i + 1];
			}
			length -= 1;
		}else error_code();
	}
	bool isFull() { return length == MAX; }
	bool isEmpty() { return length == 0; }
	int getEntry(int pos) { return data[pos]; }
	bool find(int item) {
		for (int i = 0; i < length; i++) {
			if (data[i] == item) return true;
		}return false;
	}
	void replace(int pos, int item) { data[pos] = item; }
	int size() { return (length); }
	void display() {
		cout << "����Ʈ : ";
		for (int i = 0; i < length; i++) {
			cout << data[i] << "\t";
		}cout << endl;
	}
	void clear() {
		length = 0;
	}
};