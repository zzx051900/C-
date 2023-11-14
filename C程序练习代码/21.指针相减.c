//21.÷∏’Îœ‡ºı
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 99 };
	int* p = &arr[0];
	int* q = &arr[9];
	printf("%p\n", &arr[0]);

	printf("%p\n", &arr[9]);

	printf("%d\n", &arr[0]);

	printf("%d\n", &arr[9]);

	printf("%d\n", &arr[9] - &arr[0]);

	printf("%d\n", q - p);
	return 0;
}

