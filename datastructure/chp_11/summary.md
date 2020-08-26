# GRAPH

20200818

## 그래프란?

그래프는 요소들이 서로 복잡하게 연결되어 있는 관계를 표현한 자료구조

### 오일러 문제

* graph
    * vertex
    * edge
    * node
    * link

### 그래프의 종류

* 무방향 그래프 (undirected graph) : 간선에 방향이 표시되지 않은 그래프를 무방향 그래프라 한다. (A, B) == (B, A)
* 방향 그래프 (directed graph) : 간선(edge)에 방향성이 존재하는 그래프 <A, B> =/= <B, A>
* 가중치 그래프 (weighted graph) : 간선에 비용이나 가중치가 할당된 그래프를 가중치 그래프 또는 **네트워크** 라 한다
* 부분 그래프 (subgraph) : 원래 그래프에서 몇 개를 빼내 그래프를 새로 그린 것을 부분 그래프라고 한다
  
### 그래프의 용어

* 인접 정점 (adjacent vertex)
* 정점의 차수 (degree)
  * 진입 차수 (in-degree)
  * 진출 차수 (out-degree)
* 경로 (path)
  * 경로의 길이
* 단순 경로 (simple path)와 사이클 (cycle) : 반복되는 간선이 없는 경로를 단순 경로라 하고 단순 경로의 시작 정점과 종료 정점이 같다면 이러한 경로를 사이클이라 한다.
* 연결 그래프 (connected graph) : 모든 정점들 사이에 경로가 존재하면 G를 연결 그래프라 부른다. 떨어진 정점이 아무것도 없는 그래프. 만약 그렇지 않다면 비연결 그래프라 한다.
* 트리 (tree)
* 완전 그래프 (complete graph) : 모든 정점 간에 간선이 존재하는 그래프를 완전 그래프라 한다. 간선의 수는 $n*(n-1)/2$ 로 정해진다.

### 그래프의 추상 자료형

* data : 정점(vertex)의 집합과 간선(edge)의 집합
* 연산
  * create()
  * isEmpty()
  * insertVertex(v)
  * insertEdge(u,v)
  * deleteVertex(v)
  * deleteEdge(u,v)
  * adjacent(v)

## 그래프의 표현

배열을 사용하는 **인접 행렬(adjacency matrix)** 과 연결 리스트를 사용하는 **인접 리스트(adjacency list)** 두 가지가 있다.

### 인접 행렬

정점의 개수가 n개라면 n x n의 2차원 배열 형태를 사용한다.
정점 i에 대한 차수는 : 
$$degree(i)=\sum_{k=0}^{n-1} M[i][k]$$ 

### 인접 행렬을 이용한 그래프 클래스 구현

* 데이터 필드
  * size : 그래프의 크기
  * adj[][] : 이차원 배열. 인접 행렬을 표시
  * verticles[] : 정점의 정보
* 멤버 함수(method)
  * isEmpty(), isFull()
  * insertVertex()
  * deleteVertex()
  * insertEdge()
  * deleteEdge()
  * adjacent() 

### 인접 행렬을 이용한 너비 우선 탐색

breadth first search. BFS. 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이다. 너비 우선 탐색을 위해서는 가까운 거리에 있는 정점들을 차례로 저장하고, 들어간 순서대로 꺼낼 수 있는 queue가 사용된다.

```cpp
void BFS(int v) {
  visited[v] = true;
  cout << getVertex(v) << "\t";
  CircularQueue que;

  que.enqueue(v);                             //시작 정점을 큐에 저장
  while(!que.isEmpty()){
    int v = que.dequeue();                    //큐에서 정점 하나 꺼내서
    for(int w=0; w<size; w++){
      if(isLinked(v,w)&&visited[w]==false){   //인접 정점 탐색을 통해 그 정점이 현재 정점과 연결되어 있고 방문되지 않았다면
        visited[w] =true;
        cout << getVertex(w)<< '\t';
        que.enqueue(w);                       //방문한 정점을 큐에 저장한다
      }
    }
  }
}
```

### 인접 리스트

정점의 수가 n개이고 간선의 수가 e개인 무방향 그래프에서는 n개의 연결 리스트가 필요하고, n개의 헤더 포인터와 2e개의 노드가 필요하다. 따라서 인접 행렬 표현은 정점의 개수에 비해 간선의 개수가 매우 적은 희소 그래프의 표현에 적합하다.

## 그래프의 탐색

하나의 정점에서 시작하여 모든 정점들을 한 번씩 방문하는 작업. **깊이 우선 탐색**과 **너비 우선 탐색**이 있다

### 깊이 우선 탐색

depth first search. DFS. 스택을 이용한 미로 탐색과 유사하다. 

```cpp
void DFS(int v) {
  visited[v] = true;
  cout << getVertex(v) << "\t";
  for (Node* p = adj[v]; p != NULL; p = p->getLink()) {
    if (visited[p->getId()] == false) DFS(p->getId());
  }
}
```

### 인접 리스트를 이용한 너비 우선 탐색

```cpp
void BFS(int v){
  visited[v] = true;
  cout << getVertex(v);
  CircularQueue que;
  que.enqueue(v);
  while(!que.isEmpty()){
    int v = que.dequeue();
    for(Node* w= adj[v] ; w!=NULL; w= w->getLink()){
      int id = w->getId();
      if(!visited[id]) {
        visited[id] =true;
        cout<<getVertex(id);
        que.enqueue(id);    //방문한 정점을 큐에 저장
      }
    }
  }
}
```

## 연결 성분

연결 성분 (connected component) 이란 최대로 연결된 부분 그래프를 말한다.

## 신장 트리

[신장 트리](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html)

이산 구조때 했던 kruskal algorithm, prim algorithm이 이와 관련된 것

## 위상 정렬

[위상 정렬](https://gmlwjd9405.github.io/2018/08/27/algorithm-topological-sort.html)

위상 정렬( **Topo** logical **Sort** ) : 어떤 일을 하는 순서를 찾는 알고리즘. 즉 방향 그래프에 존재하는 각 정점들의 선행 순서를 위배하지 않으면서 모든 정점을 나열하는 것

```cpp

#include <iostream>
#include "AdjListGraph.h"
#include " ArrayStack.h"
using namespace std;

#define MAX 256

class TopoSortGraph : public AdjListGraph {
  int inDegl[MAX];    //정점의 진입 차수
  /*
  1차원 배열.
  이 배열에는 각 정점의 진입 차수가 기록된다.
  즉, inDegl[i]는 정점 i로 들어오는 간선의 개수
  정점 i는 inDegl[i]의 값이 0일 경우 후보 정점이 된다.
  진입 차수가 0인 정점들을 저장하기 위해 스택을 이용한 것
  */
public:
  void insertDirEdge(int u, int v) {
    adj[u] = new Node (v, adj[u]);
  }
  void TopoSort() {
    for(int i = 0 ; i<size ; i++) inDeg[i] = 0;
    for(int i = 0 ; i<size ; i++) {
      Node *node = adj[i];
      while(node!=NULL) {
        inDeg[node->getId()]++;
        node = node->getLink();
      }
    }
    ArrayStack s;
    for(int i = 0; i<size ; i++)
      if(inDeg[i] == 0)
        s.push(i);
    while(s.isEmpty() == false) {
      int w= s.pop();
      Node *node = adj[w];
      while(node!= NULL) {
        int u = node -> getId();
        inDeg[u]--;
        if(inDeg[u] ==0) s.push(u);
        node = node->getLink();
      }
    }cout <<endl;
  }
};
```