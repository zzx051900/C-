//6.����1/1-1/2+1/3-1/4+1/5...+1/99-1/100��ֵ
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
int main()
{
	int i = 1, flag = 1;//flagΪ���ű�־
	double sum = 0;
	for (i = 1; i <= 100; i++)
	{
		flag = pow(-1, i + 1);//������2������Ϊ-1��i+1�η�����ƽ����ʽpow(a,b)
		sum += flag*(1.0 / i);//Ҫ�õ��������ͣ�������ʱ����һ����ҪΪ�������ͣ�����д1.0
		//flag = -flag;//(����1��flag�ĸ���ÿ�θպ÷�ת
	}
	printf("%lf\n", sum);
	return 0;
}