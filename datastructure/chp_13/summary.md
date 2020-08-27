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

```cpp
void insertionSort(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i-1; j>=0 && A[j]>key ;j--) {			//A[j]>key는 배열이 이미 다 정렬된 상황이라면 for문을 나오도록 주문한 것
			A[j + 1] = A[j];
		}A[j + 1] = key;
	}
}
```

```cpp
inline int ascend(int x, int y) { return y - x; }
inline int descend(int x, int y) { return x - y; }

void insertionSortFn(int A[], int n, int(*f)(int, int)) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0 && f(A[j], key) < 0; j--) {
			A[j + 1] = A[j];
		}A[j+1] = key;
	}
}
```

## 버블 정렬

**bubble sort** 인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환하는 방법

```cpp
void bubblesort(int a[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int k = 0; k < i; k++) {
			if (a[k] > a[k + 1]) swap(a[k], a[k + 1]);
		}
	}
}
```

## 셸 정렬

**shell sort** 삽입 정렬이 어느 정도 정렬된 배열에 대해서는 대단히 빠름. 삽입 정렬보다 빠름.
gap 간격만큼 돌고 돌아야 하니까 첫번째 for문에서 gap만큼 차이나게 한 것이고
두번째 for문에서는 아예 key < a\[j] 조건을 줘서 if문을 넣지 않은 것
shellsort에서 간격이 짝수이면 1을 더하는 것이 좋은 것으로 분석되었음 그래서 짝수일 경우 1을 추가했음

```cpp
static void sortGapInsertion(int a[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = a[i];
		for (j = i - gap; j >= first && key < a[j]; j = j - gap) {
			a[j + gap] = a[j];
		}a[j + gap] = key;
	}
}

void shellsort(int a[], int n) {
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		printArray(a, n, "shell..");
		if ((gap % 2) == 0) gap++;
		for (int i = 0; i < gap; i++) {
			sortGapInsertion(a, i, n - 1, gap);
		}
	}
}
```

## 합병 정렬

**merge sort** 하나의 리스트를 두개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 두 리스트를 합하여 전체가 정렬된 리스트를 만드는 방법.

1. 분할 divide
2. 정복 conquer : 순환 호출을 이용
3. 결합 combine

```cpp
#define MAX 1024

static void merge(int a[], int left, int mid, int right) {
	int i, j, k = left, l;
	static int sorted[MAX];
	for (i = left, j = mid + 1; i <= mid && j <= right;)
    sorted[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
	if (i > mid)
		for (l = j; l <= right; l++, k++)
			sorted[k] = a[l];
	else
		for (l = i; l <= mid; l++, k++)
			sorted[k] = a[l];
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}
```

[해설](https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html)

* `int i, j, k = left, l;` 
  정수 i j k l을 선언하는데 특히 k는 left와 같은 값으로 선언하겠다. **k는 또한 정렬될 리스트에 대한 인덱스다** left의 인덱스는 0일테니...! i는 정렬**된** 왼쪽 리스트에 대한 인덱스(i=left), j는 정렬**된** 오른쪽 리스트에 대한 인덱스(j = mid+1), k는 정렬**될** 리스트에 대한 인덱스 

* `static int sorted[MAX];`
  정렬되어 저장될 배열 생성

* `	for (i = left, j = mid + 1; i <= mid && j <= right;)`
  i와 j는 정렬된 리스트의 시작점으로 각자 리스트 내에서. 이거는 `while(i<=mid && j<= right)`로 표현해도 좋겠다

* `sorted[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];`
  왼쪽과 오른쪽 리스트에서 각 요소 크기 비교해서 작은거 순서대로 sorted에 넣고 만약 넣어졌으면 그 리스트의 인덱스는 1 증가하기
* 나머지 if/else문은 한쪽에 남아있는 레코드 비교할 필요 더이상 없으니까 일괄 복사하기
* mergeSort는 합병 정렬 일고리즘을 이용해 int 배열을 오름차순으로 정렬하는 함수임

## 퀵 함수

**quick sort** divide and conquer을 사용한다.</br>
리스트 안에 있는 pivot