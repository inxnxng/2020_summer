5# 이진 탐색 트리

20200810

## 이진 탐색 트리

* 탐색 : 레코드의 집합에서 특정한 레코드를 찾아내는 작업. 어떤 키가 입력되면 이 키를 가진 레코드를 찾는 것
  * 레코드 : 하나 이상의 필드로 구성된다
    * 필드 : 범위같은 느낌
    * 테이블 : 레코드들의 집합
  * 키 : 레코드들은 키로 불리는 하나의 필드에 의해 구별된다
    * 주요키 : 이렇게 구별해주는 키를 주요키라 한다

### 이진 탐색 트리(Binary Search Tree)

[이진 탐색 트리](https://ratsgo.github.io/data%20structure&algorithm/2017/10/22/bst/)

* 모든 노드는 유일한 키를 가진다
* 왼쪽 서브트리의 키들은 루트의 키보다 작다
* 오른쪽 서브트리의 키들은 루트의 키보다 크다
* 왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다

중위 순회를 한다(inorder). 삽입 연산은 leaf node에서 이뤄진다.

* 데이터 : 이진 탐색 트리의 특성을 만족하는 이진트리 : 어떤 노드 x의 왼쪽 서브트리의 키들은 x의 키보다 작고, 오른쪽 서브트리의 키들은 x의 키보다 크다. 이 때 왼쪽과 오른쪽 서브트리는 모두 이진 탐색 트리이다.
* 연산
  * insert(node)
  * remove(node)
  * search(key)

## 이진 탐색 트리의 연산

* 비교한 결과가 같으면 탐색이 성공적으로 끝난다
* 비교한 결과 탐색키가 루트 노드의 키 값보다 작으면 탐색은 이 루트 노드의 왼쪽 자식을 기준으로 다시 시작한다
* 비교한 결과 탐색키가 루트 노드의 키 값보다 크면 탐색은 이 루트 노드의 오른쪽 자식을 기준으로 다시 시작한다

### 삭제연산

삭제하려는 노드가
1. 단말 노드일 경우
2. 왼쪽이나 오른쪽 서브트리 중 하나만 가지고 있는 경우
3. 두개의 서브트리 모두 가지고 있는 경우
    * **삭제되는 노드와 가장 값이 비슷한 노드**를 가져와야 다른 노드들을 변경시키지 않고 이진 탐색 트리의 조건을 만족한다.
    * 삭제를 위해 알아야할 노드 : 삭제할 노드, 삭제할 노드의 부모 노드, 후계 노드, 후계 노드의 부모 노드
 
## 이진 탐색 트리 프로그램

```cpp
void remove(BinaryNode* parent, BinaryNode* node) {
  //case 1 : 단말 노드일 경우
  if (node->isLeaf()) {
    if (parent == NULL) root = NULL;
    else {
      if (parent->getLeft() == node) parent->setLeft(NULL);
      else parent->setRight(NULL);
    }
  }
  //case 2 : 한쪽에 자식 노드를 갖는 경우
  else if (node->getLeft() == NULL || node->getRight() == NULL) {
    BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
    // 왼쪽에 자식이 있다면 왼쪽 포인터를 오른쪽에 있다면 오른쪽 포인터를
    if (node == root) root = child;
    else {
      if (parent->getLeft() == node)parent->setLeft(child);
      //삭제하려는 노드가 부모 노드의 왼쪽 자식이었다면 부모 노드 왼쪽에 child 자식 노드 놓기
      else parent->setRight(child);
    }
  }
  //case 3 : 삭제하려는 노드가 두개의 자식이 모두 있는 경우
  else {
    BinaryNode* succp = node;
    BinaryNode* succ = node->getRight();
    while (succ->getLeft() != NULL) {
      succp = succ;
      succ->getLeft();
    }
    //왼쪽 자식이었다면 
    if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
    else succp->setRight(succ->getRight());
    node->setData(succ->getData());
    node = succ;
  }
  delete node;
}

void remove(int key) {
  if (isEmpty()) return;
  //없앨 노드의 부모와 자신
  BinaryNode* parent = NULL;
  BinaryNode* node = root;
  while (node != NULL && node->getData() != key) {
    parent = node;
    node = (key < node->getData()) ? node->getLeft() : node->getRight();
  }
  if (node == NULL) {
    cout << "키가 존재하지 않는다" << endl;
    return;
  }
  else remove(parent, node);
}
```

## 이진 탐색 트리의 성능 분석

이진 탐색 트리에서의 탐색, 삽입, 삭제 연산의 시간 복잡도는 트리의 높이를 h라 했을 때 $O(h)$ 가 된다. 따라서 n개의 노드를 가지는 이진 탐색 트리의 경우, 일반적인 이진트리의 높이는 $log_2(n)$ 이므로 이진 탐색 트리 연산의 평균적인 경우 시간 복잡도는 $O(log_2(n))$