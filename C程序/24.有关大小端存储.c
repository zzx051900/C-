//24.�йش�С�˴洢
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int a = 0x11223344;//��δ洢���ڴ���44 33 22 11
	char *pc = (char)&a;
	*pc = 0;//����Ϊ��0
	printf("%x\n", a);//���ʱ������˳�������Ӧ��Ϊ11223300
	return 0;
}