//12.编写一个函数求字符串的长度

#define _CRT_SECURE_NO_WARNINGS

//方案1：有临时变量的方法，非递归

#include<stdio.h>
#include<string.h>

int my_strlen(char* arr)//传的是数组首元素的地址，要用指针接收
{
	int count = 0;
	while ((*arr) != '\0')
	{
		count++;
		arr++;//指针加一，表示指向下一个数组元素
	}
	return count
		;
}
int main()
{
	char arr[] = "bit";
	//int len = strlen(arr);
	//printf("%d\n",len);

	//模拟实现一个strlen函数
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}


//方案2：无临时变量的方法，递归方法
//(递归就是把一个问题化为1加一个小问题，再把小问题化为1加更小的问题，以此类推，最后先实现最小的问题，再慢慢往前整合)
/*
#include<stdio.h>
#include<string.h>

int my_strlen(char* str)//传的是数组首元素的地址，要用指针接收
{
	if ((*str) != '\0')
		return 1 + my_strlen(str + 1);//如果第一个字符不是结束符，则长度为‘1+后面的字符串’
	else
		return 0;
}

int main()
{
	char arr[] = "bit";
	//int len = strlen(arr);
	//printf("%d\n",len);

	//模拟实现一个strlen函数
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
*/