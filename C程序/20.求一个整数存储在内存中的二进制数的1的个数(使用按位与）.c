//20.求一个整数存储在内存中的二进制数的1的个数(使用按位与&）

//(整数在内存中用补码存储）

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int num = 0;
	int count;//1的个数
	scanf("%d", &num);
	//一个二进制数按位与1，结果为1说明末尾为1，结果为0说明末尾是0
	for (int i = 0; i<32; i++)
	{
		if ((num >> i) & 1 == 1)//将要检测的位移动到最低位
			count++;
	}
	printf("%d", count);
	return 0;
}