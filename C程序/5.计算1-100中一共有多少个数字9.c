//5.����1��100��һ�������ٸ�����9
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int i = 0, count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)//����Ϊ9
			count++;
		if (i / 10 == 9)//ʮλ��Ϊ9
			count++;
	}
	printf("%d\n", count);
	return 0;
}
