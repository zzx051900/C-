//10.дһ��������ÿһ�ε��ú����ͻ���num��ֵ��һ
//����Ϊͨ�������޸��������е�ֵ������Ҫ�ô�ֵ���ã�
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Add(int* p)//��ָ����յ�ַ
{
	(*p)++;//  *���������� ��++�����ȼ��ϸߣ�Ҫ��������*p
}
int main()
{
	int num = 0;
	Add(&num);//������num�ĵ�ַ
	printf("%d\n", num);//�鿴num��ֵ�Ƿ�ı�
	Add(&num);//������num�ĵ�ַ
	printf("%d\n", num);//�鿴num��ֵ�Ƿ�ı�
	Add(&num);//������num�ĵ�ַ
	printf("%d\n", num);//�鿴num��ֵ�Ƿ�ı�
	return 0;
}