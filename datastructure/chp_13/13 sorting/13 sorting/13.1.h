#pragma once
#include <iostream>
using namespace std;

inline void swap(int& x, int& y) {
	int t = x;
	x = y;
	y = t;
}

void selectionSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[least]) least = j;
		}
		swap(A[i], A[least]);
	}
}

void insertionSort(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i-1; j>=0 && A[j]>key ;j--) {			//A[j]>key�� �迭�� �̹� �� ���ĵ� ��Ȳ�̶�� for���� �������� �ֹ��� ��
			A[j + 1] = A[j];
		}A[j + 1] = key;
	}
}

inline int ascend(int x, int y) { return y - x; }
inline int descend(int x, int y) { return x - y; }

void insertionSortFn(int A[], int n, int(*f)(int, int)) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0 && f(A[key], key) < 0; j--) {
			A[j + 1] = A[j];
		}A[j+1] = key;
	}
}