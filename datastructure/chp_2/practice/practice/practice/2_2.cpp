#include<cstdio>

//1���� �迭���� �ִ� ã��
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
	printf("�迭�� �ִ� = %d\n", maxVal);
}

//��� �ϰ� ���� ���� �迭�� �̸��� ������ ���� �迭�� �����ͷ� �������� �� �Ǵ�
//�迭�� ���� ���� �����ȴٴ� �Ͱ�
//�迭�� ���̴� ���� ���� �Է��ؾ��ϴ� ���ۿ� ���ٴ� ��