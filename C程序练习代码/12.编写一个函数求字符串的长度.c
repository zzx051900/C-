//12.��дһ���������ַ����ĳ���

#define _CRT_SECURE_NO_WARNINGS

//����1������ʱ�����ķ������ǵݹ�

#include<stdio.h>
#include<string.h>

int my_strlen(char* arr)//������������Ԫ�صĵ�ַ��Ҫ��ָ�����
{
	int count = 0;
	while ((*arr) != '\0')
	{
		count++;
		arr++;//ָ���һ����ʾָ����һ������Ԫ��
	}
	return count
		;
}
int main()
{
	char arr[] = "bit";
	//int len = strlen(arr);
	//printf("%d\n",len);

	//ģ��ʵ��һ��strlen����
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}


//����2������ʱ�����ķ������ݹ鷽��
//(�ݹ���ǰ�һ�����⻯Ϊ1��һ��С���⣬�ٰ�С���⻯Ϊ1�Ӹ�С�����⣬�Դ����ƣ������ʵ����С�����⣬��������ǰ����)
/*
#include<stdio.h>
#include<string.h>

int my_strlen(char* str)//������������Ԫ�صĵ�ַ��Ҫ��ָ�����
{
	if ((*str) != '\0')
		return 1 + my_strlen(str + 1);//�����һ���ַ����ǽ��������򳤶�Ϊ��1+������ַ�����
	else
		return 0;
}

int main()
{
	char arr[] = "bit";
	//int len = strlen(arr);
	//printf("%d\n",len);

	//ģ��ʵ��һ��strlen����
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
*/