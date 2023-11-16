//冒泡排序（升序）
#include<iostream>

using namespace std;

int main()
{
	int arr[] = { 2, 4, 3, 5, 6, 8, 9, 7, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//排序前输出
	for (int i = 0; i<sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
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
	//排序后输出.

	for (int i = 0; i<sz; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}