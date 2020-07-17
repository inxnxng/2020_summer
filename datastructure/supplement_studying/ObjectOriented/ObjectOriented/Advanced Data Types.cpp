//Pointer variable stores the address of memory : int* p;
//int x = 4;
//int *p = &x;

//The * operator is the inverse of the & operator.
//cout << *p;
//print the value at the memory address which is pointed by the pointer p

//�����ʹ� �Ҵ� �� �� ���� ��� ���� & ������ ���� �ַ� �ּҰ��� �Ҵ����
//���۷����� ���� ����� �״�� �Ҵ��Ѵ�
//int a = 10;
//int *p = &a;
//int &r = a;

//https://ssinyoung.tistory.com/16

#include <iostream>
#include <vector>
using namespace std;

//char
/*


bool find_char(const char* s, char ch) {
	while (*s != '\0') {
		if (*s == ch) {
			return true;
		}s++;
	}return false;
}

int main() {
	const char* phrase = "this is a phrase";
	for (char ch = 'a'; ch <= 'z'; ch++) {
		if (!find_char(phrase, ch))	cout << "NOT : ";
		cout << "in " << phrase << endl;
	}
}

*/

//dynamic array
/*

//����
//double* nums = new double[size];
//����
//delete[] nums;

int main() {
	double sum = 0.0;
	double* nums;
	int size;

	cout << " enter size";
	cin >> size;

	if (size > 0) {
		nums = new double[size];
		for (int i = 0; i < size; i++) {
			cin >> nums[i];
			sum += nums[i];
		}
		cout << "everything" << endl;
		for (int i = 0; i < size; i++) {
			cout << nums[i] << "\t";
		}cout << endl;
		delete[] nums;
	}
}
*/

//list
/*
//list�� size�� �� �� �ִ� �Լ��� �������� ����

//int a[]�ص� �ǰ� int* a�ص� �ǰ�
void print(const int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}cout << endl;
}

int main() {
	int a[] = { 2,3,4,5,6,7,8,9 }, * p;	//*p�� ȭ��ǥ
	//p points to first element of array a
	p = &a[0]; // p = a;��� �ѰŶ� �Ȱ���
	for (int i = 0; i < 8; i++) {
		cout << *p << "\t";
		p++;
	}cout << endl;
}
*/

//2���� ����
/*

//���� �ʹ� ������ϱ�
using Matrix = vector<vector<int>>;

vector<vector<int>> a(2, vector<int>(3));//row 2 col 3

int main() {
	int num = 0;
	for (vector<int>& i : a) {
		for (int& k : i) {
			k = num;
			num++;
		}
	}

	for (vector<int>& i : a) {
		for (int& k : i) {
			cout << k << "\t";
		}cout << endl;
	}
}

*/

//1���� ����
/*

vector<int> v1;	//�̸��� ���� ���Ͱ� ������ ���� �ڸ��� ���� �� ������ ���� �͵� �ƴ�
vector<int> v2(10);	//10���� ���� ������ ���� �� �ȿ� ��Ҵ� 0���� �ʱ�ȭ
vector<int> v3(10, 8);	//10���� ���� ������ ����. 8�� �ʱ�ȭ��
vector<int> v4{ 1,2,3,4 };	//�켱 4���� ������ ����� ��õ� ������ ��

vector<int> primes(vector<int>& v) {
	vector<int> result;
	for (int& i : v) {
		if (i % 2 == 0) {
			result.push_back(i);
		}
	}
	return result;
}

int main() {
	vector<int> l1{ 1, 2, 3,4,5,6,7,8,9,10 };
	l1.push_back(4);
	cout << l1.at(3) << endl;
	l1.size();

	for (int& i : primes(l1)) {
		cout << i << "\t";
	}cout << endl;
	int sum = 0;
	for (int& i : l1) {
		sum += i;
	}cout << sum << endl;
	cout << l1.empty() << endl;
	l1.clear();
	cout << l1.empty() << endl;

}

*/

//function pointer
/*

int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }
//function pointer
int eva(int(*f)(int, int), int x, int y) { return f(x, y); }

int main() {
	int (*func)(int, int);
	func = add;
	cout << func(1, 2) << endl;
}

*/

//pointer and reference 2
/*

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int var1 = 5, var2 = 10;
	cout << &var1 << "\t" << &var2 << endl;
	swap(var1, var2);
	cout << &var1 << "\t" << &var2 << endl;
	swap(var1, var2);
	cout << &var1 << "\t" << &var2 << endl;
}

*/

//pointer and reference 1
/*

int main()
{
	int x = 4;
	int* p = &x;
	cout << endl << "(1)[address of x: " << &x << "]" << "[value of x: " << x << "]";
	cout << endl << "(1)[pointed by p: " << p << "]" << "[value of pointed p : " << *p << "]";
	p = &x;
	cout << endl << "(2)[address of x: " << &x << "]" << "[value of x: " << x << "]";
	cout << endl << "(2)[pointed by p: " << p << "]" << "[value of pointed p : " << *p << "]";
	*p = 7;
	cout << endl << "(3)[address of x: " << &x << "]" << "[value of x: " << x << "]";
	cout << endl << "(3)[pointed by p: " << p << "]" << "[value of pointed p : " << *p << "]";
	return 0;
}

*/