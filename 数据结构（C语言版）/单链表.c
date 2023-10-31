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

//单链表的初始化，构建一个带头结点的单链表
Status InitList_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode)); //生成头结点，并使L指向头结点
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
	LNode *p = L; //指向头结点	
	while (p && j<i - 1) //寻找第i-1个结点，p指向i-1结点
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)
		return ERROR;  //i大于表长+1或小于1，插入位置非法
	LNode *s = (LNode*)malloc(sizeof(LNode));    //新建一个s结点，要插入的结点
	s->data = e; //生成新结点，将结点的数据域置为e
	s->next = p->next;
	p->next = s; //顺序不可颠倒
	return OK;
}


int main()
{
	int a = 1, i = 1;

	LinkList L;
	//构造单链表
	InitList_L(&L);
	ListInsert_L(&L, i, a);
	
}