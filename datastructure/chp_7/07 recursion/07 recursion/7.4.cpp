#include<iostream>
#include<ctime>
using namespace std;

double slowPower(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i ++) result = result * x;
	return result;
}

double Power(double x, int n) {
	if (n == 0) return 1;
	else if (n % 2==0) {return Power(x * x, n / 2); }
	else { return x * Power(x * x, (n - 1) / 2); }
}

int main() {
	clock_t start;
	clock_t end;
	clock_t result;

	start = (float)clock();
	Power(2, 5000);
	end = clock();
	result = (float)(end - start);
	cout << result << endl;

	slowPower(2, 5000);
	end = clock();
	result = (float)(end - start);
	cout << result << endl;

	return 0;
}