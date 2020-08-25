# TensorFlow

**지도학습 - 분류, 회귀** 를 통해 문제해결을 하려고 함. 회귀는 숫자로 된 결과를 예측하고 분류는 범주형, 즉 카테고리 형 문제를 예측하려고 하는 것.
neural network = 인공신경망 = deep learning

***
library : **tensorflow** / pytorch / caffe2 / theano

algorithm : decision tree / randon forest / KNN / SVM / **neural network**

문제(지도학습) : **회귀** / **분류**

machine learning 

AI(artificial intelligence)
***

## 지도학습

1. 과거의 데이터가 준비한다. 원인-독립변수 결과-종속변수
2. 모델의 구조를 만든다. 
3. 데이터로 모델을 학습(FIT)한다.
4. 모델을 이용한다.

```python
import pandas as pd
import tensorflow as tf

X = tf.keras.layers.Input(shape=[1])
Y = tf.keras.layers.Dense(1)(X)
model = tf.keras.models.Model(X,Y)
model.compile(loss="mse")

model.fit(indep,dep,epochs=1000)

print("Predictions: ", model.predict([[15]]))
```

## 손실의 의미

`model.fit(독립,종속,epochs=10)` --> loss : 매 학습마다 조금씩 진행되는데 학습이 끝났을 때 마다 모델이 얼마나 정답에 가깝게 접근했는지 알 수 있는 지표

$LOSS = (예측-결과)^2의 평균$

loss가 0에 가까울 수록 학습이 잘 된 것. 

## 수식과 퍼셉트론

$y = w_1x_1+w_2x_2+...+w_nx_n+b$ 에서 $`w_i`$는 가중치이고 $b$는 편향, bias라 부른다. 

## 원핫인코딩

[원핫인코딩](https://wikidocs.net/22647)

회귀가 아닌 분류에서 쓰인다. 표현하고 싶은 단어의 인덱스에는 1의 값을, 다른 인덱스에는 0을 부여하는 단어의 벡터 표현 방식이다. 

## softmax

[sigmoid](https://icim.nims.re.kr/post/easyMath/64)

softmax : 0과 1사이의 확률을 보여줌

\[Activation]
회귀 모델 : identity(y=x)
분류 모델 : softmax

## BatchNormalization

간단하게 설명하면 중간 중간의 결과를 다음 입력으로 넣기 전에 normalization을 해주는 거에요. (정확히는 standardization)을 해줍니다. 그렇게 각 히든레이어 입력 데이터의 scale을 맞추어 줌으로써 scale이 흔들려서 나타나게 되는 여러 문제들을 해결해 줍니다.

```python
# 2. 모델의 구조를 BatchNormalization layer를 사용하여 만든다.
X = tf.keras.layers.Input(shape=[13])
 
H = tf.keras.layers.Dense(8)(X)
H = tf.keras.layers.BatchNormalization()(H)
H = tf.keras.layers.Activation('swish')(H)
 
H = tf.keras.layers.Dense(8)(H)
H = tf.keras.layers.BatchNormalization()(H)
H = tf.keras.layers.Activation('swish')(H)
 
H = tf.keras.layers.Dense(8)(H)
H = tf.keras.layers.BatchNormalization()(H)
H = tf.keras.layers.Activation('swish')(H)
 
Y = tf.keras.layers.Dense(1)(H)
model = tf.keras.models.Model(X, Y)
model.compile(loss='mse')
 

```