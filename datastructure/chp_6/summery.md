# 리스트

20200802

## 리스트 추상 자료형

리스트 또는 선형 리스트(linear list). 리스트의 항목들은 순서 또는 위치를 가진다.
`L = {item_0, item_1, item_2, ..., item_n-1}`
집합은 항목 사이에 순서 개념이 없지만 리스트에 들어있는 항목들 사이에는 순서가 있다.

리스트도 선형자료 구조임. like 스택, 큐, 덱. 하지만 이들은 삽입과 삭제 연산이 맨 앞이나 맨 뒤로 제한되어 있는 반면 **리스트는 임의의 위치에 있는 항목에 대한 연산을 허용**한다.

* 리스트 : 특정한 자료 구조. 스택이나 큐
* 연결 리스트 : 어떤 자료 구조를 구현하는 프로그래밍 기법. 배열

### 추상 자료형

* 리스트의 어떤 위치에 새로운 요솔르 삽입/삭제/반환
* 리스트가 비어 있는지/가득 차 있는지 검사
* 리스트에 어떤 요소가 있는지
* 리스트의 어떤 위치에 있는 요소를 새로운 요소로 대치
* 리스트 안의 요소 개수 세기
* 리스트 안의 모든 요소를 출력
***
* 데이터 : 임의의 접근 방법을 제공하는 같은 타임 요소들의 순서 있는 모임
* 연산 :
    * insert(pos, item) : 리스트의 pos 위치에 새로운 요소 item을 삽입
    * delete(pos) : 리스트의 pos 위치에 있는 요소를 삭제
    * getEntry(pos) : pos 위치에 있는 요소를 return
    * isEmpty()
    * isFull()
    * find(item)
    * replace(pos, item)
    * size()
    * display()

리스트는 대부분 **포인터를 사용한 연결 리스트 방식**을 이용한다(단일, 이중, 원형)

## 배열로 구현한 리스트

1. 데이터 멤버
    1. data\[MAX_LIST_SIZE]
    2. length : 리스트에 저장된 요소의 개수

```
data[MAX_DATA_SIZE]
    |-------------------------------length-----|
    |   A   |   B   |   C   |   D   |    | | | |
    |data[0]-data[1]-data[2]-data[3]-----------|
```

2. 삽입 연산
3. 삭제 연산

## 연결 리스트로 구현된 리스트

배열로 리스트를 구현하는 것과 달리 연결 리스트에서는 시작 노드의 주소만을 관리한다.

* 헤드 포인터 head를 멤버로 가지는 경우
    * 리스트가 공백이라면 헤드 포인터의 경우 head변수가 `NULL`이 된다
* 헤드 노드 org를 멤버로 가지는 경우. 즉 헤드 노드 객체를 선언하여 사용하는 빈 시작 객체(실제 헤드 포인터는 org.link가 된다)
    * 헤드 노드 org의 링크 필드 즉 org.link가 `NULL`이 된다


> 노드 클래스에서 가능한 많은 기능을 구현하고, 리스트 클래스에서는 이들을 사용함으로써 리스트 클래스의 복잡도를 줄이는 방법 
>> 객체 지향 프로그래밍 관점으로 바라보았을 때 데이터 위주의 관점으로 바라보면서 상향식(bottom up)으로 해결하기

### 삽입 연산

```
void insert(before,node){
    if(isEmpty())
        then head <- node
    else node.link <- before.link
         before.link <- node
}
```
* `node.link <- before.link`
    * 전 노드가 향하는 포인터 방향은 현재 노드의 방향 포인터가 복사하여 가져와야 하고
* `before.link <- node`
    * 현재 노드의 위치를 전 노드의 포인터 방향이 node를 가리켜야 한다???

```cpp
//포인터 복사이고(제발 link는 **다음 노드**임)
node->link = link;
//this가 가리키는 링크에 node를 저장한다 임....
this->link = node;
```

### 삭제 연산

```
bool remove(before){
    if(isEmpty()) = false;
        then removed <- before.link
             before.link <- removed.link
             destroy(removed)
}
```
* `removed <- before.link`
    * 전 노드는 현재 삭제할 노드를 가리키고 있는데 그 노드 우선 복사해놓고
* `before.link <- removed.link`
    * 삭제할 노드가 가리키는 주소를 전 노드에게 주어 전 노드가 삭제할 노드 다음 노드를 향하도록 해놓는다
* `destroy(removed)`
    * 그리고 삭제할 노드를 destroy하기
  
```cpp
//link는 항상 다음 노드임
Node* removed = link;
//삭제될 노드가 향했던 포인트를 전 노드의 포인터가 향하도록
link = removed->link;
```

### 연산자 detail

최초의 p는 헤드 포인터 `p = getHead();` 헤드 노드는 `org`. 이후로 link를 따라 진행 `p = p->getLink();`
리스트에 삽입할 노드 객체는 동적으로 할당하였는데, `new Node(10)`을 통해 Node 객체 하나를 동적으로 생성하고 초기화한 후 그 객체의 주소를 반환한다

## 다양한 형태의 연결 리스트

### circular linked list

원형 연결 리스트. 리스트의 마지막 노드의 링크가 첫 번째 노드를 가리키는 연결리스트. 마지막 노드의 링크 필드는 `NULL`이 아니라 `첫번째 노드 주소`가 된다.
다만 **헤드 포인터는 리스트의 마지막 노드를 가리키게 된다**

### double linked list

이중 연결 리스트. 양방향으로 검색이 가능해진다.
```
        데이터 필드
prev   |   data   |   next
선행노드           후속노드
```
임의의 노드의 포인터를 p라 한다면 `p==p->next->prev == p->prev->next`이다. 무슨 난리람ㅠ

#### 추가 연산

1. 새로운 노드 N의 선행 노드를 현재 노드로 설정
2. N의 후속 노드를 현재 노드의 후속 노드로 설정
3. 현재 노드의 후속 노드의 선행 노드를 N으로 설정
4. 현재 노드의 후속 노드를 N으로 설정

```cpp
if (i % 2)deq.addFront(new Node(i));
else deq.addRear(new Node(i));
```
결국 중요한 것 ==> **새로운 요소를 추가**할 때 `i`로 놓으면 안되고 `new Node(i)`을 놓아야한다.