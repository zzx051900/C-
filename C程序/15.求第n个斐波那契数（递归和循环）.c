//15.���n��쳲����������ݹ��ѭ����
//�����ݹ�ͬһ�����ᱻ�����ظ����㣬�˷���Դ��
//�ݹ��ѭ���������ڲ��ó�������������һ�־�һ����Զ�Ǻõķ���

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Fib1(int n)//�ݹ�
{
	if (n <= 2)
		return 1;
	if (n>2)
		return Fib1(n - 1) + Fib1(n - 2);
}

int Fib2(int n)//ѭ�������Ա�������ظ�
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;//���n��쳲�������
	int ret = 0;
	scanf("%d", &n);
	ret = Fib1(n);
	printf("%d\n", ret);
	ret = Fib2(n);
	printf("%d\n", ret);
	for (int i = 1; i <= 10; i++)///�����1~10��쳲�������
	{
		printf("%d\t", Fib1(i));
	}

	return 0;
}