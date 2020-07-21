# 스택

###### 20200715,20200721

## 스택이란

**LIFO**(Last-In First-Out) 후입 선출
스택은 가장 먼저 입력된 데이터가 맨 아래에 쌓이고 입력된 데이터가 가장 위에 쌓이는 구조.
입출력은 맨 위에서만 일어나고 스택의 중간에서는 데이터를 삽입하거나 삭제할 수 없음.
자료의 출력순서가 입력순서의 역순으로 이루어져야 할 경우에 긴요함.
-->되돌리기 기능(undo)
-->함수 호출 & 활성화 레코드(activation record)

* 스택 상산
* 스택 하단
* 요소
* 공백 상태
* 포화 상태
* 삽입 연산 (push)
* 삭제 연산 (pop)

## 스택의 추상 자료형

stack

1. 데이터
LIFO의 접근 방법을 유지하는 elements의 모음

2. 연산

***
push(x)     : 주어진 element x를 stack 맨 위에 추가
pop()       : stack이 비어있지 않다면 맨 위의 element를 삭제하고 **삭제된 element를 반환**
***
가장 기본적인 연산.
***
isEmpty()   : stack이 비어있으면 true 아니면 false 반환
isFull()    : stack이 가득 차 잇으면 true 아니면 false
***
스택이 공백 상태에 있는지 포화 상태에 있는지 검사.
push와 pop 연산의 보조 장치.
***
**peek()**  : stack이 비어있지 않으면 **맨 위의 요소를 삭제하지 않고 반환**
size()  : stack내의 모든 elements 개수 반환
display()   : stack 내의 모든 elements 출력
***
peek은 pop과 반대로 요소를 삭제하지 않고 반환한다.

### 활성화 레코드

```cpp
int main(){
    a();
    return 0;
}
int a(){
    b();
    c();
    return 0;
}
int b(){
    return 0;
}
int c() {
    return 0;
}
```

1. main()
2. main() a()
3. main() a() b()
4. main() a()       //b는 반환됨
5. main() a() c()
6. main() a()       //c는 반환됨
7. main()           //a는 반환됨

## 스택의 구현 방법

스택을 배열로 구현하면 넣을 수 있는 항목의 수가 제한. 스택의 크기가 고정        **일반 공책**
포인터를 이용한 연결리스트 --> isFull() 필요 없음 (5장)                       **바인더 공책**

### 배열을 통한 스택 구현

배열은 순차적인 메모리 공간에 할당된 **순차적 표현(sequential representataion)**

top이라는 변수로 가장 최근에 입력되었던 자료의 위치 표현. -1로 초기화
MAX_STACK_SIZE로 스택에 저장할 수 있는 최대 요소 개수 표현

### 연결 리스트를 이용한 스택

linked stack : **포인터** 연산을 통해 구현 (5장)

### EXTRA

ungetc() : [참고]( https://modoocode.com/49)

***

## 연습문제

  
