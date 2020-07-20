/*
10. Software Component 1

- pointer p --> p[i] == *(p+i)
	p[i][j] == *(*(p+j)+i)
-auto 사용시 조심하기

11. Software Component 2

- pass by reference &
- static은 전역 변수를 사용하는 것보다 훨씬 안전하다
	은행 클래스에서 계좌 수 선언
	https://wikidocs.net/21186

- friend클래스는 선언된 다른 클래스의 private 과 protected에 접근할 수 있음

*/

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
//friend ostream& operator<<(ostream& os, const Point& point)

//class& ~ <-> class
/*

//overloading : https://modoocode.com/202
//"기본적으로 대입 연산자 함수는, 기존의 사칙연산 연산자 함수와는 다르게
// Class& 타입을 리턴한다.
// 대입 연산자 자체의 의미를 생각해 볼 때 리턴값은 void와 다름이 없지만
// 리턴 값을 주는 것이 인터페이스 차원에서 더 낫기 때문!

// Class 타입을 리턴하지 않고 굳이 Complex& 타입을 리턴하는 이유는
// 대입 연산 이후에 이 값을 가지고 다른 연산을 수행하지 않기 때문

//계산을 하지 않고 값을 반환하므로 레퍼런스를 걸어두지 않았던 것
//Complex operator+(const Complex& c) const;
//Complex operator-(const Complex& c) const;
//Complex operator*(const Complex& c) const;
//Complex operator/(const Complex& c) const;

//이후 계산을 바로 하니까 레퍼런스를 걸어두었고
//Complex& operator+=(const Complex& c);
//Complex& operator-=(const Complex& c);
//Complex& operator*=(const Complex& c);
//Complex& operator/=(const Complex& c);

class MyString {
	char* string_content;	//문자열을 가리키는 포인터
	int string_length;	//문자열 길이
	int memory_capacity;	//현재 할당된 용량
public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;
	char at(int i) const;

	int compare(MyString& str);
	bool operator==(MyString& str);

};

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];	//바로 입력 불가능하니
												//크기 만큼의 방을 만들어서
	for (int i = 0; i != string_length; i++)
		string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		cout << string_content[i];
	}cout << endl;
}

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}
}

char MyString::at(int i) const {
	if (i >= string_length || i < 0) return 0;
	else return string_content[i];
}

int MyString::compare(MyString& str) {
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	if (string_length == str.string_length) return 0;

	else if (string_length > str.string_length)
		return 1;
	return -1;
}

bool MyString::operator==(MyString& str) {
	return !compare(str);
}


int main() {
	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");

	if (str1 == str2)
		std::cout << "str1 와 str2 같다." << std::endl;
	else
		std::cout << "st1 와 str2 는 다르다." << std::endl;

	if (str2 == str3)
		std::cout << "str2 와 str3 는 같다." << std::endl;
	else
		std::cout << "st2 와 str3 는 다르다" << std::endl;
}




*/

//Overloading
/*
Point operator+(const Point& p1, const Point& p2) {
	Point result;
	result.x = p1.x + p2.x;
	result.y = p1.y + p2.y;
	return result;
}
*/

/*
class Point {
	double x;
	double y;
public:
	Point();
	Point(int x, int y);
	void setPoint(int x, int y);
	int getX(void) const;
	int getY(void) const;
	Point& operator+(const Point& point);
	Point& operator=(const Point& point);
};

Point::Point()
{
	x = y = 0;
}
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Point::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Point::getX(void) const
{
	return this->x;
}
int Point::getY(void) const
{
	return this->y;
}

Point& Point::operator+(const Point& point)
{
	Point result(this->x + point.getX(), this->y + point.getY());
	return result;
}

Point& Point::operator=(const Point& point)
{
	this->x = point.getX();
	this->y = point.getY();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	return os << "(" << point.getX() << "," << point.getY() << ")";
}





int main()
{
	Point* pP1, * pP2;
	pP1 = new Point;
	pP2 = new Point(1, 2);
	pP1->setPoint(10, 20);
	*pP2 = *pP1 + *pP2;
	cout << "[X:" << pP1->getX() << "]" << "[Y:" << pP1->getY() << "]" << endl;
	cout << *pP2 << endl;
	delete pP1;
	delete pP2;
}
*/

//Pointers to Objects
/*


class Point {
	double x;
	double y;
public:

	void set_x(double x) {
		this->x = x;
	}

};

int main() {

	//Point Definition
	Point pt1;
	Point* pt2;

	//Operator &
	pt2 = &pt1;

	//
	//Point* pt2 = &p
	//
	//이렇게 선언하면 pt1을 만들지 않아도 된다
	//pt2 = new Point;

	//Operator *
	pt1.x = 1;
	pt1.y = 2;

	//(*pt2).x = 1.0 and pt2->x = 1.0 are same
	cout << (*pt2).x << " : " << (*pt2).y << endl;
	cout << pt2->x << " : " << pt2->y << endl;

	delete pt2;

}

*/

//이거 보충 : https://stackoverflow.com/questions/2988273/c-pointer-to-objects
/*
	Myclass* myclass;
	Myclass c;
	myclass = &c;
	myclass->DoSomething();

void f(Myclass* p) {
	p->DoSomething();
}

int main() {
	Myclass C;
	f(&c);
}

Myclass myClass;
myClass.DoSomething();

Myclass* p = new Myclass();
p->DoSomething();
delete p;

*/

//class 생성자
/*


class Point {
public:
	double x;
	double y;
};

//생성자
// class 안에선 S(int); 이렇게 선언만 하고 나가고
// class 밖에서
// S::S(int){...}으로 선언하기

// S():n(0) 으로 초기화 해놓을 수도 있음

class Account {
	std::string name;
	int id;
	double balance;
public:
	Account(const string& customer_name, int account_num,
		double amount)
		:name(customer_name), id(account_num), balance(amount) {
		if (amount < 0) {
			cout << "Warning : negatice account balance" << endl;
			balance = 0.0;
		}
	}
	void deposit(double amt) {
		balance += amt;
	}
	bool withdraw(double amt) {
		bool result = false;
		if (balance - amt >= 0) {
			balance -= amt;
			result = true;
		}return result;
	}
	void display() {
		cout << "Name : " << name << endl;
		cout << "Id : " << id << endl;
		cout << "Balance : " << balance << endl;
	}
};

int main() {
	Account act1("Joe", 2131, 1000.000);
	Account act2("Moe", 2132, 1111.222);
	act1.display();
	act2.display();
	cout << endl;
	act1.withdraw(800.00);
	act2.deposit(22.22);
	act1.display();
	act2.display();
}

*/