//һά���鰸��������Ԫ������
//����������������һ��5��Ԫ�ص����飬���ҽ�Ԫ������
#include<iostream>

using namespace std;

int main()
{
	int arr[5] = { 9, 3, 7, 2, 8 };
	int temp = 0;//���ڽ�������ʱ���Ԫ��

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 5 / 2; i++)//iС������Ԫ�ظ�����һ��
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