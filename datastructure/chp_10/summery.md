# QUEUE

20200813

## 우선순위 큐

우선순위 개념을 큐에 도입한 자료구조. 큐는 선입선출(FIFO)의 원칙에 **우선순위 큐(priority queue)** 즉 데이터들이 우선순위를 가지고 있는 큐 규칙이 추가 된 것이다.

|  자료구조   |          삭제되는 요소          |
| :---------: | :-----------------------------: |
|    스택     | 가장 최근에 들어온 데이터 (FILO) |
|     큐      |  가장 먼저 들어온 데이터 (FIFO)  |
| 우선순위 큐 |   가장 우선순위가 높은 데이터   |

**힙(heap)** 이 최고임

### 추상자료형

* 데이터 : 우선 순위를 가진 요소들의 모임
* 연산
  * insert(item)
  * remove()
  * find()
  * isEmpty)()
  * isFull()
  * display()

## 우선순위 큐의 구현 방법

### 배열

1. 정렬되지 않은 배열 : 추가시 뒤에 붙이기만 해도 되지만 가장 우선순위가 높은 요소를 삭제할 경우 처음부터 끝까지 모든 요소들을 스캔하면서 가장 우선순위가 높은 요소를 찾아야 한다. 그리고 뒤에 있는 요소들을 앞으로 한칸씩 옮겨야 한다.
2. 정렬된 배열 : 배열 내의 요소들과의 우선 순위를 비교하는 과정이 필요하다. 그래야 정렬된 상태를 유지할 수 있기 때문

### 연결 리스트

1. 정렬되지 않은 연결리스트 : 삽입시 첫번째 노드로 삽입하는 것이 유리하다. 다만 배열과 달리 다른 노드들의 이동은 필요없다
2. 정렬된 연결리스트 : 우선 순위가 높은 요소가 앞에 위치하는 것이 유리하므로 우선순위가 높은 요소가 첫 번째 노드가 되는 것이 중요하다.

### 힙

heap이란 완전 이진 트리의 일종으로 우선 순위 큐를 위해 만들어진 자료구조이다. 반 정렬 상태를 유지한다.

## HEAP

[더미](https://ko.wikipedia.org/wiki/%ED%9E%99_(%EC%9E%90%EB%A3%8C_%EA%B5%AC%EC%A1%B0)) 여러 개의 값들 중에서 가장 큰 값이나 가장 작은 값을 빠르게 찾아내도록 만들어짐. **부모 노드의 키 값이 자식 노드의 키 값보다 큰 이진트리** 를 말한다. 이진 탐색 트리에서는 중복된 값을 허용하지 않지만 힙에서는 중복된 값을 허용한다.

* 최대 힙(max heap) : 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진트리
* 최소 힙(min heap) : 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진트리

```cpp
heapNode remove() {
  if (isEmpty()) return NULL;
  heapNode item = node[1];
  heapNode last = node[size--];
  int parent = 1;
  int child = 2;
  while (child <= size) { //자식이 사이즈를 벗어나지 않는다 즉 힙 트리를 벗어나지 않는 동안
    if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) child++;
    if (last.getKey() >= node[child].getKey()) break;
    node[parent] = node[child];
    parent = child;
    child *= 2;
  }
  node[parent] = last;
  return item;
}
```

`if (last.getKey() >= node[child].getKey()) break;` 이동이 완료되었다면, 즉 그림 10.18처럼 되었다면~

## STL의 우선순위 큐를 사용한 정렬

```cpp
void heapSorter(int a[], int n) {
	priority_queue<int> maxHeap;
	for (int i = 0; i < n; i++) {
		maxHeap.push(a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = maxHeap.top();
		maxHeap.pop();
	}
}

void heapSortInc(int a[], int n) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < n; i++) {
		minHeap.push(a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = minHeap.top();
		minHeap.pop();
	}
}
```

## 힙의 응용 : 허프만 코드

[코드 참조](https://gist.github.com/fpdjsns/a46dede3cbd4a05599c94fcda562a0e0)