//14.��n�Ľ׳�
//���ֱ���ѭ���͵ݹ�ʵ�֣�

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Fac1(int n)//��ѭ���ķ�����׳�
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int Fac2(int n)//�õݹ�ķ�����׳�
{
	if (n == 1)//�����ǵ��ڣ�ע��"����"��"==����һ��"=����ʾ��ֵ������
		return 1;
	return n*Fac2(n - 1);

}

int main()
{
	int n = 0;//n�Ľ׳�
	int ret = 0;//��Ž��
	scanf("%d", &n);
	ret = Fac1(n);
	printf("%d\n", ret);
	ret = Fac2(n);
	printf("%d\n", ret);
	return 0;
}