//30.�й�����Ԫ�ط���Խ�������(����⣩--��C�����ȱ�ݡ�

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//vc6.0������ <=10,��ѭ��
	//gcc������ <=10,��ѭ��
	//vs2013 <=12,��ѭ��

	//���󴴽�����i��Ҳ������ѭ��������⣩
	for (i = 0; i <= 12; i++)
	{
		printf("hh\n");
		arr[i] = 0;
	}
	system("pause");
	return 0;
}
