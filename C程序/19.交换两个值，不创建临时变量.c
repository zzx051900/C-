//19.��������ֵ����������ʱ����

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	//����a��b��ֵ
	int a = 5;
	int b = 3;
	printf("a=%d b=%d\n", a, b);
	//����һ��������ʱ����
	int tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);

	//���������Ӽ��������ܲ��������
	a = a + b;//8,3
	b = a - b;//8,5
	a = a - b;//3,5
	printf("a=%d b=%d\n", a, b);

	//���������׻򷨣�������������
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	return 0;
}