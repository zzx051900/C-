//24.有关大小端存储
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int a = 0x11223344;//大段存储，内存中44 33 22 11
	char *pc = (char)&a;
	*pc = 0;//将改为了0
	printf("%x\n", a);//输出时按正常顺序输出，应该为11223300
	return 0;
}