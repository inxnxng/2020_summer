# Tree

20200806

## 트리의 개념

스택, 큐, 리스트는 모두 자료형이 일렬로 나열된 **선형 자료구조(linear data structure)** 였다. 트리는 **계층적인 구조(hierarchical structure)** 로 대표적인 것이 **결정 트리(decision tree)** 이다. 트리는 유한 집합이다

* 포리스트(forest) : 트리들의 집합
    * 노드(node)
        * 루트(root)
        * 서브트리(subtree)
    * 간선, 에지(edge)
        * 부모 노드(parent node)
        * 자식 노드(children node)
        * 형제 관계(sibling)
        * 조상 노드(ancestor node)
        * 자손 노드(descendent node)
        * 단말 노드(terminal node or leaf node) : 자식 노드가 없는 노드
        * 비단말 노드(nonterminal node)
* 차수(degree) : 어떤 노드가 가지고 있는 자식 노드의 개수. 트리가 가지고 있는 노드의 차수 중에서 가장 큰 차수.
* 레벨(level) : 루트의 레벨은 1. 한 층씩 내려갈수록 1씩 증가
* 높이(height) : 트리가 가지고 있는 최대 레벨

일반 트리의 노드 구조

```
                            link field
data field |   link(1)  link(2)  link(3)  ...  link(n)  |
   data    |  자식노드1   자노2    자노3    ...  자노n    |
```

## 이진트리 소개

모든 노드가 2개의 서브트리를 갖는 트리, 이 때 서브트리는 공집합일 수도 있다. 따라서 모든 노드의 차수가 2 이하가 되어 최대 2개까지의 자식 노드를 가질 수 있다.
**다만 왼쪽 서브트리와 오른쪽 서브트리는 반드시 서로 구별되어야 한다.**

### 이진트리의 성질

* n개의 node를 가진 트리는 n-1개의 edge를 가진다. root를 제외한 tree의 모든 node가 하나의 parent node를 가지기 때문. 부모와 자식 간에는 하나의 edge만 존재하므로
* 높이가 h인 이진트리는 $h$개 이상, $2^h-1$개 이하의 노드를 가진다. level $i$에서 노드의 최대 개수는 $2^(i-1)$이다. 따라서 높이가 h인 이진트리의 최대 노드 개수는 $\sum_{i=1}^h 2^(i-1) = 2^h-1$
* n개의 노드를 가지는 이진트리의 높이 $log_2(n+1)$(floor 처리하고) 이상이고 n 이하이다. 한 레벨에서 최소한 하나의 노드는 있어야 하므로 높이는 n을 넘을 수 없다는 것.
* 형태
    * 포화 이진트리 : 트리의 각 레벨에 노드가 꽉 차 있는 이진트리. 번호는 레벨 단위로 왼쪽에서 오른쪽으로 번호를 붙이면 된다.
    * 완전 이진트리 : 높이가 k인 트리에서 레벨 1 부터 k-1까지는 모든 노드가 채워져 있고 마지막 레벨 k에서는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진트리. 마지막 레벨에서는 노드가 꽉 차있지 않아도 되지만 중간에 빈 곳이 있으면 안된다. 힙(heap, 10장)이 대표적인 완전 이진트리
    * 기타 이진트리

### 이진트리의 추상 자료형

* 데이터
    * 노드와 간선의 집합. 노드는 공집합이거나 공집합이 아닌 경우 루트 노드와 왼쪽 서브트리, 오른쪽 서브트리로 구성됨. 이때 모든 서브트리도 이진트리여야함.
* 연산 
    * create()
    * isEmpty()
    * getRoot()
    * getCount()
    * getHeight()
    * insertNode(n)
    * deleteNode(n)
    * display()

## 이진트리의 표현

* 배열 표현법
    * 저장하고자 하는 이진 트리가 완전 이진트리일 경우. 높이가 k이면 먼저 $2^k-1$개의 연속 공간을 할당. 다음 완전 이진트리 번호대로 노드의 정보를 배열에 저장.
* 링크 표현법
    * 연결 리스트를 이용하여 선형 자료구조를 표현한 방식과 유사

## 링크 표현법을 이용한 이진 트리의 구현

## 이진트리의 순회(traversal)

**순회(traversal)** 한다는 것은 트리에 속하는 모든 노드를 한 번씩 방문하여 노드가 가지고 있는 데이터를 목적에 맞게 처리하는 것을 의미한다.

### 순회 방법

루트 방문 : V, 왼쪽 서브트리 방문 : L, 오른쪽 서브트리 방문 : R

* 전위(preorder) 순회(VLR)
* 중위(inorder) 순회(LVR)
* 후위(postorder) 순회(LRV)

#### 전위 순회(VLR) ex) 모든 노드의 레벨 계산

```
preorder(x)

if (x != NULL)
    then print DATA(x)          //루트(x) 처리
         preorder(LEFT(x))      //왼쪽 서브트리 방문
         preorder(RIGHT(x))     //오른쪽 서브트리 방문
```

#### 중위 순회(LVR)

```
inorder(x)

if (x != NULL)
    then inorder(LEFT(x))
         print DATA(x)
         inorder(RIGHT(x))
```

#### 후위 순회(LRV) ex) 현재 디렉토리 용량 계산

```
postorder(x)

if (x != NULL)
    then postorder(LEFT(x))
         postorder(RIGHT(X))
         print DATA(X)
```

### 레벨 순회

```cpp
void levelorder() {
	cout << "levelorder : " << endl;
	if (!isEmpty()) {
		CircularQueue q;
    		q.enqueue(root);
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				cout << "[ " << n->getData() << " ]\t";
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}cout << endl;
	}
}
```

## 이진 트리 연산

```cpp
int getCount() { return isEmpty() ? 0 : getCount(root); }
int getCount(BinaryNode* node) {
	if (node == NULL) return 0;
	return 1 + getCount(node->getLeft()) + getCount(node->getRight());
}
```

이렇게 인자 없는 함수와 인자 있는 함수 두개를 만든 이유
1. 인자 없는 아이는 전체 노드에 대해 적용하도록 그래서 애초에 설정을 root라 해놓은 것이고
2. 인자 있느 아이는 어떠한 노드도 그 노드 밑으로 한해 root가 될 수 있다 왼쪽 3번째 밑 왼쪽을 root로 설정해놓을 수 있는 것처럼 말임. 그래서 순환 함수를 쓰기도 하니까 모든 인자 즉 root로 설정해놓은 인자가 아니더라도 root의 역할을 하며 count를 할 수 있도록 설정해놓은 것이다.

## 이진 트리 응용

이진트리 순회는 **수식 트리(expression tree)** 를 처리하는데 사용될 수 잇다. 수식 트리는 산술식이나 논리식의 연산자와 피연산자들로 만들어진다. 

|      수식      |  a+b  | a-(b*c) | (a<b)or(c<d>) |
| :------------: | :---: | :-----: | :-----------: |
| 전위 순회(VLR) |  +ab  |  -a*bc  |  (or)<ab<cd   |
| 중위 순회(LVR) |  a+b  |  a-b*c  |  a<b(or)c<d>  |
| 후위 순회(LRV) |  ab+  |  abc*-  |  ab<cd<(or)   |

후위 순회를 통해 전체 수식 연산을 해야한다.

```
evaluate(x)

if (x == NULL)
    then return 0;
else x<-evaluate(LEFT(x))           //a
     y<-evaluate(RIGHT(x))          //b
     operation<-DATA(x)             //+
     return (x operation y);
```

## 스레드 이진트리

[스레드 이진트리](https://ko.wikipedia.org/wiki/%EC%8A%A4%EB%A0%88%EB%93%9C_%EC%9D%B4%EC%A7%84_%ED%8A%B8%EB%A6%AC)

가리키는 곳이 없는 모든 오른쪽 널(null pointer)를 중위 후속자 노드로 연결하고 가리키는 곳이 없는 모든 왼쪽 널 포인터를 중위 선행자 노드로 연결한 것을 말한다. 재귀적인 중위 순회를 빠르게 할 수 있는 방법이다. 조금 느리더라도 부모 포인터나 스택을 사용하지 않고도 스레드 이진 트리에서 노드의 부모를 찾을 수 있게 해준다.

이진트리의 노드에는 많은 NULL 링크들이 존재한다. 링크 값이 `NULL`을 갖는 대신에 중위 선행자나 중위 후속자를 저장시켜 놓는 것이 스레드 이진트리의 핵심 아이디어

순회를 빠르게 해줄 수 있다는 장점이 있는 반면 스레드를 설정하기 위해 삽입함수나 삭제함수가 더 많은 일을 해야한다는 것이 단점