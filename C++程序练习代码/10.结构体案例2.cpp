/*
����������
- ���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�
- �����ṹ�����飬���5��Ӣ��
- ͨ��ð�����򣬽������е�Ӣ�۰���������������������մ�ӡ�����Ľ��
*/
#include<iostream>
#include<string>
using namespace std;


// Ӣ�۵Ľṹ��
struct Hero
{
	string name;
	int age;
	string sex;
};

//��ӡ����Ӣ�۵���Ϣ
void printInfo(struct Hero heroArray[], int sz)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Ӣ������:" << heroArray[i].name << " ���䣺" << heroArray[i].age << " �Ա�" << heroArray[i].sex << endl;
	}
	cout << endl;
}

//ð������
void bubblesort(struct Hero heroArray[], int sz)
{
	struct Hero temp;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (heroArray[j].age > heroArray[j + 1].age)//�������������ṹ���������ֻ�ǽ�������
			{
				temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

int main()
{
	//����5��Ӣ�۵�����
	struct Hero heroArray[5] =
	{
		{ "aaa", 20, "��" },
		{ "bbb", 18, "Ů" },
		{ "ccc", 26, "��" },
		{ "ddd", 24, "��" },
		{ "eee", 19, "Ů" },
	};

	int sz = sizeof(heroArray) / sizeof(heroArray[0]);
	//��ӡ����ǰ����Ӣ�۵���Ϣ
	printInfo(heroArray, sz);

	//ð������
	bubblesort(heroArray, sz);

	//��ӡ���������Ӣ�۵���Ϣ
	printInfo(heroArray, sz);

	system("pause");
	return 0;
}
