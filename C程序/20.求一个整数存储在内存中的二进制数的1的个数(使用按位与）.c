//20.��һ�������洢���ڴ��еĶ���������1�ĸ���(ʹ�ð�λ��&��

//(�������ڴ����ò���洢��

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int num = 0;
	int count;//1�ĸ���
	scanf("%d", &num);
	//һ������������λ��1�����Ϊ1˵��ĩβΪ1�����Ϊ0˵��ĩβ��0
	for (int i = 0; i<32; i++)
	{
		if ((num >> i) & 1 == 1)//��Ҫ����λ�ƶ������λ
			count++;
	}
	printf("%d", count);
	return 0;
}