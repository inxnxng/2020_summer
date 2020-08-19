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