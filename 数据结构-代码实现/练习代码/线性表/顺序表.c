#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20	//线性表初始分配量
#define OK 1	//成功标志
#define  ERROR 0	//失败标志

typedef int Status;	//Status 是函数的类型，其值是函数结果状态代码
typedef int ElemType;	//ElemType的类型根据实际情况而定，这里假定为int

//顺序表数据结构
typedef struct
{
	ElemType *elem;
	int length;
}SqList;

//函数声明
Status InitList_Sq(SqList *L);	//顺序表的初始化
void DestroyList_Sq(SqList* L);	//顺序表的销毁（销毁还存在问题）
void ClearList(SqList* L);	//清空顺序表
Status GetLength(SqList L);	//求顺序表长度
Status IsEmpty(SqList L);	//判断顺序表是否为空
Status ListInsert_Sq(SqList *L, int i, ElemType e);	//顺序表的插入
Status ListDelete_Sq(SqList *L, int i, ElemType *e);	//顺序表的删除
Status GetElem_Sq(SqList L, int i, ElemType *e);	//顺序表的取值
Status LocateElem(SqList L, ElemType e);	//顺序表的查找
void Output(SqList L);	//打印顺序表

int main()
{
	SqList L;

	printf("顺序表的初始化\n");
	InitList_Sq(&L);
	Output(L);  //打印结果

	int f = 1;	//用于跳出循环
	while (f)
	{
		printf("---------------------------------------------------------------------------\n");
		printf("请选择要进行的操作：\n");
		printf("1.插入数据	2.删除数据	3.判断顺序表是否为空	4.求顺序表长度	5.顺序表取值\n");
		printf("6.清空线性表	7.销毁线性表	8.线性表的查找		9.尾插建立顺序表	10.退出\n");

		int select = 0;
		int n = 0;
		int e = 0;
		int i = 0, m = 0;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
		{
				  printf("请输入插入的位置 i 及元素的值 m ：");
				  scanf("%d %d", &i, &m);
				  ListInsert_Sq(&L, i, m);
				  Output(L);  //打印结果
				  break;
		}			
		case 2:
		{
				  printf("请输入要删除的是第几个元素：");
				  i = 0;
				  scanf("%d", &i);
				  ListDelete_Sq(&L, i, &e);
				  Output(L);  //打印结果
				  printf("删除的数据为：%d\n", e);
				  break;
		}		
		case 3:
		{
				  int flag = IsEmpty(L);
				  if (flag == 1)
				  {
					  printf("顺序表为空\n");
				  }
				  else
				  {
					  printf("顺序表不为空\n");
				  }
				  break;
		}			
		case 4:
		{
				  int length = GetLength(L);
				  printf("顺序表长度为 %d\n", length);
				  break;
		}
		case 5:
		{
				  printf("请输入要获取第几位元素的值：");
				  i = 0;
				  scanf("%d", &i);
				  GetElem_Sq(L, i, &e);
				  printf("第 %d 位元素的值为 %d\n", i, e);
				  break;
		}		
		case 6:
			ClearList(&L);
			Output(L);  //打印结果
			break;
		case 7:
			DestroyList_Sq(&L);
			break;
		case 8:
		{
				  printf("请输入要查找元素的值：");
				  e = 0;
				  scanf("%d", &e);
				  i = LocateElem(L, e);
				  printf("值为 %d 的元素在顺序表中的位序为 %d\n", e, i);
				  break;
		}			
		case 9:
		{
				  printf("请输入要插入的元素个数：");			  
				  scanf("%d", &n);
				  for (int i = 1; i <= n; i++)
				  {
					  
					  printf("请输入第 i 个元素的值 m ：");
					  scanf("%d", &m);
					  ListInsert_Sq(&L, i, m);	//插入位置永远为length - 1前,即尾插
				  }
				  Output(L);  //打印结果
				  break;
		}		
		case 10:
			f = 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

//顺序表的初始化
Status InitList_Sq(SqList* L)
{
	L->elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));	//动态分配内存，创建头结点，初始分配的数组最大容量为MAXSIZE
	if (!L->elem)	//异常处理，检查存储空间是否分配成功
		return ERROR;
	L->length = 0;	//表中元素为0
	return OK;
}

//顺序表的销毁
void DestroyList_Sq(SqList* L)
{
	if (L->elem)	//如果数组不为空，则释放这块内存空间
		free(L->elem);
	L->length = 0;
	L->elem = NULL;
}

//清空顺序表
void ClearList(SqList* L)
{
	L->length = 0;  //将线性表长度置为0
}

//求顺序表长度
Status GetLength(SqList L)
{
	return L.length;
}

//判断顺序表是否为空
Status IsEmpty(SqList L)
{
	if (L.length == 0)
		return 1;  //若为空，则返回1
	return 0;
}

//顺序表的插入
/*
初始条件：顺序表已经存在
操作结果：在L中的第i个元素前插入新的数据元素e，表长加一
算法思想：
1.判断插入位置i是否合法(i<1||i>L.length+1)
2.判断顺序表的存储空间是否已满，若已满则返回ERROR
3.将第n至第i位的元素依次向后移动一个位置，空出第i个位置
4.将要插入的新元素放入第i个位置
*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1)	//eg:一共有10个元素(L->length=10)，插入在最后位置的话相当于插入在第11个元素之前，所以i最大只能为L->length+1，i的范围是1到11
		return ERROR;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i <= L->length)	//若插入位置不在表尾，要移动元素
	{
		for (int j = L->length - 1; j >= i - 1; j--)	//表中最后一个元素的下标为L->length-1
		{
			L->elem[j + 1] = L->elem[j];
		}
	}
	//若i = L->length + 1，即插入在表尾，则不需要移动元素
	L->elem[i - 1] = e;	//将新元素插入
	L->length++;	//表长加一
	return OK;
}

//顺序表的删除
/*
初始条件：顺序表已经存在
操作结果：删除L中的第i个元素，并用e返回其值，表长减一
算法思想：
1.判断顺序表是否为空，若为空返回ERROR
2.判断删除位置是否合法(1<i<n)
3.将第i+1至n位的元素依次向前移动一个位置
4.表长减一，返回OK
*/
Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	if (L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->elem[i - 1];
	if (i < L->length - 1)	//如果删除位置不在最后，需要移动元素
	{
		for (int j = i - 1; j <= L->length - 2; j++)
		{
			L->elem[j] = L->elem[j + 1];	//j + 1 的最大值为 L->length - 1
		}
	}
	//如果在最后(i == L->length - 1)，则只需要表长减一
	L->length--;	//表长减一
	return OK;
}

//顺序表取值（根须位置i获取相应位置数据元素的值，用e返回）
/*
初始条件：顺序表已经存在
操作结果：根须位置i获取相应位置数据元素的值，用e返回
*/
Status GetElem_Sq(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;  //判断i值是否合理，若不合理，返回ERROR
	*e = L.elem[i - 1];  //第i-1个单元存储着第i个数据
	return OK;
}

//顺序表的查找
/*
在线性表L中查找与指定值e相同的数据元素的位置
从表的一端开始，逐个进行记录的关键字和给定值的比较。找到，返回该元素的位置序号，未找到，则返回0
*/
Status LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i<L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;//eg:数组a[0]的位置序号是1
	}
	return 0;//未找到，返回0
}

//读取（打印）顺序表中所有元素
void Output(SqList L)
{
	printf("当前顺序表的长度为：%d\n", L.length);
	printf("当前顺序表的元素为：");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}
