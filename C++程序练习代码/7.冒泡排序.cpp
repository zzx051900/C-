//ð����������
#include<iostream>

using namespace std;

int main()
{
	int arr[] = { 2, 4, 3, 5, 6, 8, 9, 7, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//����ǰ���
	for (int i = 0; i<sz; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int i = 0;//�������ѭ������ʾ����
	int j = 0;//�����ڲ�ѭ������ʾ�ڼ�����
	int tmp = 0;//���ڽ���Ԫ��
	for (i = 0; i<sz - 1; i++)//n��Ԫ����Ҫn��1��ѭ��
	{
		for (j = 0; j<sz - 1 - i; j++)//ÿ��ѭ����Ҫ��ͷ��ʼ����Ҫ��j��0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	//��������.

	for (int i = 0; i<sz; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}