#include<iostream>
using namespace std;

/*
8 function

- const에 초기 값이 필요하다.
- #include 처리도 전처리(preprocessing)의 일부
- 클래스 안의 함수 (유용),
	클래스 안의 클래스 (복잡한 클래스 안에서만 유용. 가능하면 클래스를 작고 간단하게 유지하는 것이 좋음),
	함수 안의 클래스 가능 (피하자),
	함수 안의 함수 (허용하지 않는다),
	함수나 다른 블록 안의 블록/중첩된 블록 (불가피하지만 복잡한 중첩은 지양)
- int find(vector<string> vs, string s, int) --> 세번째 인자는 사용하지 않는다.
- for(int s : v) --> v에서 하나씩 꺼내와서 s에 대입
- pass by value : 값에 의한 전달로 값을 복사하여 전달함. 함수 안에 들어간
				복사값은 원래 값에 영향을 끼치지 않음
- pass by reference : 참조에 의한 전달
- reference(&) : 참조. 주소에 해당하는 개념.
			void print( const vector<double>& v) --> 상수 참조에 의한 전달
- 역참조(refer-back) : 다른 곳에서 정의한 객체를 참조한다는 의미에서 참조와 같은 의미
- 참조에 의한 전달 : r을 사용하면 i를 사용하는 것과 같음
		int i = 7;
		int& r = i; --> r은 i를 가리키는 참조
		r = 9 ; --> i도 9가 된다
		i = 10; --> r도 10이 된다
- double val = v[f(x)][g(y)]; <-- v[f(x)][g(y)]에 값을 읽기 또는 값을 써야한다면 참조를 한다.
  double& val = v[f(x)][g(y)]; --> v[f(x)][g(y)]에 읽기와 쓰기가 가능해짐.
- 참조로 전달받은 객체의 값을 고치려면 당연히 객체를 전달해야 한다.
  기술적으로 정수 리터럴 2는 값을 저장한 객체라기 보다 그냥 값(value)이다.
  하지만 g()의 인자 r은 대입문의 왼쪽에 올 수 있는 lvalue여야 한다.
  반면 const참조는 꼭 lvalue일 필요가 없다. 초기화나 값에 의한 전달에서 그렇듯이
  적절한 변환을 수행할 수 있기 때문이다. 세번째 호출 g(1,y,3)에서 컴파일러는
  g()의 인자 cr이 가리킬 int를 할당한다.
  --> 이처럼 컴파일러가 생성한 객체를 임시 객체(temporary object/temporary)라 한다.
- 명시적인 변환을 통해 축소하자 : int x3 = static_cast<int>(x);
- function activation record(함수 활동 기록)
- call stack (호출 스택)
-namespace : 소속을 나타냄
  
  
  
  
  
  
  
  
  
  
  */

void swap(double& d1, double& d2) {
	double temp = d1;
	d1 = d2;
	d2 = temp;
}
//////////////////////////////////////
void g(int a, int& r, const int& cr) {
	++a;
	++r;
	int x = cr;
}

int main() {
	int x = 0; 
	int y = 0;
	int z = 0;
	g(x, y, z); // x==0, y==1, z==0
//	g(1, 2, 3); // 참조 인자 r에는 참조 가능한 변수를 지정해야 함
	g(1, y, 3); // cr은 const이므로 리터럴을 전달할 수 있음
	return 0;
}
//////////////////////////////////////
const Date& default_date() {
	static const Date dd(1970, 1, 1);	//이 코드를 처음 실행할 때만 dd를 초기화
	return dd;
}