//3.�ж�����
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	//�����׼��1.�ܱ�4�����Ҳ��ܱ�100���� 2.�ܱ�400����
	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
	{
		printf("%d������\n", n);
	}
	else
	{
		printf("%d��������\n", n);
	}
	return 0;
}