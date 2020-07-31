#include<iostream>
using namespace std;

int** allocate(int r, int c) {
	if (r <= 0 || c <= 0) return NULL;

	int** mat = new int* [r];
	for (int i = 0; i < r; i++) {
		mat[i] = new int[c];
	}return mat;
}

void free(int** mat, int r, int c) {
	if (mat != NULL) {
		for (int i = 0; i < r; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}
}

void setRandom(int** mat, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			mat[i][k] = rand()%100;
		}
	}
}

void printInt(int** mat, int r, int c) {
	cout << "행의 수 : " << r << ", 열의 수 : " << c << endl;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			cout << mat[i][k] << " ";
		}cout << endl;
	}
}

int main() {
	int** mat;
	int r, c;

	cout << "행과 열의 수를 입력하세요 : " << endl;
	cin >> r >> c;
	mat = allocate(r, c);
	setRandom(mat, r, c);
	printInt(mat, r, c);
	free(mat, r, c);
}