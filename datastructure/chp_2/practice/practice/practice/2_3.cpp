int findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for(int i = 0 ; i < h ; i++)
		for (int j = 0; j < w; j++) {
			if (maxVal < a[i][j])
				maxVal = a[i][j];
		}
	return maxVal;
}

#include<cstdio>

void main() {
	int img[4][5] = { {3,24,82,23,33},
		{34,6,23,72,54},
		{99,43,6,36,65},
		{20,25,46,68,9} };
	int maxPixel = findMaxPixel(img, 4, 5);
	printf("영상의 최대 밝기 = %d", maxPixel);
}