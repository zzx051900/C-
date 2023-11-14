//23.���������
//1��ʵ�ֺ���Init�����������ʼ��Ϊ0
//2��ʵ�ֺ���Print������ӡ����ÿ��Ԫ��
//3��ʵ�ֺ���Reverse�����������Ԫ������
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
	int end = sz - 1;//��ŵ��������±꣬��������Ԫ��
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
	int sz = sizeof(arr) / sizeof(arr[0]);//�����ڲ��޷����������С
	//Init(arr,sz);//��ʼ������
	Print(arr, sz);//��ӡ����
	Reverse(arr, sz);//��������
	Print(arr, sz);//��ӡ����
	return 0;
}