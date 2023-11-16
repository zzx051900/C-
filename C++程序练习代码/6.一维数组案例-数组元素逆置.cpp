//一维数组案例：数组元素逆置
//案例描述：请声明一个5个元素的数组，并且将元素逆置
#include<iostream>

using namespace std;

int main()
{
	int arr[5] = { 9, 3, 7, 2, 8 };
	int temp = 0;//用于交换是暂时存放元素

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 5 / 2; i++)//i小于数组元素个数的一半
	{
		temp = arr[i];
		arr[i] = arr[4 - i];
		arr[4 - i] = temp;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}