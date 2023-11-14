//29.使用指针打印数组内容

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void print(int *p, int sz);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}

void print(int *p, int sz)
{
	for (int i = 0; i<sz; i++)
	{
		printf("%d ", *(p + i));
	}
}