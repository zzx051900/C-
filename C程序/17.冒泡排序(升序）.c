//17.ð������(����
//��һ��ð��������һ��Ԫ�س���������λ�ã�

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void bubble_sort(int arr[], int sz)//���棬δ�Ż�
{
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
}

void bubble_sort2(int arr[], int sz)
//�Ż��汾�����һ��ѭ�����Ƿ�����Ԫ�ؽ���
//���û��Ԫ�ؽ���˵�������Ѿ�����ֱ������ѭ��
{
	int i = 0;//�������ѭ������ʾ����
	int j = 0;//�����ڲ�ѭ������ʾ�ڼ�����
	int tmp = 0;//���ڽ���Ԫ��
	int flag = 1;//���ڼ���Ƿ���Ԫ�ؽ����ı�־
	for (i = 0; i<sz - 1; i++)//n��Ԫ����Ҫn��1��ѭ��
	{
		for (j = 0; j<sz - 1 - i; j++)//ÿ��ѭ����Ҫ��ͷ��ʼ����Ҫ��j��0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//�������˽�������־��0,��ʾ����ѭ������
			}
		}
		if (flag == 1)//��ĳ�������flag��Ϊ1��˵��δ�����������Ѵ����������
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