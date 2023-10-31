//9.二分查找：写一个函数在一个有序数组中查找具体的某个数(找到的话返回这个数的下标，找不到返回—1)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int binary_search(int arr[], int k, int sz)
{
	int left = 0;//左下标
	int right = sz - 1;//右下标
	int mid = 0;//中间元素的下标
	while (left <= right)//必须是小于等于，因为左右下标相等时也要判断一次
	{
		mid = (right + left) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//给定的有序数组，可能不给定，用scanf输入，可能无序，需要冒泡排序
	int k = 0;//给定的要查找的数
	int sz = sizeof(arr) / sizeof(arr[0]);//测定数组大小
	int ret = 0;
	scanf("%d", &k);
	ret = binary_search(arr, k, sz);//二分查找，传参传的是数组的首地址，要查找的元素，数组长度（数组长度无法在函数中求，因为函数中的arr是指针）
	if (ret == -1)
	{
		printf("找不到指定元素");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}
	return 0;
}