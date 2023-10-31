//23.数组操作：
//1。实现函数Init（）对数组初始化为0
//2。实现函数Print（）打印数组每个元素
//3。实现函数Reverse（）完成数组元素逆置
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void Init(int arr[], int sz)
{
	for (int i = 0; i<sz; i++)
	{
		arr[i] = 0;
	}
}

void Print(int arr[], int sz)
{
	for (int i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Reverse(int arr[], int sz)
{
	int start = 0;
	int end = sz - 1;//这放的是数组下标，不是数组元素
	while (start<end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);//函数内部无法计算数组大小
	//Init(arr,sz);//初始化数组
	Print(arr, sz);//打印数组
	Reverse(arr, sz);//逆序数组
	Print(arr, sz);//打印数组
	return 0;
}