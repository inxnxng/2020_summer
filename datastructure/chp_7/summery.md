# 순환 : Recursion

20200805</br>
[참고](http://suyeongpark.me/archives/2314)
맥주!!!!!!
html 정리

## 순환의 소개

팩토리얼 함수는 스택으로 움직인다.

### 순환(recursion) <-> 반복(iteration)

원래 정의가 순환적으로 되어 있는 경우 순환 형태로 적용하는 것이 더 쉽다.</br>
분할 정복(divide and conquer) : 주어진 문제를 더 작은 동일한 문제들로 분해하여 해결하는 방법
시간 복잡도 ([링크](https://ko.wikipedia.org/wiki/%EC%8B%9C%EA%B0%84_%EB%B3%B5%EC%9E%A1%EB%8F%84)) : for를 사용하여 n번 반복하므로 시간 복잡도는 $O(n)$이다. 팩토리얼의 순환 알고리즘은 순환 호출 할 때마다 1번의 곱셈이 수행되고 순환 호출을 n번 일어나므로 역시 $O(n)$이다.</br>
다만, 순환 호출의 경우 여분의 기억공간이 더 필요하고 함수를 호출하기 위해 함수의 파라미터들을 스택에 저장하는 것과 같은 사전 작업이 필요하여 수행시간이 더 걸린다

## 거듭제곱 값 계산

```cpp
double Power(double x, int n) {
	if (n == 0) { return 1; }
	else if (n % 2==0) { return Power(x * x, n / 2); }
	else { return x * Power(x * x, (n - 1) / 2); }
}
```
왜? 이렇게 구성했지? $처음에는 n승이었다가 n/2승이 되고, n/4가 된다.$ **문제의 크기가 하나씩 줄어드는 게 아니라 절반씩 줄어든다** </br>

100 -> 50 -> 25 -> 12 -> 6 -> 3 -> 1 이렇게 줄어드는데 반면 순환호출의 경우 $2^k -> 2^(k-1) -> ... -> 2^3 -> 2^2 -> 2^1 -> 2^0$이렇게 총 k번의 호출이 일어난다.</br>
$n = 2^k$ 양변에 log함수를 취하면 $log2(n) = k$가 된다. 따라서 시간 복잡도는 계속 $O(n)$.

## 피보나치수열의 계산

```cpp
int iter_fibo(int n)
{
  int f0 = 0, f1 = 1, fi;
  if (n == 0) return 0;           // 예외처리
  else if (n == 1) return 1;
  else {                          //본 편
    for (int i = 2; i <= n; i++) {
      fi = f0 + f1;
      f0 = f1;
      f1 = fi;
    }
  } return fi;
}
```

## 하노이 탑 계산

```cpp
//막대 from에 쌓여있는 n개의 원판을 막대 tmp를 사용하여 막대 to로 옮긴다.
void HanoiTower(int n, char from, char tmp, char to){
  if(n == 1) //from에서 to로 옮겨준다
  else{
    //from의 맨 밑의 원판을 제외한 나머지 원판을 tmp로 옮긴다 to를 이용해서
    hanoiTower(n - 1, from, to, tmp);
    //tmp의 원판들을 to로 옮긴다 from을 이용해서
		hanoiTower(n - 1, tmp, from, to);
  }
}
```
### 반복적인 형태로 바꾸기 어려운 순환

1. return `n * factorial(n-1);`
2. return `factorial(n-1) * n;`

1은 꼬리 순환으로 순환호출이 순환 함수 맨끝에서 이루어지는 형태로 쉽게 반복적인 형태로 변환 가능하다. 2는 머리순환으로 하노이의 탑 문제처럼 여러군데에서 자기 자신을 호출하는 경우(multi recursion)는 쉽게 반복적인 코드로 바꿀 수 없다.

## 다중 순환

* 선형 순환 : 최대 하나의 순환 호출이 이루어짐 ; 팩토리얼, 거듭제곱
* 이진 순환 : 두개의 순환 호출이 발생하는 경우 ; 피보나치, 하노이탑
* **다중 순환** : 일반화하여 하나의 함수에서 두개 이상의 순환 호출이 이루어지는 경우


