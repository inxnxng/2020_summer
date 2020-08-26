# Sorting

20200826

## 정렬이란

오름차순(ascending order) 이나 내림차순(descending order)으로 나열하는 것을 말한다.

정렬 시켜야할 대상을 **record** 라 하고 record는 다시 **field** 라고 하는 보다 작은 단위로 나뉘어진다. 여러 field 중에서 record와 record를 식별해주는 역할을 하는 field를 **key** 라 한다. 정렬이란 record들을 key값의 순서대로 재배열하는 것이다.

정렬 알고리즘을 평가하는 효율성의 기준은 정렬을 위해 필요한 비교 _연산의 횟수와 이동 연산_ 의 횟수이다.

### 정렬 알고리즘의 분류

* 정렬
  * 단순하지만 비효율적인 방법
    * 삽입
    * 선택
    * 버블
  * 복잡하지만 효율적인 방법
    * 퀵
    * 힙 
    * 합병
    * 기수

[내부 정렬과 외부 정렬](https://medium.com/@joongwon/%EC%A0%95%EB%A0%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B8%B0%EC%B4%88-805391cb088e)

## 선택 정렬

### 선택 정렬

**selection sort** 제자리 정렬(in-place sorting)을 통해..  요소의 개수가 n개면 n-1번만 반복하면 된다.

## 삽입 정렬

**insertion sort** 추가적인 배열을 사용하지 않고 입력 배열을 정렬된 부분과 정렬되지 않은 부분으로 나누어서 생각한다.