//26.���������1�ĸ���(�����ò����ʾ)

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Count1(int a)
{
	int count = 0;
	for (int i = 0; i<32; i++)
	{
		if ((a >> i) & 1 == 1)//��λ��1��ke�ж����һ���Ƿ���1
			count++;
	}
	return count;
}

int Count2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);//ʹa�Ķ�������ʽ�����ұ�һ�������0
		count++;
	}
	return count;
}

int main()
{
	int a = 0, count = 0;
	scanf("%d", &a);
	count = Count1(a);
	printf("%d\n", count);
	count = Count2(a);
	printf("%d\n", count);
	return 0;
}