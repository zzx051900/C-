//25.�й�sizeof�Ľ�һ�����
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int i = 0;//ȫ�ֱ����;�̬����Ĭ�ϳ�ʼ��Ϊ0���ֲ�����Ĭ�ϳ�ʼ��Ϊ���ֵ

int main()
{
	i--;//-1
	if (i>sizeof(-1))//sizeof�ķ���ֵΪ�޷������ͣ�-1��������ʱҲ��ת��Ϊ�޷�������
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}