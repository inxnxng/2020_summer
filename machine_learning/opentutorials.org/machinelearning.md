# 독립변수와 종속변수

독립변수 : 원인 - 온도
종속변수 : 결과 - 판매량

상관관계

# 기계학습

[지도 학습? 비지도 학습?](https://marobiana.tistory.com/155)

* 기계학습 machine learning
  * 강화학습 reinforcement learning
  * 지도학습 supervised learning
    * 분류 classification
    * 회귀 regression
  * 비지도학습 unsupervised learning
    * 군집화 clustering
    * 변환 transform
    * 연관 association

## 지도학습

가지고 있는 데이터에 독립변수와 종속변수가 있고
* 종속 변수가 숫자일 때 **회귀** 를 이용하면 된다
* 종속 변수가 이름일 때 **분류** 를 이용하면 된다

# 사분위수 Quartile

[사분위수](https://support.minitab.com/ko-kr/minitab/19/help-and-how-to/graphs/boxplot/interpret-the-results/quartiles/)

## 비지도학습

### 군집화 clustering

비슷한 것들을 찾아 그룹을 만드는 것
구분해서 그룹을 만드는 것은 군집화. 이미 그렇게 그룹이 지어진 것에 나눠 넣는게 분류

> 비슷한 행을 그룹핑하는 것
> > 군집화

### 연관 association rule learning

장바구니 학습. 추천리스트.
> 비슷한 열의 관계를 찾아주는 것
> > 연관

### 변환

[변환](https://subinium.github.io/MLwithPython-3-1/)</br>
데이터를 새롭게 표현하여 사람이나 다른 머신러닝 알고리즘이 원래 데이터보다 쉽게 해석할 수 있도록 만드는 알고리즘. 특성이 많은 고차원 데이터를 특성의 수를 줄이면서 꼭 필요한 특징을 포함한 데이터로 표현하는 방법인 차원 축소(dimensionality reduction) 시각화를 위해 데이터셋을 2차원으로 변경하는 경우임

### 정리

비지도 : 탐험적. 데이터들의 성격을 파악하는 것이 중요. 종속변수와 독립변수의 구분이 중요하지 않다. 데이터들을 파악하는 것이 포인트.
지도 : 역사적. 과거의 원인과 결과를 바탕으로 어떠한 결과가 나올 것인지 추측하는 것. 독립변수와 종속변수의 구분이 중요

## 강화학습

reinforcement learning. 경험을 통해. 상벌 시스템. 