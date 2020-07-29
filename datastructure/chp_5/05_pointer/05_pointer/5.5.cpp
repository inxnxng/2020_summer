#include<iostream>
using namespace std;

int** allocate(int r, int c) {
	if (r <= 0 || c <= 0) return NULL;

	int** mat = new int* [r];
	for (int i = 0; i < r; i++) {
		mat[i] = new int[c];
	}return mat;
}

int main() {

}