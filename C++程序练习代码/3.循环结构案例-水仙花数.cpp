/*
����������ˮ�ɻ�����ָһ��3λ��������ÿ��λ�ϵ����ֵ�3����֮�͵���������
���磺1^3+5^3+3^3=153
ʹ��do...while��䣬�������3λ���е�ˮ�ɻ���
*/
#include<iostream>

using namespace std;

int main()
{
	int m = 100;//3λ������100��ʼ

	int a = 0;//��ȡ��λ����
	int b = 0;//��ȡʮλ����
	int c = 0;//��ȡ��λ����

	do
	{
		a = m / 100;
		b = m / 10 % 10;
		c = m % 10;
		if (a*a*a + b*b*b + c*c*c == m)
		{
			cout << m << endl;
		}
		m++;
	} while (m < 1000);

	system("pause");
	return 0;
}