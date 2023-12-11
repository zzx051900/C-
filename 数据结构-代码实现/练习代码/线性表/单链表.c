#define _CRT_SECURE_NO_WARNINGS 1

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

//��������
Status InitList_L(LinkList *L);	//������ĳ�ʼ��
Status ListInsert_L(LinkList L, int i, ElemType e);	//������Ĳ���
int Empty(LinkList L);	//�жϵ������Ƿ�Ϊ��
Status DestoryList_L(LinkList *L);	//���ٵ�����
Status ClearList_L(LinkList L);	//����������
int ListLength_L(LinkList L);	//������ı�
Status GetElem(LinkList L, int i, ElemType *e);	//�������ȡֵ->��λ����
LNode *LocateElem_Ad(LinkList L, ElemType e);	//������Ĳ���->��ֵ����->���ص�ַ
int LocateElem_Num(LinkList L, ElemType e);	//������Ĳ���->��ֵ����->�������
Status ListDelete_L(LinkList L, int i, ElemType *e);	//���������ɾ��
Status CreateList_H(LinkList *L, int n);	//������Ĵ�����ͷ�巨��
Status CreateList_R(LinkList *L, int n);	//������Ĵ�����β�巨��
Status ListTraverse(LinkList L);	//������ӡ����

int main()
{
	LinkList L = NULL;

	int a = 0;//a�����жϺ����Ƿ�ִ�гɹ�
	int n = 0;//n��ʾҪ���������Ԫ�ظ���
	int i = 0;//i��ʾҪ����Ԫ�ص�λ��
	int e = 0;//e��ʾҪ����Ԫ�ص�����
	int m = 0;//m��ʾ����Ԫ�ص����
	int f = 1;	//��������ѭ��
	int select = 0;	//�����û�����ѡ��
	int length = 0;

	while (f)
	{
		printf("---------------------------------------------------------------------------\n");
		printf("��ѡ��Ҫ���еĲ�����\n");
		printf("1.ͷ�巨��������	2.β�巨��������	3.������Ĳ���	4.�������ɾ��	5.�������ȡֵ\n");
		printf("6.���ҷ��ص�ַ		7.���ҷ������		8.����������	9.�жϵ������Ƿ�Ϊ��\n");
		printf("10.�������		11.���ٵ�����		12.�˳�		13.������ĳ�ʼ��\n");

		scanf("%d", &select);
		switch (select)
		{
		case 1:
		{
				  //ͷ�巨��������
				  printf("������ͷ�巨���������Ԫ�ظ�����");
				  scanf("%d", &n);
				  CreateList_H(&L, n);
				  ListTraverse(L);
				  break;
		}		
		case 2:
		{
				  //β�巨��������
				  printf("������ͷ�巨���������Ԫ�ظ�����");
				  scanf("%d", &n);
				  CreateList_R(&L, n);
				  ListTraverse(L);
				  break;
		}		
		case 3:
		{
				  printf("������Ҫ�����λ�� i ������Ԫ�ص�ֵ e ��");
				  scanf("%d %d", &i, &e);
				  ListInsert_L(L, i,  e);
				  ListTraverse(L);
				  break;
		}
		case 4:
		{
				  printf("������Ҫɾ����Ԫ����� i ��");
				  scanf("%d", &i);
				  ListDelete_L(L, i, &e);
				  printf("ɾ�����ĵ� %d λԪ�ص� ֵΪ %d\n", i, e);
				  ListTraverse(L);
				  break;
		}
		case 5:
		{
				  printf("���������е�i��Ԫ�ص�ֵ��������i��ֵ��");
				  scanf("%d", &i);
				  GetElem(L, i, &e);
				  printf("��%dλԪ�ص�ֵΪ%d\n", i, e);
				  break;
		}
		case 6:
		{
				  printf("����������ֵΪe��Ԫ�صĵ�ַ��������e��ֵ��");
				  scanf("%d", &e);			  
				  printf("��һ��ֵΪ%d��Ԫ�صĵ�ַΪ%p\n", e, LocateElem_Ad(L,e));
				  break;
		}	
		case 7:
		{
				  printf("����������ֵΪe��Ԫ�ص���ţ���m���أ���������e��ֵ��");
				  scanf("%d", &e);
				  m = LocateElem_Num(L, e);
				  printf("��һ��ֵΪ%d��Ԫ�ص����Ϊ%d\n", e, m);
				  break;
		}			
		case 8:
		{
				  a = ClearList_L(L);	//��յ�����
				  if (a = 1)
					  printf("��յ�����ɹ�\n");
				  ListTraverse(L);
				  break;
		}
		case 9:
		{
				  a = Empty(L);
				  if (a == 1)
					  printf("������Ϊ�գ�\n");
				  else
					  printf("������Ϊ�գ�\n");
				  break;
		}
		case 10:
		{
				   length = ListLength_L(L);
				   printf("�������Ϊ��%d\n", length);
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
			printf("����������������룡/n");
			break;
		}
	}
	return 0;
}

//�������壺

//������ĳ�ʼ��������һ����ͷ���ĵ�����Ҫ�ö���ָ�룩
Status InitList_L(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode)); //����ͷ��㣬��ʹLָ��ͷ���
	if (!(*L)) // �洢����ʧ�� 
		return ERROR;
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
	LNode *p, *s;	//p����ѭ��������sΪ�²���Ľ��
	p = L; //ָ��ͷ���	
	while (p && j<i - 1) //Ѱ�ҵ�i-1����㣬pָ��i-1���	//ѭ��������ϣ���Ľ���� j = i-1 
	{
		p = p->next;
		j++;
	}	
	if (!p || j>i - 1)	//!p ѭ������������pָ���ʱ��δ�ҵ�����i��ֵ����
		return ERROR;  //j > i-1	i���ڱ�+1��С��1��i<=0��������λ�÷Ƿ�
	s = (LNode*)malloc(sizeof(LNode));    //�½�һ��s��㣬Ҫ����Ľ��
	s->data = e; //�����½�㣬��������������Ϊe
	s->next = p->next;
	p->next = s; //˳�򲻿ɵߵ�
	return OK;
}

//�жϵ������Ƿ�Ϊ��
/*��Ϊ�շ���1�����򷵻�0*/
int Empty(LinkList L)
{

	if (L->next == NULL)	//ͷ����next��Ϊ��
		return 1;
	return 0;
}

//���ٵ�����ʹ�ö���ָ�룩
/*�����������н�����ͷ��㶼�ͷŵ�*/
Status DestoryList_L(LinkList *L)
{
	LNode* p = *L;	//p��ʱָ��ͷ���
	//ע���ʱ����ֱ���ͷ�p����Ϊͷ����л��������һ���ĵ�ַ���ͷž��Ҳ�����һ�������
	while (*L)
	{
		*L = (*L)->next;
		free(p); //��һ���ͷż��ͷŵ�ͷ���
		p = *L;
	}
	return OK;
}

//����������
/*�����ͷ����н�㣬����ͷ���ָ��������Ϊ��*/
Status ClearList_L(LinkList L)
{
	LNode *p, *q;	//p����ָ����Ҫ�ͷŵĽ�㣬q������p�ͷ�֮ǰָ����һ��㣬��ʹp�ƶ�	
	//�����ٲ�ͬ���ǣ����ʱͷָ��L�����ƶ�������ʱLҪ�������ƶ����������ʱҪ����һ��ָ��
	p = L->next;	//pָ����Ԫ���
	while (p)
	{
		q = p->next;   //qָ����һ��㣬���潫Ҫ�ͷŽ���next��
		free(p);
		p = q;
	}
	L->next = NULL;	//����ͷź���Ҫ��ͷ����ָ�������ΪNULL���γɿձ�
	return OK;
}

//������ı�
int ListLength_L(LinkList L)
{
	LNode *p;   //����ָ���ͷ�������Ľ��
	int count = 0;
	p = L->next; //ָ����Ԫ���
	while (p)	//����ָ��㲻Ϊ��ʱ��count++���������һλ
	{
		count++;
		p = p->next;
	}
	return count;
}

//�������ȡֵ��Ҳ����λ���ң�
/*��λ���ң����������е�iλ�õ�Ԫ��*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	LNode *p = L->next;	//ָ����Ԫ���
	int j = 1;
	while (p && j<i) //���ɨ��ֱ��pָ���i��Ԫ��(j=i)�����ҵ��ˣ�����pΪ�գ�������û�ҵ���
	{
		p = p->next;
		++j;
	}
	if (!p || j>i) //j����i���������i�����Ϊ0����
		return ERROR;
	*e = p->data;
	return OK;
}

//������Ĳ��ң�Ҳ����ֵ���ң�
/*��ֵ���ң�����ָ�����ݻ�ȡ��һ�����������ڵ�λ��(��ַ�����)*/

//���ص�ַ:
LNode *LocateElem_Ad(LinkList L, ElemType e) //����ֵΪ�ṹ�����͵�ָ��
{
	LNode *p = L->next;
	while (p && p->data != e)	//���ɨ��ֱ��(p -> data == e)�����ҵ��ˣ�����pΪ�գ�������û�ҵ���
	{
		p = p->next;
	}
	return p;
}
//�������
int LocateElem_Num(LinkList L, ElemType e)
{
	LNode *p = L->next;
	int j = 1;
	while (p && (p->data != e))	//���ɨ��ֱ��(p -> data == e)�����ҵ��ˣ�����pΪ�գ�������û�ҵ���
	{
		p = p->next;
		j++;
	}//���û�ҵ�����pΪ��
	if (p)
		return j;	//p��Ϊ�գ�����j
	return 0;//����ʧ�ܷ���0
}

//���������ɾ��������e���ر�ɾ����Ԫ�����ݣ�
Status ListDelete_L(LinkList L, int i, ElemType *e)
{
	LNode *p = L; //ָ��ͷ���
	LNode *q;
	int j = 0;
	//Ѱ�ҵ�i-1����㣬�ҵ�i����㲻��Ϊ�� 
	//����ѭ��ʱ��j = i-1),��pָ��ɾԪ�ص�ǰһ����㣨���ҵ��ˣ�
	//��p->next == NULL ��ʱp�Ѿ�Ϊ���һ����㣨û�ҵ���
	while (p->next && j<i - 1) 
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j>i - 1) //p->next == NULL����i <= 0 //����Ҫɾ����㲻����
		return ERROR;
	q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = p->next->next;	//��Ҫ�ͷŽ���ǰ������next��ֱ��ָ���ͷŽ��ĺ�̽��
	*e = q->data; //���ɾ����������
	free(q);	//�ͷ�ɾ�����Ŀռ�
	return OK;
}

//������Ĵ�����ͷ�巨��β�巨��
/*ͷ�巨:����n��Ԫ�� ��Ԫ�ش�ͷ��ʼ���β���	,����Ԫ����Զ������ͷ������Ԫ���ǰ���൱��ͬʱ����˵�����ĳ�ʼ���͵�����Ĳ��룩*/
Status CreateList_H(LinkList *L, int n)
{
	LNode *p, *r;  //p����ָ���½��,rָ��ͷ���֮��ѭ������
	//����һ������ͷ���ĵ�������ָ������Ϊ��
	*L = (LinkList)malloc(sizeof(LNode));
	r = *L;
	r->next = NULL;	//ͷ����next��Ϊ�գ���ɳ�ʼ��
	//�������븳ֵ
	for (int i = n; i>0; i--)
	{
		p = (LNode *)malloc(sizeof(LNode)); //Ϊ�½�㶯̬�����ڴ�
		p->next = NULL;
		printf("�����������ĵ�%d��Ԫ�أ�", i);
		scanf("%d", &p->data);
		p->next = r->next;
		r->next = p;
	}
	return OK;

}

//β�巨
/*β�巨������������n��Ԫ�أ� Ԫ�ش�β�����ν���*/
Status CreateList_R(LinkList *L, int n)
{

	LNode *p, *r;//p����ָ���½��(��������)��rָ��β�����
	*L = (LinkList)malloc(sizeof(LNode));
	r = *L;  //�տ�ʼʱrָ��ͷ���
	r->next = NULL;
	for (int i = 1; i <= n; i++) {
		p = (LNode *)malloc(sizeof(LNode));   //ע�����ﲻҪ���ǽ�����ڴ涨��ΪNode��ָ������
		printf("�����������ĵ�%d��Ԫ�أ�", i);
		scanf("%d", &p->data);
		p->next = NULL;	//�½���next��Ϊ��
		r->next = p;
		r = r->next;	//βָ��ָ���µ�β�ӵ�
	}
	return OK;
}

//������ӡ����
Status ListTraverse(LinkList L) 
{
	LNode* p = L->next;	//ָ����Ԫ���
	printf("����������Ԫ��Ϊ�� ");
	if (!p)
	{
		printf("��ʱ����Ϊ��\n");
		return ERROR;//�����Ԫ��㲻���ڷ���0
	}		
	while (p) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
