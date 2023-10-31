#include<stdio.h>
#include<stdlib.h>

#define OK 1	//�ɹ���־
#define  ERROR 0	//ʧ�ܱ�־

typedef int Status;	//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int ElemType;	//ElemType�����͸���ʵ���������������ٶ�Ϊint

typedef struct LNode	//���嵥����������
{ 
	ElemType data; //������
	struct LNode *next; //ָ����
}LNode, *LinkList;	//LNode:�ṹ������;*LinkList:ָ��LNode���͵�ָ��

//������ĳ�ʼ��������һ����ͷ���ĵ�����
Status InitList_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode)); //����ͷ��㣬��ʹLָ��ͷ���
	(*L)->next = NULL;
	return 0;
}

//������Ĳ���
/*
��ʼ����:������L�Ѿ�����
�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e
*/
Status ListInsert_L(LinkList L, int i, ElemType e)
{
	int j = 0;
	LNode *p = L; //ָ��ͷ���	
	while (p && j<i - 1) //Ѱ�ҵ�i-1����㣬pָ��i-1���
	{
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)
		return ERROR;  //i���ڱ�+1��С��1������λ�÷Ƿ�
	LNode *s = (LNode*)malloc(sizeof(LNode));    //�½�һ��s��㣬Ҫ����Ľ��
	s->data = e; //�����½�㣬��������������Ϊe
	s->next = p->next;
	p->next = s; //˳�򲻿ɵߵ�
	return OK;
}


int main()
{
	int a = 1, i = 1;

	LinkList L;
	//���쵥����
	InitList_L(&L);
	ListInsert_L(&L, i, a);
	
}