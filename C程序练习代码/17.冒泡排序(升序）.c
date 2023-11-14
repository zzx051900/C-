//17.冒泡排序(升序）
//（一趟冒泡排序让一个元素出现在最终位置）

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void bubble_sort(int arr[], int sz)//初版，未优化
{
	int i = 0;//用于外层循环，表示趟数
	int j = 0;//用于内层循环，表示第几个数
	int tmp = 0;//用于交换元素
	for (i = 0; i<sz - 1; i++)//n个元素需要n—1次循环
	{
		for (j = 0; j<sz - 1 - i; j++)//每趟循环都要从头开始，都要将j置0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void bubble_sort2(int arr[], int sz)
//优化版本，检测一趟循环中是否发生了元素交换
//如果没有元素交换说明数组已经有序，直接跳出循环
{
	int i = 0;//用于外层循环，表示趟数
	int j = 0;//用于内层循环，表示第几个数
	int tmp = 0;//用于交换元素
	int flag = 1;//用于检测是否发生元素交换的标志
	for (i = 0; i<sz - 1; i++)//n个元素需要n—1次循环
	{
		for (j = 0; j<sz - 1 - i; j++)//每趟循环都要从头开始，都要将j置0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//若发生了交换，标志置0,表示仍需循环交换
			}
		}
		if (flag == 1)//若某趟排序后flag仍为1，说明未发生交换，已达成有序数组
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 2, 4, 3, 5, 6, 8, 9, 7, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr,sz);
	bubble_sort2(arr, sz);
	for (int i = 0; i<sz; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}