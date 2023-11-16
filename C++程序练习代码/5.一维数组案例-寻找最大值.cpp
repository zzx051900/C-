//一维数组案例：寻找最大值
#include<iostream>

using namespace std;

int main()
{
	//1.创建数组
	int arr[5] = { 50, 40, 60, 70, 90 };
	//2.寻找最大值
	int max = 0;//存放最大值
	for (int i = 0; i < 5; i++)
	{
		if (arr[i]>max)
			max = arr[i];//如果访问的元素比我认定的元素大，则更新最大值
	}
	//3.输出最大值
	cout << "最大值为：" << max << endl;
	system("pause");
	return 0;
}