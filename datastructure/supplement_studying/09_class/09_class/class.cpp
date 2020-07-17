#include<iostream>
#include<vector>
using namespace std;


/*
09 Class

-사용자 정의 타입 (User-Defined Type)
-생성자를 아래에서 명시하려면
	classname::classname임 classname classname::classname이 아니라


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

//윤년까지 고려한 계산기
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

//생성자는 Date::Date 
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
	//왜 try catch에 Date::Invalid를 넣었을까?
	/*
	
	[예외 처리를 위한 메커니즘 try throw catch]

	try - try 내부에 예외가 있는지 탐색
	throw - try에서 예외를 탐색하면 throw의 인자로 준 변수를 catch로 던짐
	catch - throw에서 던진 변수를 인자로 받아서 catch 내부에 프로그래머가 정의한
			예외 처리를 실시한다

	--> 예외가 발생했을 때 throw를 통해 인자로 보내고, catch 부분이 실행되며
		try내부에서 throw 이후 부분은 skip

	[실행 예시]

	try{
	...
	throw PARAM;
	...
	}catch(int expn){	<--PARAM을 expn으로 받은 것
	...
	}
	
	일반 함수 내에서 즉 호출된 함수 내부에서 예외처리를 하여
	throw를 통해 catch에 보낼 수 있음.

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

//연산자 오버로딩

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