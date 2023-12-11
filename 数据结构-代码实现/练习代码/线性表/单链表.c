#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define OK 1	//成功标志
#define  ERROR 0	//失败标志

typedef int Status;	//Status 是函数的类型，其值是函数结果状态代码
typedef int ElemType;	//ElemType的类型根据实际情况而定，这里假定为int

typedef struct LNode	//定义单链表结点类型
{ 
	ElemType data; //数据域
	struct LNode *next; //指针域
}LNode, *LinkList;	//LNode:结构体类型;*LinkList:指向LNode类型的指针

//函数声明
Status InitList_L(LinkList *L);	//单链表的初始化
Status ListInsert_L(LinkList L, int i, ElemType e);	//单链表的插入
int Empty(LinkList L);	//判断单链表是否为空
Status DestoryList_L(LinkList *L);	//销毁单链表
Status ClearList_L(LinkList L);	//单链表的清空
int ListLength_L(LinkList L);	//求单链表的表长
Status GetElem(LinkList L, int i, ElemType *e);	//单链表的取值->按位查找
LNode *LocateElem_Ad(LinkList L, ElemType e);	//单链表的查找->按值查找->返回地址
int LocateElem_Num(LinkList L, ElemType e);	//单链表的查找->按值查找->返回序号
Status ListDelete_L(LinkList L, int i, ElemType *e);	//单链表结点的删除
Status CreateList_H(LinkList *L, int n);	//单链表的创建（头插法）
Status CreateList_R(LinkList *L, int n);	//单链表的创建（尾插法）
Status ListTraverse(LinkList L);	//遍历打印链表

int main()
{
	LinkList L = NULL;

	int a = 0;//a用于判断函数是否执行成功
	int n = 0;//n表示要插入链表的元素个数
	int i = 0;//i表示要操作元素的位置
	int e = 0;//e表示要操作元素的内容
	int m = 0;//m表示查找元素的序号
	int f = 1;	//用于跳出循环
	int select = 0;	//用于用户输入选择
	int length = 0;

	while (f)
	{
		printf("---------------------------------------------------------------------------\n");
		printf("请选择要进行的操作：\n");
		printf("1.头插法建立链表	2.尾插法建立链表	3.单链表的插入	4.单链表的删除	5.单链表的取值\n");
		printf("6.查找返回地址		7.查找返回序号		8.单链表的清空	9.判断单链表是否为空\n");
		printf("10.求单链表表长		11.销毁单链表		12.退出		13.单链表的初始化\n");

		scanf("%d", &select);
		switch (select)
		{
		case 1:
		{
				  //头插法创建链表
				  printf("请输入头插法创建链表的元素个数：");
				  scanf("%d", &n);
				  CreateList_H(&L, n);
				  ListTraverse(L);
				  break;
		}		
		case 2:
		{
				  //尾插法创建链表
				  printf("请输入头插法创建链表的元素个数：");
				  scanf("%d", &n);
				  CreateList_R(&L, n);
				  ListTraverse(L);
				  break;
		}		
		case 3:
		{
				  printf("请输入要插入的位置 i 及插入元素的值 e ：");
				  scanf("%d %d", &i, &e);
				  ListInsert_L(L, i,  e);
				  ListTraverse(L);
				  break;
		}
		case 4:
		{
				  printf("请输入要删除的元素序号 i ：");
				  scanf("%d", &i);
				  ListDelete_L(L, i, &e);
				  printf("删除掉的第 %d 位元素的 值为 %d\n", i, e);
				  ListTraverse(L);
				  break;
		}
		case 5:
		{
				  printf("查找链表中第i个元素的值，请输入i的值：");
				  scanf("%d", &i);
				  GetElem(L, i, &e);
				  printf("第%d位元素的值为%d\n", i, e);
				  break;
		}
		case 6:
		{
				  printf("查找链表中值为e的元素的地址，请输入e的值：");
				  scanf("%d", &e);			  
				  printf("第一个值为%d的元素的地址为%p\n", e, LocateElem_Ad(L,e));
				  break;
		}	
		case 7:
		{
				  printf("查找链表中值为e的元素的序号（用m返回），请输入e的值：");
				  scanf("%d", &e);
				  m = LocateElem_Num(L, e);
				  printf("第一个值为%d的元素的序号为%d\n", e, m);
				  break;
		}			
		case 8:
		{
				  a = ClearList_L(L);	//清空单链表
				  if (a = 1)
					  printf("清空单链表成功\n");
				  ListTraverse(L);
				  break;
		}
		case 9:
		{
				  a = Empty(L);
				  if (a == 1)
					  printf("单链表为空！\n");
				  else
					  printf("单链表不为空！\n");
				  break;
		}
		case 10:
		{
				   length = ListLength_L(L);
				   printf("单链表表长为：%d\n", length);
				   break;
		}
		case 11:
		{
				   DestoryList_L(&L);
				   break;
		}
		case 12:
			f = 0;
			break;
		case 13:
			InitList_L(&L);
			break;
		default:
			printf("输入错误，请重新输入！/n");
			break;
		}
	}
	return 0;
}

//函数定义：

//单链表的初始化，构建一个带头结点的单链表（要用二级指针）
Status InitList_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode)); //生成头结点，并使L指向头结点
	if (!(*L)) // 存储分配失败 
		return ERROR;
	(*L)->next = NULL;
	return 0;
}

//单链表的插入
/*
初始条件:单链表L已经存在
操作结果，在L中第i个位置之前插入新的数据元素e
*/
Status ListInsert_L(LinkList L, int i, ElemType e)
{
	int j = 0;
	LNode *p, *s;	//p用于循环遍历，s为新插入的结点
	p = L; //指向头结点	
	while (p && j<i - 1) //寻找第i-1个结点，p指向i-1结点	//循环结束后希望的结果是 j = i-1 
	{
		p = p->next;
		j++;
	}	
	if (!p || j>i - 1)	//!p 循环遍历结束，p指向空时还未找到（即i的值过大）
		return ERROR;  //j > i-1	i大于表长+1或小于1（i<=0），插入位置非法
	s = (LNode*)malloc(sizeof(LNode));    //新建一个s结点，要插入的结点
	s->data = e; //生成新结点，将结点的数据域置为e
	s->next = p->next;
	p->next = s; //顺序不可颠倒
	return OK;
}

//判断单链表是否为空
/*若为空返回1，否则返回0*/
int Empty(LinkList L)
{

	if (L->next == NULL)	//头结点的next域为空
		return 1;
	return 0;
}

//销毁单链表（使用二级指针）
/*将链表中所有结点包括头结点都释放掉*/
Status DestoryList_L(LinkList *L)
{
	LNode* p = *L;	//p此时指向头结点
	//注意此时不能直接释放p，因为头结点中还存放着下一结点的地址，释放就找不到下一个结点了
	while (*L)
	{
		*L = (*L)->next;
		free(p); //第一次释放即释放掉头结点
		p = *L;
	}
	return OK;
}

//单链表的清空
/*依次释放所有结点，并将头结点指针域设置为空*/
Status ClearList_L(LinkList L)
{
	LNode *p, *q;	//p用于指向需要释放的结点，q用于在p释放之前指向下一结点，以使p移动	
	//与销毁不同的是：清空时头指针L不能移动，销毁时L要销毁且移动，所以清空时要多设一个指针
	p = L->next;	//p指向首元结点
	while (p)
	{
		q = p->next;   //q指向下一结点，保存将要释放结点的next域
		free(p);
		p = q;
	}
	L->next = NULL;	//结点释放后还需要将头结点的指针域更改为NULL，形成空表
	return OK;
}

//求单链表的表长
int ListLength_L(LinkList L)
{
	LNode *p;   //用于指向除头结点以外的结点
	int count = 0;
	p = L->next; //指向首元结点
	while (p)	//当所指结点不为空时，count++，并向后移一位
	{
		count++;
		p = p->next;
	}
	return count;
}

//单链表的取值（也即按位查找）
/*按位查找：返回链表中第i位置的元素*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	LNode *p = L->next;	//指向首元结点
	int j = 1;
	while (p && j<i) //向后扫描直到p指向第i个元素(j=i)（即找到了），或p为空（遍历完没找到）
	{
		p = p->next;
		++j;
	}
	if (!p || j>i) //j大于i的情况：如i传入的为0或负数
		return ERROR;
	*e = p->data;
	return OK;
}

//单链表的查找（也即按值查找）
/*按值查找：根据指定数据获取第一个该数据所在的位置(地址或序号)*/

//返回地址:
LNode *LocateElem_Ad(LinkList L, ElemType e) //返回值为结构体类型的指针
{
	LNode *p = L->next;
	while (p && p->data != e)	//向后扫描直到(p -> data == e)（即找到了），或p为空（遍历完没找到）
	{
		p = p->next;
	}
	return p;
}
//返回序号
int LocateElem_Num(LinkList L, ElemType e)
{
	LNode *p = L->next;
	int j = 1;
	while (p && (p->data != e))	//向后扫描直到(p -> data == e)（即找到了），或p为空（遍历完没找到）
	{
		p = p->next;
		j++;
	}//如果没找到，则p为空
	if (p)
		return j;	//p不为空，返回j
	return 0;//查找失败返回0
}

//单链表结点的删除（并用e返回被删结点的元素内容）
Status ListDelete_L(LinkList L, int i, ElemType *e)
{
	LNode *p = L; //指向头结点
	LNode *q;
	int j = 0;
	//寻找第i-1个结点，且第i个结点不能为空 
	//结束循环时（j = i-1),即p指向被删元素的前一个结点（即找到了）
	//或p->next == NULL 此时p已经为最后一个结点（没找到）
	while (p->next && j<i - 1) 
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j>i - 1) //p->next == NULL，或i <= 0 //代表要删除结点不存在
		return ERROR;
	q = p->next; //临时保存被删结点的地址以备释放
	p->next = p->next->next;	//令要释放结点的前驱结点的next域直接指向释放结点的后继结点
	*e = q->data; //存放删除结点的数据
	free(q);	//释放删除结点的空间
	return OK;
}

//单链表的创建（头插法和尾插法）
/*头插法:输入n个元素 ，元素从头开始依次插入	,即新元素永远插入在头结点后、首元结点前（相当于同时完成了单链表的初始化和单链表的插入）*/
Status CreateList_H(LinkList *L, int n)
{
	LNode *p, *r;  //p用于指向新结点,r指向头结点之后循环遍历
	//建立一个带有头结点的单链表并将指针域置为空
	*L = (LinkList)malloc(sizeof(LNode));
	r = *L;
	r->next = NULL;	//头结点的next域为空，完成初始化
	//结点添加与赋值
	for (int i = n; i>0; i--)
	{
		p = (LNode *)malloc(sizeof(LNode)); //为新结点动态分配内存
		p->next = NULL;
		printf("请输入该链表的第%d个元素：", i);
		scanf("%d", &p->data);
		p->next = r->next;
		r->next = p;
	}
	return OK;

}

//尾插法
/*尾插法创建链表：输入n个元素， 元素从尾部依次接入*/
Status CreateList_R(LinkList *L, int n)
{

	LNode *p, *r;//p用于指向新结点(待插入结点)，r指向尾部结点
	*L = (LinkList)malloc(sizeof(LNode));
	r = *L;  //刚开始时r指向头结点
	r->next = NULL;
	for (int i = 1; i <= n; i++) {
		p = (LNode *)malloc(sizeof(LNode));   //注意这里不要忘记将这块内存定义为Node的指针类型
		printf("请输入该链表的第%d个元素：", i);
		scanf("%d", &p->data);
		p->next = NULL;	//新结点的next域为空
		r->next = p;
		r = r->next;	//尾指针指向新的尾接点
	}
	return OK;
}

//遍历打印链表
Status ListTraverse(LinkList L) 
{
	LNode* p = L->next;	//指向首元结点
	printf("链表中所有元素为： ");
	if (!p)
	{
		printf("此时链表为空\n");
		return ERROR;//如果首元结点不存在返回0
	}		
	while (p) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
