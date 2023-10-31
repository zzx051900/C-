//13.模拟实现strcpy()函数

#define _CRT_SECURE_NO_WARNINGS

//多步优化版本
#include<stdio.h>
#include<assert.h>

//未优化版本，较繁琐
void my_strcpy(char* dest, char* src)//dest表示要复制到的目标数组首地址，src表示源数组首地址
{
	while ((*src) != '\0')
	{
		(*dest) = (*src);
		dest++;//指针++
		src++;
	}
	*dest = *src;//将\0也复制过去
}

//优化版本，循环条件优化
void my_strcpy1(char* dest, char* src)//dest表示要复制到的目标数组首地址，src表示源数组首地址
{
	while (*dest++ = *src++)//将复制和++通知满足，且\0的值为零，可结束循环
	{
		;
	}
}

// 进一步优化，合理性判断，输入不能为野指针（但无法发现问题，也不予采用）
void my_strcpy2(char* dest, char* src)//dest表示要复制到的目标数组首地址，src表示源数组首地址
{
	if (dest != NULL&&src != NULL)
	{
		while (*dest++ = *src++)//将复制和++通知满足，且\0的值为零，可结束循环
		{
			;
		}
	}
}

//当输入野指针时，程序直接报错
void my_strcpy3(char* dest, char* src)//dest表示要复制到的目标数组首地址，src表示源数组首地址
{
	assert(dest != NULL);//断言（不理解），保证指针的有效性
	assert(src != NULL);
	while (*dest++ = *src++)//将复制和++通知满足，且\0的值为零，可结束循环
	{
		;
	}
}

//使用const修饰源数组元素首地址，使源数组内容不能修改，可规避目的与源写反的情况
void my_strcpy4(char* dest, const char* src)//dest表示要复制到的目标数组首地址，src表示源数组首地址
{
	assert(dest != NULL);//断言（不理解）
	assert(src != NULL);
	while (*dest++ = *src++)//将复制和++通知满足，且\0的值为零，可结束循环
	{
		;
	}
}

//将返回值设置为目的数组的首元素地址
char* my_strcpy5(char* dest, const char* src)//dest表示要复制到的目标数组首地址，src表示源数组首地址
{
	char* ret = dest;
	assert(dest != NULL);//断言（不理解）
	assert(src != NULL);
	while (*dest++ = *src++)//将复制和++通知满足，且\0的值为零，可结束循环
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