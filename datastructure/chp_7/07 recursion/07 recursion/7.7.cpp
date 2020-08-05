#include<iostream>
using namespace std;

int fibIter(int n) {
	if (n < 2) return n;
	else {
		int f0, fi = 1, f1 = 0;
		for (int i = 2; i <= n; i++) {
			f0 = fi;
			fi += f1;
			f1 = f0;
		}return fi;
	}
}

int main() {
	cout << fibIter(10) << endl;
}