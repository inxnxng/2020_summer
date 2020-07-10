#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_SIZE 10

void sub(int x, int arr[]) {
	x = 10;
	arr[0] = 10;
}

void main() {
	int var;
	int list[MAX_SIZE];
	var = 0;
	list[0] = 0;
	sub(var, list);
	printf("var=%d, list[0]=%d\n", var, list[0]);
	//var값이 안바뀌는 것은 값을 복사만 해서 썼기 때문에 원래의 값이 바뀌지 않는 것.
	//list값이 바뀌는 것은 주소를 가져갔기 때문. 포인터를 가져갔기 때문.
}

