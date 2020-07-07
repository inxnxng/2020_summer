# 자료구조와 알고리즘
###### 20200707

## 자료구조의 분류
* 자료구조
    * 단순
    * 복잡
        * 선형
            * 스택, 큐, 덱 -- 접근이 맨 앞과 맨 뒤로 제한
            * 배열 -- 직접 접근
            * 연결 리스트 -- 순서 접근
        * 비선형
            * 트리, 그래프

## 알고리즘의 조건
* 입력 : 0개 이상의 입력
* 출력 : **1개** 이상의 출력
* 명백성 : 명령어는 애매하지 않고 명확해야 함
* 유한성 : 무한하게 돌면 안 됨
* 유효성 : 실행 가능해야 함

## 알고리즘 기술 방법
유사 코드에서 대입 연산자는 **<-**
**=**은 비교 연산자

## 추상 자료형
구현으로부터 명세의 분리
**정보은닉**

### 추상화
복잡한 자료, 모듈, 시스템 등으로부터 핵심적인 개념이나 기능을 간추려 내는 것.

간략화 된 기술 또는 명세로서 시스템의 정말 핵심적인 구조나 동작에만 집중하는 것.

### 추상 자료형 (Abstract Data Type; ADT)
추상적으로 정의한 자료

what은 존재하나 how는 존재하지 않음

## C++
c++에서는 클래스를 사용하여 추상 자료형을 구현

* 데이터 : 클래스의 속성(멤버 변수)
* 연산 : 클래스의 메소드(멤버 함수)

## 알고리즘의 성능 분석
* 시간 복잡도 : **실행 시간**이 빠르고
* 공간 복잡도 : 처리를 위해 필요한 **기억 공간**이 적은

### 시간 복잡도 함수
* T(n) : n은 연산의 수 또는 문제의 크기
* O(n) : 빅오 표기법; n에 따른 함수의 상한값을 표현. 최고차항의 계수도 버리고 단지 최고차항의 차수만을 사용
    - O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(2^n) < O(n!)
* Ω(n) : 빅오메가 표기법; 하한값 표현.
* Θ(n) : 빅세타 표기법; 동일한 함수로 상한과 하한 표현 가능할 때. EX) n <= 2n+1 <= 3n   f(n)=Θ(n)

가장 정밀한 것은 빅세타. 하지만 통상적으로 빅오 표기법을 많이 씀.

## 자료구조 표기법
### UML Diagram
* - : private
* + : public
* \# : protected
* :(colon) : 반환형 표시
* inheritance : is-a
* aggregation : has-a
* dependency : use

***

## 연습문제

1. 4번 ; 트리 그래프는 비선형 구조
2. 2번 ; 큐 데크 리스트는 선형 그래프는 비선형
3.  데이터 : element로 구성되어 있는 원소들의 집합
    create() : 집합을 새로 생성
    insert(x,y) : 집합 x에 원소 y를 추가
    remove(x,y) : 집합 x에 존재하는 원소 y를 제거
    is_in(x,y) : 집합 x에 원소 y가 존재하면 true로 존재하지 않으면 false로 return
    union(x,y) : 집합 x와 집합 y에 있는 원소를 중복없이 return
    intersection(x,y) : 집합 x와 집합 y에 있는 원소를 비교하여 x와 y에 둘 다 존재하는 원소들을 return
    difference(x,y) : 집합 x에서 집합 y에 존재하는 모든 원소를 제거하여 return
4. 3번 ; n^2만 가져오기
5. 1 < logn < n < nlogn < n^2 < 2^n < n!
6. 2|log2(n)| + 1 , O(log2(n))
7. c == 15이고 n>=0일 때 O(n^2) 성립 ; 10n <= 10n^2, 2 <= 2n^2
8. n\*log2(n) ; sub()의 시간 복잡도가 O(n) 일 때, for문 안에서 |log2(n)|번만큼 돌 수 있으므로 n*log2(n)
9.  (1) b: O(n) w: O(n)
    (2) b: O(1) w: O(n)
    (3) b: O(n) w: O(n)
    (4) b: O(1) w: O(n)

***

## 프로그래밍 프로젝트

1. 1부터 n까지의 합
(1) sum = n(n+1)/2

'''cpp
int sumAlgorithmA(int a) {
    int result 0;
    result = a(a+1)/2;
    return result;
}
'''

'''cpp
int sumAlgorithmB(int a) {
    int result = 0;
    for(int i = 1 ; i <= a; i++){
        result += i;
    }
    return result;
}
'''

'''cpp
int sumAlgorithmC(int a) {
    int result 0;
    for(int i = 0; i <= a ; i++){
        for(int j =0; j < i; j++){
            result++;
        }
    }
    return result;
}
'''

(2) 확인
(3) A : O(1) ; result 변수만 초기화해주면 되므로
    B : O(n) ; 1 + n
    C : O(n^2) ; 1 + n(n+1)/2

(4) 확인
(5) 확인
