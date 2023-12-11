#define _CRT_SECURE_NO_WARNINGS
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

//��������
Status InitList_Sq(SqList *L);	//˳���ĳ�ʼ��
void DestroyList_Sq(SqList* L);	//˳�������٣����ٻ��������⣩
void ClearList(SqList* L);	//���˳���
Status GetLength(SqList L);	//��˳�����
Status IsEmpty(SqList L);	//�ж�˳����Ƿ�Ϊ��
Status ListInsert_Sq(SqList *L, int i, ElemType e);	//˳���Ĳ���
Status ListDelete_Sq(SqList *L, int i, ElemType *e);	//˳����ɾ��
Status GetElem_Sq(SqList L, int i, ElemType *e);	//˳����ȡֵ
Status LocateElem(SqList L, ElemType e);	//˳���Ĳ���
void Output(SqList L);	//��ӡ˳���

int main()
{
	SqList L;

	printf("˳���ĳ�ʼ��\n");
	InitList_Sq(&L);
	Output(L);  //��ӡ���

	int f = 1;	//��������ѭ��
	while (f)
	{
		printf("---------------------------------------------------------------------------\n");
		printf("��ѡ��Ҫ���еĲ�����\n");
		printf("1.��������	2.ɾ������	3.�ж�˳����Ƿ�Ϊ��	4.��˳�����	5.˳���ȡֵ\n");
		printf("6.������Ա�	7.�������Ա�	8.���Ա�Ĳ���		9.β�彨��˳���	10.�˳�\n");

		int select = 0;
		int n = 0;
		int e = 0;
		int i = 0, m = 0;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
		{
				  printf("����������λ�� i ��Ԫ�ص�ֵ m ��");
				  scanf("%d %d", &i, &m);
				  ListInsert_Sq(&L, i, m);
				  Output(L);  //��ӡ���
				  break;
		}			
		case 2:
		{
				  printf("������Ҫɾ�����ǵڼ���Ԫ�أ�");
				  i = 0;
				  scanf("%d", &i);
				  ListDelete_Sq(&L, i, &e);
				  Output(L);  //��ӡ���
				  printf("ɾ��������Ϊ��%d\n", e);
				  break;
		}		
		case 3:
		{
				  int flag = IsEmpty(L);
				  if (flag == 1)
				  {
					  printf("˳���Ϊ��\n");
				  }
				  else
				  {
					  printf("˳���Ϊ��\n");
				  }
				  break;
		}			
		case 4:
		{
				  int length = GetLength(L);
				  printf("˳�����Ϊ %d\n", length);
				  break;
		}
		case 5:
		{
				  printf("������Ҫ��ȡ�ڼ�λԪ�ص�ֵ��");
				  i = 0;
				  scanf("%d", &i);
				  GetElem_Sq(L, i, &e);
				  printf("�� %d λԪ�ص�ֵΪ %d\n", i, e);
				  break;
		}		
		case 6:
			ClearList(&L);
			Output(L);  //��ӡ���
			break;
		case 7:
			DestroyList_Sq(&L);
			break;
		case 8:
		{
				  printf("������Ҫ����Ԫ�ص�ֵ��");
				  e = 0;
				  scanf("%d", &e);
				  i = LocateElem(L, e);
				  printf("ֵΪ %d ��Ԫ����˳����е�λ��Ϊ %d\n", e, i);
				  break;
		}			
		case 9:
		{
				  printf("������Ҫ�����Ԫ�ظ�����");			  
				  scanf("%d", &n);
				  for (int i = 1; i <= n; i++)
				  {
					  
					  printf("������� i ��Ԫ�ص�ֵ m ��");
					  scanf("%d", &m);
					  ListInsert_Sq(&L, i, m);	//����λ����ԶΪlength - 1ǰ,��β��
				  }
				  Output(L);  //��ӡ���
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

//˳���ĳ�ʼ��
Status InitList_Sq(SqList* L)
{
	L->elem = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));	//��̬�����ڴ棬����ͷ��㣬��ʼ����������������ΪMAXSIZE
	if (!L->elem)	//�쳣�������洢�ռ��Ƿ����ɹ�
		return ERROR;
	L->length = 0;	//����Ԫ��Ϊ0
	return OK;
}

//˳��������
void DestroyList_Sq(SqList* L)
{
	if (L->elem)	//������鲻Ϊ�գ����ͷ�����ڴ�ռ�
		free(L->elem);
	L->length = 0;
	L->elem = NULL;
}

//���˳���
void ClearList(SqList* L)
{
	L->length = 0;  //�����Ա�����Ϊ0
}

//��˳�����
Status GetLength(SqList L)
{
	return L.length;
}

//�ж�˳����Ƿ�Ϊ��
Status IsEmpty(SqList L)
{
	if (L.length == 0)
		return 1;  //��Ϊ�գ��򷵻�1
	return 0;
}

//˳���Ĳ���
/*
��ʼ������˳����Ѿ�����
�����������L�еĵ�i��Ԫ��ǰ�����µ�����Ԫ��e������һ
�㷨˼�룺
1.�жϲ���λ��i�Ƿ�Ϸ�(i<1||i>L.length+1)
2.�ж�˳���Ĵ洢�ռ��Ƿ��������������򷵻�ERROR
3.����n����iλ��Ԫ����������ƶ�һ��λ�ã��ճ���i��λ��
4.��Ҫ�������Ԫ�ط����i��λ��
*/
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1)	//eg:һ����10��Ԫ��(L->length=10)�����������λ�õĻ��൱�ڲ����ڵ�11��Ԫ��֮ǰ������i���ֻ��ΪL->length+1��i�ķ�Χ��1��11
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
	//��i = L->length + 1���������ڱ�β������Ҫ�ƶ�Ԫ��
	L->elem[i - 1] = e;	//����Ԫ�ز���
	L->length++;	//����һ
	return OK;
}

//˳����ɾ��
/*
��ʼ������˳����Ѿ�����
���������ɾ��L�еĵ�i��Ԫ�أ�����e������ֵ������һ
�㷨˼�룺
1.�ж�˳����Ƿ�Ϊ�գ���Ϊ�շ���ERROR
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
	if (i < L->length - 1)	//���ɾ��λ�ò��������Ҫ�ƶ�Ԫ��
	{
		for (int j = i - 1; j <= L->length - 2; j++)
		{
			L->elem[j] = L->elem[j + 1];	//j + 1 �����ֵΪ L->length - 1
		}
	}
	//��������(i == L->length - 1)����ֻ��Ҫ����һ
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
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;  //�ж�iֵ�Ƿ����������������ERROR
	*e = L.elem[i - 1];  //��i-1����Ԫ�洢�ŵ�i������
	return OK;
}

//˳���Ĳ���
/*
�����Ա�L�в�����ָ��ֵe��ͬ������Ԫ�ص�λ��
�ӱ��һ�˿�ʼ��������м�¼�Ĺؼ��ֺ͸���ֵ�ıȽϡ��ҵ������ظ�Ԫ�ص�λ����ţ�δ�ҵ����򷵻�0
*/
Status LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i<L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;//eg:����a[0]��λ�������1
	}
	return 0;//δ�ҵ�������0
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
