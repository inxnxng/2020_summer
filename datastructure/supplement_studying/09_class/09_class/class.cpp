#include<iostream>
#include<vector>
using namespace std;


/*
09 Class

-����� ���� Ÿ�� (User-Defined Type)
-�����ڸ� �Ʒ����� ����Ϸ���
	classname::classname�� classname classname::classname�� �ƴ϶�


*/

class X {
private:
	int m;
	int mf(int);
public:
	int f(int i) { m = i; return mf(i); }
};

struct Date_S {
	int y, m, d;
};

enum class Month {
	Jan = 1, Feb, Mar, Apr, May, Jun,
	Jul, Aug, Sep, Oct, Nov, Dec
};

class Year {
	static const int min = 1900;
	static const int max = 2200;
public:
	class Invalid {};
	Year(int x) : y(x) { if( (x < min) || (x > max)) throw Invalid{}; }
private:
	int y;
};

class Date {
	Year y;
	int d;
	Month m;
	bool is_Valid();
public:
	Date(Year y, Month m, int d);
	class Invalid {};
	void add_day(int n);
	Month month() { return m; }
	int day() { return d; }
	Year year() { return y; }
};

//������� ����� ����
void init_day(Date& dd, int y, int m, int d) {
	if (m == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
		if (d > 31) {
			dd.y = 1970;
			dd.m = 1;
			dd.d = 1;
		}
	}
	else if (m == 2) {
		if (((y % 4 == 0) && (y % 100 != 0)) || y % 400 == 0) {
			if (d > 29) {
				dd.y = 1970;
				dd.m = 1;
				dd.d = 1;
			}
		}
		else {
			if (d > 28) {
				dd.y = 1970;
				dd.m = 1;
				dd.d = 1;
			}
		}	
	}
	else {
		if (d > 30) {
			dd.y = 1970;
			dd.m = 1;
			dd.d = 1;
		}
	}
}

//�����ڴ� Date::Date 
Date::Date(Year yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd } {
	if (!is_Valid()) throw Invalid{};
}

bool Date::is_Valid() {
	if (m < 1 || m>12) return false;
}

void Date::add_day(int n) {

}

void f1(Date& d1, Date& d2) {
	cout << d1.month() << " " << d2.month() << endl;
}

void f2(int x, int y) {
	try {
		Date dxy{ 2020,x,y };
		//cout << dxy << '\n' << endl;
	}
	//�� try catch�� Date::Invalid�� �־�����?
	/*
	
	[���� ó���� ���� ��Ŀ���� try throw catch]

	try - try ���ο� ���ܰ� �ִ��� Ž��
	throw - try���� ���ܸ� Ž���ϸ� throw�� ���ڷ� �� ������ catch�� ����
	catch - throw���� ���� ������ ���ڷ� �޾Ƽ� catch ���ο� ���α׷��Ӱ� ������
			���� ó���� �ǽ��Ѵ�

	--> ���ܰ� �߻����� �� throw�� ���� ���ڷ� ������, catch �κ��� ����Ǹ�
		try���ο��� throw ���� �κ��� skip

	[���� ����]

	try{
	...
	throw PARAM;
	...
	}catch(int expn){	<--PARAM�� expn���� ���� ��
	...
	}
	
	�Ϲ� �Լ� ������ �� ȣ��� �Լ� ���ο��� ����ó���� �Ͽ�
	throw�� ���� catch�� ���� �� ����.

	void f(int a, int b){
		...
		if(a==b) throw b;
		...
	}
	*/
	catch (Date::Invalid) {
		cout << ("invalid date") << endl;
	}
}

//������ �����ε�

Month operator++(Month& m) {
	m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1);
}

vector<string> month_tbl;

ostream& operator <<(ostream& os, Month m) {
	return os << month_tbl[int(m)];
}


int main() {
	Date today{ 1999,4,29 };
	today.month =2;
	cout << today.month() << endl;
	return 0;
}