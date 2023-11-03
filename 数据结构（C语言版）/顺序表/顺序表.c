#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20	//���Ա��ʼ������
#define OK 1	//�ɹ���־
#define  ERROR 0	//ʧ�ܱ�־

typedef int Status;	//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int ElemType;	//ElemType�����͸���ʵ���������������ٶ�Ϊint

//˳������ݽṹ
typedef struct
{
	ElemType *elem;
	int length;
}SqList;

//����һ���յ�˳���L
Status InitList_Sq(SqList *L)
{
	L->elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));	//��̬�����ڴ�
	if (!L->elem)	//�쳣�������洢�ռ��Ƿ����ɹ�
		return ERROR;
	L->length = 0;	//����Ԫ��Ϊ0
	return OK;
}

//˳���Ĳ���
/*
��ʼ������˳����Ѿ�����
�����������L�еĵ�i��Ԫ��ǰ�����µ�����Ԫ��e������һ
�㷨˼�룺1.�жϲ���λ��i�Ƿ�Ϸ�(i<1||i>L.length+1)
		 2.�ж�˳���Ĵ洢�ռ��Ƿ��������������򷵻�ERROR
		 3.����n����iλ��Ԫ����������ƶ�һ��λ�ã��ճ���i��λ��
		 4.��Ҫ�������Ԫ�ط����i��λ��
*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1)	//eg:һ����10��Ԫ��(L->length=10)�����������λ�õĻ��൱�ڲ����ڵ�11��Ԫ��֮ǰ������i���ֻ��ΪL->length+1
		return ERROR;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i <= L->length)	//������λ�ò��ڱ�β��Ҫ�ƶ�Ԫ��
	{
		for (int j = L->length - 1; j >= i - 1; j--)	//�������һ��Ԫ�ص��±�ΪL->length-1
		{
			L->elem[j + 1] = L->elem[j];
		}
	}
	L->elem[i - 1] = e;	//����Ԫ�ز���
	L->length++;	//����һ
	return OK;
}

//˳����ɾ��
/*
��ʼ������˳����Ѿ�����
���������ɾ��L�еĵ�i��Ԫ�أ�����e������ֵ������һ
�㷨˼�룺1.�ж�˳����Ƿ�Ϊ�գ���Ϊ�շ���ERROR
		 2.�ж�ɾ��λ���Ƿ�Ϸ�(1<i<n)
		 3.����i+1��nλ��Ԫ��������ǰ�ƶ�һ��λ��
		 4.����һ������OK
*/
Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	if (L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->elem[i - 1];
	if (i < L->length - 1)	//���ɾ��λ�ò��������Ҫ�ƶ�Ԫ�أ�����������ֻ��Ҫ����һ
	{
		for (int j = i - 1; j <= L->length - 2; j++)
		{
			L->elem[j] = L->elem[j + 1];
		}
	}
	L->length--;	//����һ
	return OK;
}

//˳���ȡֵ������λ��i��ȡ��Ӧλ������Ԫ�ص�ֵ����e���أ�
/*
��ʼ������˳����Ѿ�����
�������������λ��i��ȡ��Ӧλ������Ԫ�ص�ֵ����e����
*/
Status GetElem_Sq(SqList L, int i, ElemType *e)
{
	if (L.length==0 || i<1 || i>L.length)
		return ERROR;  //�ж�iֵ�Ƿ����������������ERROR
	*e = L.elem[i - 1];  //��i-1����Ԫ�洢�ŵ�i������
	return OK;
}

//��ȡ����ӡ��˳���������Ԫ��
void Output(SqList L)
{
	printf("��ǰ˳���ĳ���Ϊ��%d\n", L.length);
	printf("��ǰ˳����Ԫ��Ϊ��");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int main()
{
	SqList L;
	printf("------����һ���յ����Ա�L------\n");
	InitList_Sq(&L);
	Output(L);  //��ӡ���
	printf("------���Բ���10����------\n");
	for (int i = 1; i <= 10; i++){
		ListInsert_Sq(&L, i, i);
	}
	Output(L);  //��ӡ���
	printf("------�ڵ���λ֮ǰ����0------\n");
	ListInsert_Sq(&L, 3, 0);
	Output(L);  //��ӡ���
	printf("------ɾ����6λ������------\n");
	ElemType e;
	ListDelete_Sq(&L, 6, &e);
	printf("ɾ��������Ϊ��%d\n", e);
	Output(L);  //��ӡ���
	printf("------��ȡԪ�ز���------\n");
	GetElem_Sq(L, 5, &e);
	printf("�õ���5��Ԫ�أ�%d\n", e);
}
