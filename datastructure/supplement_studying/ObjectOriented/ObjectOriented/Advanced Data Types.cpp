//Pointer variable stores the address of memory : int* p;
//int x = 4;
//int *p = &x;

//The * operator is the inverse of the & operator.
//cout << *p;
//print the value at the memory address which is pointed by the pointer p

//포인터는 할당 할 때 참조 대상에 대해 & 연산을 통해 주로 주소값을 할당받음
//레퍼런스는 참조 대상을 그대로 할당한다
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

//생성
//double* nums = new double[size];
//제거
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
//list는 size를 알 수 있는 함수가 존재하지 않음

//int a[]해도 되고 int* a해도 되고
void print(const int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}cout << endl;
}

int main() {
	int a[] = { 2,3,4,5,6,7,8,9 }, * p;	//*p는 화살표
	//p points to first element of array a
	p = &a[0]; // p = a;라고 한거랑 똑같음
	for (int i = 0; i < 8; i++) {
		cout << *p << "\t";
		p++;
	}cout << endl;
}
*/

//2차원 벡터
/*

//말이 너무 길어지니까
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

//1차원 벡터
/*

vector<int> v1;	//이름만 가진 벡터가 생성됨 공간 자리만 생긴 것 공간이 생긴 것도 아님
vector<int> v2(10);	//10개의 벡터 공간이 생긴 것 안에 요소는 0으로 초기화
vector<int> v3(10, 8);	//10개의 벡터 공간이 생김. 8로 초기화됨
vector<int> v4{ 1,2,3,4 };	//우선 4개의 공간이 생기고 명시된 값들이 들어감

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