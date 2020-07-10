# 배열과 클래스
###### 20200708

## 배열
* 복잡
    * 선형
        * 배열 - <인덱스, 요소> 쌍의 집합 -- 직접 접근
        * 연결 리스트 -- 순차 접근 (5장)

벡터의 크기는 동적으로 변할 수 있음.
**삽입 연산은 연결리스트를 사용하는 것이 좋음**

### 1차원 배열
`int A[5];` 선언하면 **A**는 배열의 시작 주소 또는 기본 주소
문자열 끝에는 NULL을 나타내는 `'\0'` 존재. 이후의 내용은 문자열에 영향을 끼치지 않음

### 2차원 배열
저장할 때 행렬로 정의되지 않고 한줄로 위치함

### 함수 파라미터로서의 배열
배열의 이름은 포인터의 역할
배열의 길이는 반드시 함께 전달해줘야함

### 2차원 이상의 다차원 배열의 매개 변수
a[][]나 int**형으로 선언하거나 동적 할당(5장)

## 클라스
* 함수 오버로딩 : 함수 이름의 중복을 허용하는 점을 이용해 매개변수가 다른 여러 개의 함수를 동일한 이름으로 만들기
* 함수 오버라이딩 : 자식 클래스에서 부모 클래스의 멤버 함수들을 다시 정의

정수는 `%d` 실수형은 `%f` 문자열은 `%s`
`%x`이거는 16진수

### 클래스 객체의 기본 대입 연산자
두 개의 Car 객체가 있을 때 하나의 객체를 다른 객체에 대입할 수 있을까? ==> 할 수 있다.
`b = a;`는 객체 a의 모든 내용을 객체 b에 그대로 복사한다

### Call by...
[참조](https://codingplus.tistory.com/29)
* call by reference (참조에 의한 호출): 인자로 받은 값의 주소를 참조하여 직접 값에 영향을 미치는 것
* call by value (값에 의한 호출) : 인자로 받은 값을 복사하여 처리

***

## 연습문제

1. 1010번지 ; 0 1000번지 10 1010번지
2. 2번 ; int는 4byte double은 8byte
3. 

```cpp
#include <cstdio>
void main(){
    int two[10];
    for(int i = 0 ; i < 10 ; i++){
        two[i] = 2^i;
    }
    for(int i = 0 ; i < 10 ; i++){
        printf("%d\t",two[i]); 
    }
}
```

4. 객체 프로그래밍 quiz..!

```cpp
class Complex {
private :
    double real , imag;
public : 
    Complex();
    ~Complex();
    Complex(double r, double i) : real(r), imag(i);
    Complex operator +(Complex c);
    Complex operator -(Complex c);
    Complex operator *(Complex c);
    void showComp(){
    cout<< real << " + " << imag <<"i" << endl;
    }
};

Complex operator + (Complex c){
    Complex T;
    T.real = real + C.real;
    T.imag = imag + C.imag;
    return T;
}

Complex operator - (Complex c){
    Complex T;
    T.real = real - C.real;
    T.imag = imag - C.imag;
    return T;
}

Complex operator * (Complex c){
    Complex T;
    T.real = real * C.real - imag * C.imag ;
    T.imag = imag * C.real + real * C.imag;
    return T;
}
```