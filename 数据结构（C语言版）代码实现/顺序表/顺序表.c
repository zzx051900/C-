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

//构建一个空的顺序表L
Status InitList_Sq(SqList *L)
{
	L->elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));	//动态分配内存
	if (!L->elem)	//异常处理，检查存储空间是否分配成功
		return ERROR;
	L->length = 0;	//表中元素为0
	return OK;
}

//顺序表的插入
/*
初始条件：顺序表已经存在
操作结果：在L中的第i个元素前插入新的数据元素e，表长加一
算法思想：1.判断插入位置i是否合法(i<1||i>L.length+1)
		 2.判断顺序表的存储空间是否已满，若已满则返回ERROR
		 3.将第n至第i位的元素依次向后移动一个位置，空出第i个位置
		 4.将要插入的新元素放入第i个位置
*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1)	//eg:一共有10个元素(L->length=10)，插入在最后位置的话相当于插入在第11个元素之前，所以i最大只能为L->length+1
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
	L->elem[i - 1] = e;	//将新元素插入
	L->length++;	//表长加一
	return OK;
}

//顺序表的删除
/*
初始条件：顺序表已经存在
操作结果：删除L中的第i个元素，并用e返回其值，表长减一
算法思想：1.判断顺序表是否为空，若为空返回ERROR
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
	if (i < L->length - 1)	//如果删除位置不在最后，需要移动元素；如果在最后，则只需要表长减一
	{
		for (int j = i - 1; j <= L->length - 2; j++)
		{
			L->elem[j] = L->elem[j + 1];
		}
	}
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
	if (L.length==0 || i<1 || i>L.length)
		return ERROR;  //判断i值是否合理，若不合理，返回ERROR
	*e = L.elem[i - 1];  //第i-1个单元存储着第i个数据
	return OK;
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

int main()
{
	SqList L;
	printf("------构造一个空的线性表L------\n");
	InitList_Sq(&L);
	Output(L);  //打印结果
	printf("------测试插入10个数------\n");
	for (int i = 1; i <= 10; i++){
		ListInsert_Sq(&L, i, i);
	}
	Output(L);  //打印结果
	printf("------在第三位之前插入0------\n");
	ListInsert_Sq(&L, 3, 0);
	Output(L);  //打印结果
	printf("------删除第6位的数据------\n");
	ElemType e;
	ListDelete_Sq(&L, 6, &e);
	printf("删除的数据为：%d\n", e);
	Output(L);  //打印结果
	printf("------获取元素操作------\n");
	GetElem_Sq(L, 5, &e);
	printf("得到第5个元素：%d\n", e);
}
