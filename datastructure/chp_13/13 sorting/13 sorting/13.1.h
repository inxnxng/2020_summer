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
		for (j = i-1; j>=0 && A[j]>key ;j--) {			//A[j]>key는 배열이 이미 다 정렬된 상황이라면 for문을 나오도록 주문한 것
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
		for (j = i - 1; j >= 0 && f(A[j], key) < 0; j--) {
			A[j + 1] = A[j];
		}A[j+1] = key;
	}
}

void bubblesort(int a[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int k = 0; k < i; k++) {
			if (a[k] > a[k + 1]) swap(a[k], a[k + 1]);
		}
	}
}

static void sortGapInsertion(int a[], int first, int last, int gap) {	//정렬의 범위는 first에서 last까지
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = a[i];
		for (j = i - gap; j >= first && key < a[j]; j = j - gap) {
			a[j + gap] = a[j];
		}a[j + gap] = key;
	}
}

void shellsort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		printArray(a, n, "shell..");
		if ((gap % 2) == 0) gap++;
		for (int i = 0; i < gap; i++) {
			sortGapInsertion(a, i, n - 1, gap);
		}
	}
}

#define MAX 1024

static void merge(int a[], int left, int mid, int right) {
	int i, j, k = left, l;
	static int sorted[MAX];
	for (i = left, j = mid + 1; i <= mid && j <= right;) sorted[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
	if (i > mid)
		for (l = j; l <= right; l++, k++)
			sorted[k] = a[l];
	else
		for (l = i; l <= mid; l++, k++)
			sorted[k] = a[l];
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}