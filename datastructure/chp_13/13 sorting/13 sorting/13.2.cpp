#include "13.1.h"

static void initRandom(int list[], int n, int max = 100) {
	for (int i = 0; i < n; i++) {
		list[i] = rand() % max;
	}
}

static void printArray(int arr[], int n, string str = "array") {
	cout << str << " = ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}cout << endl;
}

//13.2
/*
int main() {
	int list[16];
	int n = 16;
	initRandom(list, n);
	printArray(list, n, "Original : ");
	selectionSort(list, n);
	printArray(list, n, "Selection : ");
}
*/

//13.4
int main() {
	int list[16];
	int n = 16;
	initRandom(list, n);
	printArray(list, n, "original : ");


}