//����ѧϰC���ԣ�����ϰ

//#define _CRT_SECURE_NO_WARNINGS   //������Ŀ�����и��ģ��ʲ�����Ҫ

/*
#include<stdio.h>
int main()
{

	return 0;
}
*/



//1.���Hello World
/*
#include<stdio.h>

int main()
{
	printf("hello world\n");
	return 0;
}
*/

//2.Ѱ�����Լ���������ư棩
/*
#include<stdio.h>

int main()
{
int m = 0, n = 0, r = 0;
scanf("%d %d", &m, &n);
while (m%n)//շת�������ѭ������Ϊȡģ��Ϊ��
{
r = m%n;
m = n;
n = r;
}
printf("%d\n", r);
return 0;
}
*/

//3.�ж�����
/*
#include<stdio.h>

int main()
{
int n = 0;
scanf("%d", &n);//�����׼��1.�ܱ�4�����Ҳ��ܱ�100���� 2.�ܱ�400����
if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
{
printf("%d������\n", n);
}
else
{
printf("%d��������\n", n);
}
return 0;
}
*/

//4.�ж��Ƿ�Ϊ�������Գ���)
/*
#include<stdio.h>

int main()
{
int n = 0, i = 2;			//nΪҪ�жϵ�������iΪ�Գ�����Ҫ��ѭ������
scanf("%d", &n);
for (i; i < n; i++)		    //��n����2��n-1������Ѱ���Ƿ��п�������������û����Ϊ����(Ч�ʽϵͣ�//(�Ż�������ֻ�жϵ���ƽ��n���ÿ⺯��sqrt()
{
if (n%i == 0)
break;
}
if (i == n)
{
printf("%dΪ����\n", n);
}
else
{
printf("%d��������\n", n);
}
return 0;
}
*/

//5.����1��100��һ�������ٸ�����9
/*
#include<stdio.h>

int main()
{
	int i = 0, count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)//����Ϊ9
			count++;
		if (i / 10 == 9)//ʮλ��Ϊ9
			count++;
	}
	printf("%d\n", count);
	return 0;
}
*/

//6.����1/1-1/2+1/3-1/4+1/5...+1/99-1/100��ֵ
/*
#include<stdio.h>
#include<math.h>
int main()
{
int i = 1, flag = 1;//flagΪ���ű�־
double sum = 0;
for (i = 1; i <= 100; i++)
{
flag = pow(-1, i + 1);//������2������Ϊ-1��i+1�η�����ƽ����ʽpow(a,b)
sum += flag*(1.0 / i);//Ҫ�õ��������ͣ�������ʱ����һ����ҪΪ�������ͣ�����д1.0
//flag = -flag;//(����1��flag�ĸ���ÿ�θպ÷�ת
}
printf("%lf\n", sum);
return 0;
}

*/

//7.С��Ϸ����������Ϸ
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
int ret = rand()%100+1;//����1~100�������
int guess = 0;//������Ҳµ����������
while (1)//��ѭ�������жϣ�ֱ���µ�Ϊֹ��ʹ��break����
{
printf("�������:>");
scanf("%d", &guess);
if (guess < ret)
{
printf("��С��\n");
}
else if (guess > ret)
{
printf("�´���\n");
}
else
{
printf("��ϲ�㣬�¶��ˣ�\n");
break;
}

}
}

void judge()//���ѡ���Ƿ�ʼ��Ϸ
{
int input = 0;//�������1��0��ѡ���Ƿ�ʼ��Ϸ
do//��Ϊ��������ִ��һ�Σ�����ѡ��do.while�ṹ
{
menu();//��ʾ����
printf("��ʼ��Ϸ�������Ϸ������1���˳���Ϸ������0>:");
scanf("%d", &input);
switch (input)
{
case 1:
game();//��������Ϸ����
break;
case 0:
printf("�˳���Ϸ\n");
break;
default:
printf("ѡ�����\n");
break;
}

} while (input);//����0ʱ�˳�������1������ֵʱ�����ٴ�ѡ��
}
int main()
{
srand((unsigned)time(NULL));//��ʼ�������������
judge();//���ѡ���Ƿ�ʼ��Ϸ
return 0;
}
*/

//8.�ж�����
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
//����������1��������������0
printf("%d\n", is_prime(m));
return 0;
}
*/

//9.дһ��������һ�����������в��Ҿ����ĳ����(�ҵ��Ļ�������������±꣬�Ҳ������ء�1)

//(ʹ�ö��ֲ���)
/*
#include<stdio.h>

int binary_search(int arr[], int k, int sz)
{
	int left = 0;//���±�
	int right = sz - 1;//���±�
	int mid = 0;//�м�Ԫ�ص��±�
	while (left <= right)//������С�ڵ��ڣ���Ϊ�����±����ʱҲҪ�ж�һ��
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
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//�������������飬���ܲ���������scanf���룬����������Ҫð������
	int k = 0;//������Ҫ���ҵ���
	int sz = sizeof(arr) / sizeof(arr[0]);//�ⶨ�����С
	int ret = 0;
	scanf("%d", &k);
	ret = binary_search(arr, k, sz);//���ֲ��ң����δ�����������׵�ַ��Ҫ���ҵ�Ԫ�أ����鳤�ȣ����鳤���޷��ں���������Ϊ�����е�arr��ָ�룩
	if (ret == -1)
	{
		printf("�Ҳ���ָ��Ԫ��");
	}
	else
	{
		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
	}
	return 0;
}
*/

//10.дһ��������ÿһ�ε��ú����ͻ���num��ֵ��һ

//����Ϊͨ�������޸��������е�ֵ������Ҫ�ô�ֵ���ã�
/*
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
*/

//11.������ݹ�

//����һ���޷������ͣ���˳���ӡ����ÿһλ(ʹ�õݹ飩
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

//12.��дһ���������ַ����ĳ���(����ʱ�����ķ������ǵݹ飩
/*
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
*/

//13.��дһ���������ַ����ĳ���

//(����ʱ�����ķ������ݹ鷽����
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

//14.��n�Ľ׳�

//���ֱ���ѭ���͵ݹ�ʵ�֣�
/*
#include<stdio.h>

int Fac1(int n)//��ѭ���ķ�����׳�
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int Fac2(int n)//�õݹ�ķ�����׳�
{
	if (n == 1)//�����ǵ��ڣ�ע��"����"��"==����һ��"=����ʾ��ֵ������
		return 1;
	return n*Fac2(n - 1);

}

int main()
{
	int n = 0;//n�Ľ׳�
	int ret = 0;//��Ž��
	scanf("%d", &n);
	ret = Fac1(n);
	printf("%d\n", ret);
	ret = Fac2(n);
	printf("%d\n", ret);
	return 0;
}
*/

//15.���n��쳲����������ݹ��ѭ����

//�����ݹ�ͬһ�����ᱻ�����ظ����㣬�˷���Դ��
//�ݹ��ѭ���������ڲ��ó�������������һ�־�һ����Զ�Ǻõķ���
/*
#include<stdio.h>

int Fib1(int n)//�ݹ�
{
	if (n <= 2)
		return 1;
	if (n>2)
		return Fib1(n - 1) + Fib1(n - 2);
}

int Fib2(int n)//ѭ�������Ա�������ظ�
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
	int n = 0;//���n��쳲�������
	int ret = 0;
	scanf("%d", &n);
	ret = Fib1(n);
	printf("%d\n", ret);
	ret = Fib2(n);
	printf("%d\n", ret);
	for (int i = 1; i <= 10; i++)///�����1~10��쳲�������
	{
		printf("%d\t", Fib1(i));
	}

	return 0;
}
*/

//16.����sizeof��strlen������
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

//17.ð������(����

//��һ��ð��������һ��Ԫ�س���������λ�ã�
/*
#include<stdio.h>

void bubble_sort(int arr[], int sz)//���棬δ�Ż�
{
	int i = 0;//�������ѭ������ʾ����
	int j = 0;//�����ڲ�ѭ������ʾ�ڼ�����
	int tmp = 0;//���ڽ���Ԫ��
	for (i = 0; i<sz - 1; i++)//n��Ԫ����Ҫn��1��ѭ��
	{
		for (j = 0; j<sz - 1 - i; j++)//ÿ��ѭ����Ҫ��ͷ��ʼ����Ҫ��j��0
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
//�Ż��汾�����һ��ѭ�����Ƿ�����Ԫ�ؽ���
//���û��Ԫ�ؽ���˵�������Ѿ�����ֱ������ѭ��
{
	int i = 0;//�������ѭ������ʾ����
	int j = 0;//�����ڲ�ѭ������ʾ�ڼ�����
	int tmp = 0;//���ڽ���Ԫ��
	int flag = 1;//���ڼ���Ƿ���Ԫ�ؽ����ı�־
	for (i = 0; i<sz - 1; i++)//n��Ԫ����Ҫn��1��ѭ��
	{
		for (j = 0; j<sz - 1 - i; j++)//ÿ��ѭ����Ҫ��ͷ��ʼ����Ҫ��j��0
		{
			if (arr[j]>arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//�������˽�������־��0,��ʾ����ѭ������
			}
		}
		if (flag == 1)//��ĳ�������flag��Ϊ1��˵��δ�����������Ѵ����������
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

//18.���Ծ�������Ϸ���궨���ں�����ʹ��ʱδ���в������ݣ�

//�ɸ������̴�С���������жϻ���ֻ���жϾ�����
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3//��������
#define COL 3//��������
//�к����Ѿ�Ԥ������ˣ�������ʹ��ʱ����Ҫ�����𣿣�

//��������
void menu();
void test();
void game();
void Displayboard(char board[ROW][COL]);
void Initboard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
char IsWin(char board[ROW][COL]);
int Full(char board[ROW][COL]);

void menu()//��ʾ�˵�
{
	printf("***********************\n");
	printf("*** 1.game  0.exit ****\n");
	printf("***********************\n");
}

void test()//ѡ���Ƿ������Ϸ���ٴν�����Ϸ
{
	int input = 0;
	do
	{
		menu();//�����ʾ�˵�
		printf("��ѡ���Ƿ�ʼ��Ϸ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸ����������������Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);//ֻ���������ֹͣ
}

void game()//��Ϸ������ʵ������
{
	char flag = '0';//���ڱ�ʾ��Ϸ״̬
	//'*'��ʾ���Ӯ��'#'��ʾ����Ӯ��'Q����ʾƽ�֣�'C����ʾ����
	char board[ROW][COL] = { 0 }; //���飬���������Ϣ//ʹ��Ԥ����ROW��COL��������޸��������д�С
	Initboard(board);//���̳�ʼ��
	Displayboard(board);//��ӡ����(���ε�ʱ�򴫵�����������ʵ���У�ʵ���У�
	//��ʽ����
	while (1)
	{
		//�����
		PlayerMove(board);
		Displayboard(board);
		flag = IsWin(board);//�ж���Ӯ
		if (flag != 'C')//����ж������Ѿ���Ϊ'C'����ֱ������
		{
			break;
		}
		//������
		ComputerMove(board);
		Displayboard(board);
		flag = IsWin(board);//�ж���Ӯ
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("���Ӯ\n\n");
	}
	else if (flag == '#')
	{
		printf("����Ӯ\n\n");
	}
	else if (flag == 'Q')
	{
		printf("ƽ��\n\n");
	}
}

//��������״̬
// a | a | a 
//---|---|---
// a | a | a 
//---|---|---
// a | a | a 

void Initboard(char board[ROW][COL])//���������ʼ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COL; j++)
		{
			board[i][j] = ' ';//��ʼ��ÿ��Ԫ��һ���ո�
		}
	}
}

void Displayboard(char board[ROW][COL])//��ӡ����,����Ϊһ��3��3�����̣�һ���β��У�һ���β���
{
	for (int i = 0; i<ROW; i++)//���ѭ����ѭ����,
	{
		//��ӡһ�е�����
		for (int j = 0; j<COL - 1; j++)//�ڲ�ѭ����ѭ���У�ǰCOL��1��Ԫ��
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %c \n", board[i][COL - 1]);//ÿһ�����һ��Ԫ��
		//��ӡ�ָ���(��ROW-1�в���Ҫ�ָ��У�
		if (i<ROW - 1)
		{
			for (int j = 0; j<COL - 1; j++)//�ڲ�ѭ����ѭ���У�ǰCOL��1��Ԫ��
			{
				printf("---|");
			}
			printf("---\n");//�ָ��е�ÿһ�����һ��Ԫ��
		}
	}
}

void PlayerMove(char board[ROW][COL])//�������
{
	int i = 0;
	int j = 0;
	printf("�����:>\n");
	while (1)//ѭ���жϣ�ֱ�����������ȷ
	{
		printf("���������\n");
		scanf("%d %d", &i, &j);//����������ӵ�����//Ĭ�������Ϊ����ӣ�1��1����ʼ
		if (i >= 1 && i <= ROW&&j >= 1 && j <= COL&&board[i - 1][j - 1] == ' ')//���λ���ǿո񣬴����������
		{
			board[i - 1][j - 1] = '*';//���������*��ʾ
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL])//�������ӣ�Ϊ�������
{
	int i = 0;
	int j = 0;
	printf("������:>\n");
	while (1)//ѭ���жϣ�ֱ�����������������ȷ
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (board[i][j] == ' ')//�����������ɵ��±���������±꣬���ø���
		{
			board[i][j] = '#';//����������#��ʾ
			break;
		}
	}
}

int Full(char board[ROW][COL])//�ж������Ƿ�����
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

char IsWin(char board[ROW][COL])//�жϾ���
{
	for (int i = 0; i<ROW; i++)//�ж����Ƿ���������
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int j = 0; j<COL; j++)//�ж����Ƿ���������
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�ж϶Խ����Ƿ���������
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	//���Բ�����     
	if (Full(board) == 1)//��������������Ϊ����˵��ƽ��
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
	srand((unsigned int)time(NULL));//��ʼ�������������
	test();///��ʼ����
	return 0;
}
*/

//19.��������ֵ����������ʱ����
/*
#include<stdio.h>

int main()
{
	//����a��b��ֵ
	int a = 5;
	int b = 3;
	printf("a=%d b=%d\n", a, b);
	//����һ��������ʱ����
	int tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);

	//���������Ӽ��������ܲ��������
	a = a + b;//8,3
	b = a - b;//8,5
	a = a - b;//3,5
	printf("a=%d b=%d\n", a, b);

	//���������׻򷨣�������������
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	return 0;
}
*/

//20.��һ�������洢���ڴ��еĶ���������1�ĸ���(ʹ�ð�λ��&��

//(�������ڴ����ò���洢��
/*
#include<stdio.h>

int main()
{
	int num = 0;
	int count;//1�ĸ���
	scanf("%d", &num);
	//һ������������λ��1�����Ϊ1˵��ĩβΪ1�����Ϊ0˵��ĩβ��0
	for (int i = 0; i<32; i++)
	{
		if ((num >> i) & 1 == 1)//��Ҫ����λ�ƶ������λ
			count++;
	}
	printf("%d", count);
	return 0;
}
*/

//21.ָ�����
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

//22.ģ��ʵ��strlen()��ʹ��ָ����������Ϊ�м�Ԫ�ظ�����
/*
#include<stdio.h>

int my_strlen(char* arr)
{
	char* start = arr;
	char* end = arr;
	while (*end != '\0')//����ʹ�õ���ָ��endָ����ַ���Ҫ������
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

//23.���������

//1��ʵ�ֺ���Init�����������ʼ��Ϊ0
//2��ʵ�ֺ���Print������ӡ����ÿ��Ԫ��
//3��ʵ�ֺ���Reverse�����������Ԫ������
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
	int end = sz - 1;//��ŵ��������±꣬��������Ԫ��
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
	int sz = sizeof(arr) / sizeof(arr[0]);//�����ڲ��޷����������С
	//Init(arr,sz);//��ʼ������
	Print(arr, sz);//��ӡ����
	Reverse(arr, sz);//��������
	Print(arr, sz);//��ӡ����
	return 0;
}
*/

//24.�йش�С�˴洢
/*
#include<stdio.h>

int main()
{
	int a = 0x11223344;//��δ洢���ڴ���44 33 22 11
	char *pc = (char)&a;
	*pc = 0;//����Ϊ��0
	printf("%x\n", a);//���ʱ������˳�������Ӧ��Ϊ11223300
	return 0;
}
*/

//25.�й�sizeof�Ľ�һ�����
/*
#include<stdio.h>

int i = 0;//ȫ�ֱ����;�̬����Ĭ�ϳ�ʼ��Ϊ0���ֲ�����Ĭ�ϳ�ʼ��Ϊ���ֵ

int main()
{
	i--;//-1
	if (i>sizeof(-1))//sizeof�ķ���ֵΪ�޷������ͣ�-1��������ʱҲ��ת��Ϊ�޷�������
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

//26.���������1�ĸ���(�����ò����ʾ)
/*
#include<stdio.h>

int Count1(int a)
{
	int count = 0;
	for (int i = 0; i<32; i++)
	{
		if ((a >> i) & 1 == 1)//��λ��1��ke�ж����һ���Ƿ���1
			count++;
	}
	return count;
}

int Count2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);//ʹa�Ķ�������ʽ�����ұ�һ�������0
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

//27.��int���͵�m��n�������Ķ�������ʽ�ж��ٸ�bitλ��ͬ

//˼·�������ͬΪ0����ͬΪ1���������Ľ�����м���1
/*
#include<stdio.h>

int Count2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);//ʹa�Ķ�������ʽ�����ұ�һ�������0
		count++;
	}
	return count;
}

int main()
{
	int m = 0, n = 0, a = 0, count;//aΪ�������countΪ1�ĸ�������ͬλ����
	scanf("%d %d", &m, &n);
	a = m^n;
	count = Count2(a);
	printf("%d", count);
	return 0;
}
*/

//28.��ȡһ������������ʽ������λ��ż��λ���ֱ��ӡ
/*
#include<stdio.h>

void print(int m)//ʵ�ִ�ӡ����λ��ż��λ
{
	printf("��ӡ����λ��\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
	printf("\n");

	printf("��ӡż��λ��\n");
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

//29.ʹ��ָ���ӡ��������
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

//30.�й�����Ԫ�ط���Խ�������(����⣩--��C�����ȱ�ݡ�
/*
#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//vc6.0������ <=10,��ѭ��
	//gcc������ <=10,��ѭ��
	//vs2013 <=12,��ѭ��

	//���󴴽�����i��Ҳ������ѭ��������⣩
	for (i = 0; i <= 12; i++)
	{
		printf("hh\n");
		arr[i] = 0;
	}
	system("pause");
	return 0;
}
*/

//31.ģ��ʵ��strcpy()����

//�ಽ�Ż��汾
/*
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
*/

//��ֹ��2023��10��18��

//32.дһ�δ����жϵ�ǰ�������ֽ�����ʲô(����װΪ������

//˼·����charָ��ȡ������1�Ķ�������ʽ��һ���ֽڵ����ݣ���Ϊ0����Ϊ��δ洢����Ϊ1����ΪС�δ洢
/*
#include<stdio.h>

int check_sys()
{
	int a = 1;
	
	return *(char*)&a;//ȡa��ַ�ĵ�ַ��������char���ͽ��ܣ��ٽ����ó�������ֻ�ܷ��ʵ�һ���ֽڵ�����
}

int main()
{
	int i = check_sys();
	if (i == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}
*/