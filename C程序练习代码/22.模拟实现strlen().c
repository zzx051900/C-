//22.模拟实现strlen()，使用指针相减（结果为中间元素个数）

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int my_strlen(char* arr)
{
	char* start = arr;
	char* end = arr;
	while (*end != '\0')//这里使用的是指针end指向的字符，要解引用
	{
		end++;
	}
	return end - start;
}

int main()
{
	char arr[] = { "hello" };
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
