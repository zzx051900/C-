#include<iostream>

using namespace std;

void bubbleSort(int* arr, int sz)//冒泡排序，未优化，原始版本
{
	for (int i = 0; i < sz - 1; i++)//sz个元素，需要循环sz-1趟
	{
		for (int j = 0; j < sz - 1 - i; j++)//需要比较的数每次减少一个
		{
			if (arr[j]>arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printArray(int* arr, int sz)//遍历输出数组元素
{
	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5, 6, 9, 4, 3, 2, 8, 7, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);//数组元素个数
	printArray(arr, sz);//输出排序前数组元素
	bubbleSort(arr, sz);
	printArray(arr, sz);//输出排序后数组元素
	system("pause");
	return 0;
}
