#include<iostream>

using namespace std;

void bubbleSort(int* arr, int sz)//ð������δ�Ż���ԭʼ�汾
{
	for (int i = 0; i < sz - 1; i++)//sz��Ԫ�أ���Ҫѭ��sz-1��
	{
		for (int j = 0; j < sz - 1 - i; j++)//��Ҫ�Ƚϵ���ÿ�μ���һ��
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

void printArray(int* arr, int sz)//�����������Ԫ��
{
	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5, 6, 9, 4, 3, 2, 8, 7, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
	printArray(arr, sz);//�������ǰ����Ԫ��
	bubbleSort(arr, sz);
	printArray(arr, sz);//������������Ԫ��
	system("pause");
	return 0;
}
