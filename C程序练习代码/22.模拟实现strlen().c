//22.ģ��ʵ��strlen()��ʹ��ָ����������Ϊ�м�Ԫ�ظ�����

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int my_strlen(char* arr)
{
	char* start = arr;
	char* end = arr;
	while (*end != '\0')//����ʹ�õ���ָ��endָ����ַ���Ҫ������
	{
		end++;
	}
	return end - start;
}

int main()
{
	char arr[] = { "hello" };
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
