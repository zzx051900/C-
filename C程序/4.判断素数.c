//4.�ж��Ƿ�Ϊ�������Գ���)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n = 0, i = 2;			//nΪҪ�жϵ�������iΪ�Գ�����Ҫ��ѭ������
	scanf("%d", &n);
	for (i; i < n; i++)		    //��n����2��n-1������Ѱ���Ƿ��п�������������û����Ϊ����(Ч�ʽϵͣ�//(�Ż�������ֻ�жϵ���ƽ��n���ÿ⺯��sqrt()
	{
		if (n%i == 0)
			break;
	}
	if (i == n)
	{
		printf("%dΪ����\n", n);
	}
	else
	{
		printf("%d��������\n", n);
	}
	return 0;
}