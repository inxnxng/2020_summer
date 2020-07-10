#include<cstdio>

//1차원 배열에서 최댓값 찾기
int findMaxValue(int a[], int len) {
	int maxVal = a[0];
	for (int i = 0; i < len; i++) {
		if (maxVal < a[i])
			maxVal = a[i];
	}
	return maxVal;
}

void main() {
	int arr[10] = { 3,24,82,12,34,7,53,17,26,51 };
	int maxVal = findMaxValue(arr, 10);
	printf("배열의 최댓값 = %d\n", maxVal);
}

//계속 하고 싶은 말은 배열의 이름을 가져다 쓰면 배열의 포인터로 가져오는 게 되니
//배열의 원래 값이 수정된다는 것과
//배열의 길이는 내가 직접 입력해야하는 수밖에 없다는 것