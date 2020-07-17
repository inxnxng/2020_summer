# CHAR

## 1
[참조](https://igotit.tistory.com/entry/char-const-char-char-const)

* char* v;
    * v는 문자, 문자열이 저장된 메모리의 첫 주소를 저장할 수 있는 포인터 변수
    * char* v = "문자열 상수 1"; 초기화 했어도 코드 중에는 언제든 변경 가능
* const char* v;
    * v는 다시 문자열이 저장된 메모리의 첫주소를 저장할 수 있는 포인터 변수. **v 주소 메모리의 내용은 변경 불가** 즉 v는 **상수 문자열의 포인터변수**
    * const의 대상이 v자체가 아니므로 v가 가리키는 주소는 변경 가능함
    * const char* v = "문자열 상수 1";로 초기화함. 이 때, v = "문자열 상수 2"; 는 가능 // *v = "문자열 상수 2"는 불가능. 이건 v 주소 메모리의 값을 변경하려 한 것이므로 
* char* const v;
    * v는 문자열이 저장된 메모리의 첫주소를 저장할 수 있는 포인터 변수
    * 초기화할 때 한번 지정된 문자열 메모리 주소 변경 못함.
    * char* const v = "문자열 상수1";로 초기화 했을 때, v = "문자열 상수2"는 불가능하단 소리임

## 2
[참조1](https://m.blog.naver.com/jsky10503/221131378623)
[참조2](https://m.blog.naver.com/jsky10503/221133942782)
[참조3](https://m.blog.naver.com/jsky10503/221134770777)

char형 포인터(문자열 표현 방법)

`char str[20] = "Good Morning!";` 이는 배열을 기반으로 하는 변수 형태의 문자열 선언. 변수라고 하는 이유는 문자열의 일부를 변경할 수 있기 때문. 문자열 전체를 저장하는 배열.
\[G\]\[o\]...\[!\]\[\\0\]

`char* str2 = "This is string";`으로도 선언 가능. 이는 포인터를 기반으로 문자열을 선언한 것. 이렇게 선언하면 메모리 공간에 문자열 This is string이 저장되고 문자열의 첫번째 문자 T의 주소값이 반환된다. 그리고 이 반환 값은 포인터 변수 str2에 저장된다.
**char형 포인터로 선언하면 첫번째 문자의 주소값이 저장된다**
str2--------------->\[**T**his is string\\0\]

| |char형 배열|char형 포인터|
|:---:|:---:|:---:|
|가리키는 위치 변경|불가능|가능|
|문자열 내용 변경| 가능| 불가능|

_printf 함수는 문자열을 전달 받지 않고 문자열의 주소 값을 전달 받는 함수임_

`char* strArr[3] = {"apple","banana","cinamon"};`으로 선언 시
`strArr[1]`은 "banana"임.

## 3 
[참조](https://mk28.tistory.com/127)

1. 생성
char : char arr\[size\];
string : string s;

2. 표준 입력 받아오기
char : 공백, 개행 무시. for문 돌려서 일일이 받아와도 되지만 배열 전체로 받아와도 된다
string : 공백, 개행 무시 `#include <string>` 필요

3. 문자열 개수
char : strlen(const char*);    `int size = strlen(arr);`
string : length();      `int size = s.length();`

4. 표준 입력 읽어오기
char : 
```cpp
cin.getline(_Elem *_Str, streamsize _count, _Elem _Delim = '\n')
            //변수 주소, 최대 입력 가능 문자수, 종결 문자(default는 '\n')
cin.getline(arr,SIZE);
```

string : 
```cpp
getline(cin,s);
       //위의 cin.getline과 비슷한 맥락, 그러나 최대 입력 가능 문자수를 입력하지 않아도 된다.
```
