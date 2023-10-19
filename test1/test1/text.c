//初级学习C语言，简单练习

//#define _CRT_SECURE_NO_WARNINGS   //已在项目属性中更改，故不再需要

/*
#include<stdio.h>
int main()
{

	return 0;
}
*/



//1.输出Hello World
/*
#include<stdio.h>

int main()
{
	printf("hello world\n");
	return 0;
}
*/

//2.寻找最大公约数（不完善版）
/*
#include<stdio.h>

int main()
{
int m = 0, n = 0, r = 0;
scanf("%d %d", &m, &n);
while (m%n)//辗转相除法，循环条件为取模不为零
{
r = m%n;
m = n;
n = r;
}
printf("%d\n", r);
return 0;
}
*/

//3.判断闰年
/*
#include<stdio.h>

int main()
{
int n = 0;
scanf("%d", &n);//闰年标准：1.能被4整除且不能被100整除 2.能被400整除
if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
{
printf("%d是闰年\n", n);
}
else
{
printf("%d不是闰年\n", n);
}
return 0;
}
*/

//4.判断是否为素数（试除法)
/*
#include<stdio.h>

int main()
{
int n = 0, i = 2;			//n为要判断的素数，i为试除法需要的循环变量
scanf("%d", &n);
for (i; i < n; i++)		    //用n除以2到n-1的数，寻找是否有可以整除的数，没有则为素数(效率较低）//(优化）可以只判断到开平方n，用库函数sqrt()
{
if (n%i == 0)
break;
}
if (i == n)
{
printf("%d为素数\n", n);
}
else
{
printf("%d不是素数\n", n);
}
return 0;
}
*/

//5.计算1到100中一共含多少个数字9
/*
#include<stdio.h>

int main()
{
	int i = 0, count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)//余数为9
			count++;
		if (i / 10 == 9)//十位数为9
			count++;
	}
	printf("%d\n", count);
	return 0;
}
*/

//6.计算1/1-1/2+1/3-1/4+1/5...+1/99-1/100的值
/*
#include<stdio.h>
#include<math.h>
int main()
{
int i = 1, flag = 1;//flag为负号标志
double sum = 0;
for (i = 1; i <= 100; i++)
{
flag = pow(-1, i + 1);//（方法2）符号为-1的i+1次方，用平方公式pow(a,b)
sum += flag*(1.0 / i);//要得到浮点类型，则运算时至少一个数要为浮点类型，所以写1.0
//flag = -flag;//(方法1）flag的负号每次刚好反转
}
printf("%lf\n", sum);
return 0;
}

*/

//7.小游戏：猜数字游戏
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
printf("***************************\n");
printf("****  1.play   0.exit *****\n");
printf("***************************\n");
}

void game()
{
int ret = rand()%100+1;//生成1~100的随机数
int guess = 0;//接收玩家猜的输入的数字
while (1)//死循环不断判断，直到猜到为止，使用break跳出
{
printf("请猜数字:>");
scanf("%d", &guess);
if (guess < ret)
{
printf("猜小了\n");
}
else if (guess > ret)
{
printf("猜大了\n");
}
else
{
printf("恭喜你，猜对了！\n");
break;
}

}
}

void judge()//玩家选择是否开始游戏
{
int input = 0;//玩家输入1或0，选择是否开始游戏
do//因为程序最少执行一次，所以选择do.while结构
{
menu();//提示窗口
printf("开始游戏或继续游戏请输入1，退出游戏请输入0>:");
scanf("%d", &input);
switch (input)
{
case 1:
game();//猜数字游戏函数
break;
case 0:
printf("退出游戏\n");
break;
default:
printf("选择错误\n");
break;
}

} while (input);//输入0时退出，输入1或其他值时都可再次选择
}
int main()
{
srand((unsigned)time(NULL));//初始化随机数发生器
judge();//玩家选择是否开始游戏
return 0;
}
*/

//8.判断素数
/*
#include<stdio.h>
#include<math.h>

int is_prime(int n)
{
int i = 0;
for (i = 2; i <= sqrt(n); i++)
{
if (n%i == 0)
{
return 0;
}
}

return 1;

}
int main()
{
int m = 0;
scanf("%d", &m);
//是素数返回1，不是素数返回0
printf("%d\n", is_prime(m));
return 0;
}
*/

//9.写一个函数在一个有序数组中查找具体的某个数(找到的话返回这个数的下标，找不到返回—1)

//(使用二分查找)
/*
#include<stdio.h>

int binary_search(int arr[], int k, int sz)
{
	int left = 0;//左下标
	int right = sz - 1;//右下标
	int mid = 0;//中间元素的下标
	while (left <= right)//必须是小于等于，因为左右下标相等时也要判断一次
	{
		mid = (right + left) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//给定的有序数组，可能不给定，用scanf输入，可能无序，需要冒泡排序
	int k = 0;//给定的要查找的数
	int sz = sizeof(arr) / sizeof(arr[0]);//测定数组大小
	int ret = 0;
	scanf("%d", &k);
	ret = binary_search(arr, k, sz);//二分查找，传参传的是数组的首地址，要查找的元素，数组长度（数组长度无法在函数中求，因为函数中的arr是指针）
	if (ret == -1)
	{
		printf("找不到指定元素");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}
	return 0;
}
*/

//10.写一个函数，每一次调用函数就会让num的值加一

//（因为通过函数修改主程序中的值，所以要用传值调用）
/*
#include<stdio.h>

void Add(int* p)//用指针接收地址
{
	(*p)++;//  *用来解引用 ，++的优先级较高，要用括号括*p
}
int main()
{
	int num = 0;
	Add(&num);//传的是num的地址
	printf("%d\n", num);//查看num的值是否改变
	Add(&num);//传的是num的地址
	printf("%d\n", num);//查看num的值是否改变
	Add(&num);//传的是num的地址
	printf("%d\n", num);//查看num的值是否改变
	return 0;
}
*/

//11.初体验递归

//接受一个无符号整型，按顺序打印他的每一位(使用递归）
/*
#include<stdio.h>

void print(int num)
{
	if (num>9)
	{
		print(num / 10);
	}
	printf("%d ", num % 10);
}

int main()
{

	int num = 0;
	scanf("%d", &num);
	print(num);
	return 0;
}
*/

//12.编写一个函数求字符串的长度(有临时变量的方法，非递归）
/*
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
*/

//13.编写一个函数求字符串的长度

//(无临时变量的方法，递归方法）
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

//14.求n的阶乘

//（分别用循环和递归实现）
/*
#include<stdio.h>

int Fac1(int n)//用循环的方法求阶乘
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int Fac2(int n)//用递归的方法求阶乘
{
	if (n == 1)//可以是等于，注意"等于"是"==”，一个"=”表示赋值！！！
		return 1;
	return n*Fac2(n - 1);

}

int main()
{
	int n = 0;//n的阶乘
	int ret = 0;//存放结果
	scanf("%d", &n);
	ret = Fac1(n);
	printf("%d\n", ret);
	ret = Fac2(n);
	printf("%d\n", ret);
	return 0;
}
*/

//15.求第n个斐波那契数（递归和循环）

//（但递归同一个数会被大量重复计算，浪费资源）
//递归和循环各适用于不用场景，并不是哪一种就一定永远是好的方法
/*
#include<stdio.h>

int Fib1(int n)//递归
{
	if (n <= 2)
		return 1;
	if (n>2)
		return Fib1(n - 1) + Fib1(n - 2);
}

int Fib2(int n)//循环，可以避免大量重复
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;//求第n个斐波那契数
	int ret = 0;
	scanf("%d", &n);
	ret = Fib1(n);
	printf("%d\n", ret);
	ret = Fib2(n);
	printf("%d\n", ret);
	for (int i = 1; i <= 10; i++)///输出第1~10个斐波那契数
	{
		printf("%d\t", Fib1(i));
	}

	return 0;
}
*/

//16.关于sizeof和strlen的区别
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[] = "abc";
	char arr2[] = { 'a', 'b', 'c' };
	printf("%d\n", sizeof(arr1));
	printf("%d\n", sizeof(arr2));
	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));//???
	return 0;
}
*/

//17.冒泡排序(升序）

//（一趟冒泡排序让一个元素出现在最终位置）
/*
#include<stdio.h>

void bubble_sort(int arr[], int sz)//初版，未优化
{
	int i = 0;//用于外层循环，表示趟数
	int j = 0;//用于内层循环，表示第几个数
	int tmp = 0;//用于交换元素
	for (i = 0; i<sz - 1; i++)//n个元素需要n—1次循环
	{
		for (j = 0; j<sz - 1 - i; j++)//每趟循环都要从头开始，都要将j置0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void bubble_sort2(int arr[], int sz)
//优化版本，检测一趟循环中是否发生了元素交换
//如果没有元素交换说明数组已经有序，直接跳出循环
{
	int i = 0;//用于外层循环，表示趟数
	int j = 0;//用于内层循环，表示第几个数
	int tmp = 0;//用于交换元素
	int flag = 1;//用于检测是否发生元素交换的标志
	for (i = 0; i<sz - 1; i++)//n个元素需要n—1次循环
	{
		for (j = 0; j<sz - 1 - i; j++)//每趟循环都要从头开始，都要将j置0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//若发生了交换，标志置0,表示仍需循环交换
			}
		}
		if (flag == 1)//若某趟排序后flag仍为1，说明未发生交换，已达成有序数组
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 2, 4, 3, 5, 6, 8, 9, 7, 1, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//bubble_sort(arr,sz);
	bubble_sort2(arr, sz);
	for (int i = 0; i<sz; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}
*/

//18.测试井字棋游戏（宏定义在函数中使用时未进行参数传递）

//可更改棋盘大小，但局势判断环节只会判断井字棋
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3//棋盘行数
#define COL 3//棋盘列数
//行和列已经预定义好了，函数中使用时还需要传参吗？？

//函数声明
void menu();
void test();
void game();
void Displayboard(char board[ROW][COL]);
void Initboard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
char IsWin(char board[ROW][COL]);
int Full(char board[ROW][COL]);

void menu()//提示菜单
{
	printf("***********************\n");
	printf("*** 1.game  0.exit ****\n");
	printf("***********************\n");
}

void test()//选择是否进入游戏或再次进入游戏
{
	int input = 0;
	do
	{
		menu();//输出提示菜单
		printf("请选择是否开始游戏：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏函数，包含整个游戏流程
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);//只有输入零会停止
}

void game()//游戏的整个实现流程
{
	char flag = '0';//用于表示游戏状态
	//'*'表示玩家赢，'#'表示电脑赢，'Q‘表示平局，'C’表示继续
	char board[ROW][COL] = { 0 }; //数组，存放棋盘信息//使用预定义ROW和COL方便后续修改棋盘行列大小
	Initboard(board);//棋盘初始化
	Displayboard(board);//打印数组(传参的时候传的是数组名，实参行，实参列）
	//正式下棋
	while (1)
	{
		//玩家走
		PlayerMove(board);
		Displayboard(board);
		flag = IsWin(board);//判断输赢
		if (flag != 'C')//如果判断条件已经不为'C'，则直接跳出
		{
			break;
		}
		//电脑走
		ComputerMove(board);
		Displayboard(board);
		flag = IsWin(board);//判断输赢
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("玩家赢\n\n");
	}
	else if (flag == '#')
	{
		printf("电脑赢\n\n");
	}
	else if (flag == 'Q')
	{
		printf("平局\n\n");
	}
}

//理想棋盘状态
// a | a | a 
//---|---|---
// a | a | a 
//---|---|---
// a | a | a 

void Initboard(char board[ROW][COL])//棋盘数组初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COL; j++)
		{
			board[i][j] = ' ';//初始给每个元素一个空格
		}
	}
}

void Displayboard(char board[ROW][COL])//打印棋盘,参数为一个3×3的棋盘，一个形参行，一个形参列
{
	for (int i = 0; i<ROW; i++)//外层循环，循环行,
	{
		//打印一行的数据
		for (int j = 0; j<COL - 1; j++)//内层循环，循环列，前COL－1组元素
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %c \n", board[i][COL - 1]);//每一列最后一个元素
		//打印分割行(第ROW-1行不需要分割行）
		if (i<ROW - 1)
		{
			for (int j = 0; j<COL - 1; j++)//内层循环，循环列，前COL－1组元素
			{
				printf("---|");
			}
			printf("---\n");//分割行的每一列最后一组元素
		}
	}
}

void PlayerMove(char board[ROW][COL])//玩家落子
{
	int i = 0;
	int j = 0;
	printf("玩家走:>\n");
	while (1)//循环判断，直到玩家输入正确
	{
		printf("玩家请落子\n");
		scanf("%d %d", &i, &j);//玩家输入落子的坐标//默认玩家认为坐标从（1，1）开始
		if (i >= 1 && i <= ROW&&j >= 1 && j <= COL&&board[i - 1][j - 1] == ' ')//这个位置是空格，代表可以落子
		{
			board[i - 1][j - 1] = '*';//玩家落子用*表示
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL])//电脑落子，为随机生成
{
	int i = 0;
	int j = 0;
	printf("电脑走:>\n");
	while (1)//循环判断，直到电脑随机数输入正确
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (board[i][j] == ' ')//电脑落子生成的下标就是数组下标，不用更改
		{
			board[i][j] = '#';//电脑落子用#表示
			break;
		}
	}
}

int Full(char board[ROW][COL])//判断棋盘是否已满
{
	for (int i = 0; i<ROW; i++)
	{
		for (int j = 0; j<COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL])//判断局势
{
	for (int i = 0; i<ROW; i++)//判断列是否三个相连
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int j = 0; j<COL; j++)//判断行是否三个相连
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断对角线是否三个相连
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	//若仍不满足     
	if (Full(board) == 1)//棋盘已满，且仍为跳出说明平局
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}

int main()
{
	srand((unsigned int)time(NULL));//初始化随机数发生器
	test();///开始测试
	return 0;
}
*/

//19.交换两个值，不创建临时变量
/*
#include<stdio.h>

int main()
{
	//交换a和b的值
	int a = 5;
	int b = 3;
	printf("a=%d b=%d\n", a, b);
	//方案一：创建临时变量
	int tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);

	//方案二：加减法（可能产生溢出）
	a = a + b;//8,3
	b = a - b;//8,5
	a = a - b;//3,5
	printf("a=%d b=%d\n", a, b);

	//方案三：易或法（不会产生溢出）
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	return 0;
}
*/

//20.求一个整数存储在内存中的二进制数的1的个数(使用按位与&）

//(整数在内存中用补码存储）
/*
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
*/

//21.指针相减
/*
#include<stdio.h>

int main()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 99 };
	int* p = &arr[0];
	int* q = &arr[9];
	printf("%p\n", &arr[0]);

	printf("%p\n", &arr[9]);

	printf("%d\n", &arr[0]);

	printf("%d\n", &arr[9]);

	printf("%d\n", &arr[9] - &arr[0]);

	printf("%d\n", q - p);
	return 0;
}
*/

//22.模拟实现strlen()，使用指针相减（结果为中间元素个数）
/*
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
*/

//23.数组操作：

//1。实现函数Init（）对数组初始化为0
//2。实现函数Print（）打印数组每个元素
//3。实现函数Reverse（）完成数组元素逆置
/*
#include<stdio.h>

void Init(int arr[], int sz)
{
	for (int i = 0; i<sz; i++)
	{
		arr[i] = 0;
	}
}

void Print(int arr[], int sz)
{
	for (int i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Reverse(int arr[], int sz)
{
	int start = 0;
	int end = sz - 1;//这放的是数组下标，不是数组元素
	while (start<end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);//函数内部无法计算数组大小
	//Init(arr,sz);//初始化数组
	Print(arr, sz);//打印数组
	Reverse(arr, sz);//逆序数组
	Print(arr, sz);//打印数组
	return 0;
}
*/

//24.有关大小端存储
/*
#include<stdio.h>

int main()
{
	int a = 0x11223344;//大段存储，内存中44 33 22 11
	char *pc = (char)&a;
	*pc = 0;//将改为了0
	printf("%x\n", a);//输出时按正常顺序输出，应该为11223300
	return 0;
}
*/

//25.有关sizeof的进一步理解
/*
#include<stdio.h>

int i = 0;//全局变量和静态变量默认初始化为0，局部变量默认初始化为随机值

int main()
{
	i--;//-1
	if (i>sizeof(-1))//sizeof的返回值为无符号整型，-1参与运算时也会转化为无符号整型
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}
*/

//26.求二进制中1的个数(负数用补码表示)
/*
#include<stdio.h>

int Count1(int a)
{
	int count = 0;
	for (int i = 0; i<32; i++)
	{
		if ((a >> i) & 1 == 1)//按位与1，ke判断最后一个是否是1
			count++;
	}
	return count;
}

int Count2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);//使a的二进制形式的最右边一个数变成0
		count++;
	}
	return count;
}

int main()
{
	int a = 0, count = 0;
	scanf("%d", &a);
	count = Count1(a);
	printf("%d\n", count);
	count = Count2(a);
	printf("%d\n", count);
	return 0;
}
*/

/**/

//27.求int类型的m和n两个数的二进制形式有多少个bit位不同

//思路：异或相同为0，不同为1，再求异或的结果里有几个1
/*
#include<stdio.h>

int Count2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);//使a的二进制形式的最右边一个数变成0
		count++;
	}
	return count;
}

int main()
{
	int m = 0, n = 0, a = 0, count;//a为异或结果，count为1的个数即不同位个数
	scanf("%d %d", &m, &n);
	a = m^n;
	count = Count2(a);
	printf("%d", count);
	return 0;
}
*/

//28.获取一个数二进制形式的奇数位和偶数位并分别打印
/*
#include<stdio.h>

void print(int m)//实现打印奇数位和偶数位
{
	printf("打印奇数位：\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
	printf("\n");

	printf("打印偶数位：\n");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
}

int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}
*/

//29.使用指针打印数组内容
/*
#include<stdio.h>

void print(int *p, int sz);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}

void print(int *p, int sz)
{
	for (int i = 0; i<sz; i++)
	{
		printf("%d ", *(p + i));
	}
}
*/

//30.有关数组元素访问越界的问题(不理解）--《C陷阱和缺陷》
/*
#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//vc6.0环境下 <=10,死循环
	//gcc编译器 <=10,死循环
	//vs2013 <=12,死循环

	//若后创建变量i，也不会死循环（不理解）
	for (i = 0; i <= 12; i++)
	{
		printf("hh\n");
		arr[i] = 0;
	}
	system("pause");
	return 0;
}
*/

//31.模拟实现strcpy()函数

//多步优化版本
/*
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
*/

//截止到2023年10月18日

//32.写一段代码判断当前机器的字节序是什么(并封装为函数）

//思路：用char指针取出数字1的二进制形式第一个字节的内容，若为0，则为大段存储，若为1，则为小段存储
/*
#include<stdio.h>

int check_sys()
{
	int a = 1;
	
	return *(char*)&a;//取a地址的地址，但是用char类型接受，再解引用出来，就只能访问第一个字节的内容
}

int main()
{
	int i = check_sys();
	if (i == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
*/