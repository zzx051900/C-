//9.���ֲ��ң�дһ��������һ�����������в��Ҿ����ĳ����(�ҵ��Ļ�������������±꣬�Ҳ������ء�1)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int binary_search(int arr[], int k, int sz)
{
	int left = 0;//���±�
	int right = sz - 1;//���±�
	int mid = 0;//�м�Ԫ�ص��±�
	while (left <= right)//������С�ڵ��ڣ���Ϊ�����±����ʱҲҪ�ж�һ��
	{
		mid = (right + left) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//�������������飬���ܲ���������scanf���룬����������Ҫð������
	int k = 0;//������Ҫ���ҵ���
	int sz = sizeof(arr) / sizeof(arr[0]);//�ⶨ�����С
	int ret = 0;
	scanf("%d", &k);
	ret = binary_search(arr, k, sz);//���ֲ��ң����δ�����������׵�ַ��Ҫ���ҵ�Ԫ�أ����鳤�ȣ����鳤���޷��ں���������Ϊ�����е�arr��ָ�룩
	if (ret == -1)
	{
		printf("�Ҳ���ָ��Ԫ��");
	}
	else
	{
		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
	}
	return 0;
}