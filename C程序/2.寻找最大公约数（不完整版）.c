//2.Ѱ�����Լ���������ư棩

#include<stdio.h>

int main()
{
	int m = 0, n = 0, r = 0;
	scanf("%d %d", &m, &n);
	while (m%n)//շת�������ѭ������Ϊȡģ��Ϊ��
	{
		r = m%n;
		m = n;
		n = r;
	}
	printf("%d\n", r);
	return 0;
}
