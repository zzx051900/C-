//28.��ȡһ������������ʽ������λ��ż��λ���ֱ��ӡ

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void print(int m)//ʵ�ִ�ӡ����λ��ż��λ
{
	printf("��ӡ����λ��\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
	printf("\n");

	printf("��ӡż��λ��\n");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
}

int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}