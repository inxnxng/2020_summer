#include "10.2.h"

void heapSort(int a[], int n) {
	MaxHeap h;
	for (int i = 0; i < n; i++) {
		h.insert(a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		a[i] = h.remove().getKey();
	}
}

int main() {
	MaxHeap heap;
	int data[10];

	for (int i = 0; i < 10; i++) data[i] = rand() % 100;
	cout << "정렬 전 : " << endl;
	for (int i = 0; i < 10; i++) cout << data[i] << "\t";

	cout << endl<<endl<< "-----------------" << endl;
	heapSort(data, 10);
	cout << "정렬 후 : " << endl;
	for (int i = 0; i < 10; i++) cout << data[i] << "\t";
	cout << "-----------------" << endl;


	return 0;
}