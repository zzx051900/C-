/*
����������ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ���������£�
- ���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ��������ʦ��������һ�����5��ѧ����������Ϊ��Ա
- ѧ���ĳ�Ա�����������Է���
- ����������3����ʦ��ͨ��������ÿ����ʦ������ѧ����ֵ
- ���մ�ӡ����ʦ�����Լ���ʦ����ѧ��������
*/
//ʵ���˾�������
#include<iostream>
#include<string>
using namespace std;

//ѧ���Ľṹ��
struct Student
{
	string sName;
	int score;
};


// ��ʦ�Ľṹ��
struct Teacher
{
	string tName;
	struct Student sArray[5];
};

//��ֵ����,���ٿռ䲢��ֵ
void allocateSpace(struct Teacher tArray[], int sz)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < sz; i++)
	{

		cin >> tArray[i].tName;
		for (int j = 0; j < 5; j++)
		{
			cin >> tArray[i].sArray[j].sName;

			cin >> tArray[i].sArray[j].score;
		}
	}
}

//��ӡ������ʦ������ѧ������Ϣ
void printInfo(struct Teacher tArray[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << "��ʦ������" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tѧ������:" << tArray[i].sArray[j].sName << " ������" << tArray[i].sArray[j].score << endl;
		}
	}
	cout << endl;
}

int main()
{
	//����3����ʦ������
	struct Teacher tArray[3];

	//ͨ��������3����ʦ����Ϣ��ֵ��������ʦ������ѧ����Ϣ��ֵ
	int sz = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, sz);

	//��ӡ������ʦ������ѧ������Ϣ
	printInfo(tArray, sz);

	system("pause");
	return 0;
}
