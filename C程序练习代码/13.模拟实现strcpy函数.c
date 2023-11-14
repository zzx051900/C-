//13.ģ��ʵ��strcpy()����

#define _CRT_SECURE_NO_WARNINGS

//�ಽ�Ż��汾
#include<stdio.h>
#include<assert.h>

//δ�Ż��汾���Ϸ���
void my_strcpy(char* dest, char* src)//dest��ʾҪ���Ƶ���Ŀ�������׵�ַ��src��ʾԴ�����׵�ַ
{
	while ((*src) != '\0')
	{
		(*dest) = (*src);
		dest++;//ָ��++
		src++;
	}
	*dest = *src;//��\0Ҳ���ƹ�ȥ
}

//�Ż��汾��ѭ�������Ż�
void my_strcpy1(char* dest, char* src)//dest��ʾҪ���Ƶ���Ŀ�������׵�ַ��src��ʾԴ�����׵�ַ
{
	while (*dest++ = *src++)//�����ƺ�++֪ͨ���㣬��\0��ֵΪ�㣬�ɽ���ѭ��
	{
		;
	}
}

// ��һ���Ż����������жϣ����벻��ΪҰָ�루���޷��������⣬Ҳ������ã�
void my_strcpy2(char* dest, char* src)//dest��ʾҪ���Ƶ���Ŀ�������׵�ַ��src��ʾԴ�����׵�ַ
{
	if (dest != NULL&&src != NULL)
	{
		while (*dest++ = *src++)//�����ƺ�++֪ͨ���㣬��\0��ֵΪ�㣬�ɽ���ѭ��
		{
			;
		}
	}
}

//������Ұָ��ʱ������ֱ�ӱ���
void my_strcpy3(char* dest, char* src)//dest��ʾҪ���Ƶ���Ŀ�������׵�ַ��src��ʾԴ�����׵�ַ
{
	assert(dest != NULL);//���ԣ�����⣩����ָ֤�����Ч��
	assert(src != NULL);
	while (*dest++ = *src++)//�����ƺ�++֪ͨ���㣬��\0��ֵΪ�㣬�ɽ���ѭ��
	{
		;
	}
}

//ʹ��const����Դ����Ԫ���׵�ַ��ʹԴ�������ݲ����޸ģ��ɹ��Ŀ����Դд�������
void my_strcpy4(char* dest, const char* src)//dest��ʾҪ���Ƶ���Ŀ�������׵�ַ��src��ʾԴ�����׵�ַ
{
	assert(dest != NULL);//���ԣ�����⣩
	assert(src != NULL);
	while (*dest++ = *src++)//�����ƺ�++֪ͨ���㣬��\0��ֵΪ�㣬�ɽ���ѭ��
	{
		;
	}
}

//������ֵ����ΪĿ���������Ԫ�ص�ַ
char* my_strcpy5(char* dest, const char* src)//dest��ʾҪ���Ƶ���Ŀ�������׵�ַ��src��ʾԴ�����׵�ַ
{
	char* ret = dest;
	assert(dest != NULL);//���ԣ�����⣩
	assert(src != NULL);
	while (*dest++ = *src++)//�����ƺ�++֪ͨ���㣬��\0��ֵΪ�㣬�ɽ���ѭ��
	{
		;
	}
	return ret;
}

int main()

{
	char arr1[] = "#############";
	char arr2[] = "bit";
	//my_strcpy(arr1, arr2);
	//my_strcpy1(arr1, arr2);
	//my_strcpy2(arr1, arr2);
	//my_strcpy3(arr1, arr2);
	//my_strcpy4(arr1, arr2);
	//printf("%s\n", arr1);
	printf("%s\n", my_strcpy5(arr1, arr2));
	return 0;
}