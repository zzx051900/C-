#include<iostream>
#include<string>
using namespace std;
#define MAX 1000//�����Ƿ������ά������Ҫ�޸��������ʱ�ܷ���

//��ϵ�˽ṹ��
struct Person
{
	string name;//����
	int sex;//�Ա�
	int age;//����
	string phone;//�绰
	string addr;//סַ
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];
	int size;//ͨѶ¼�����������
};

//��������
void menu();//�˵�����
void addPerson(Addressbooks* abs);//�����ϵ��
void showPerson(Addressbooks* abs);//��ʾ��ϵ��
int isExist(Addressbooks* abs, string name); //�����ϵ���Ƿ����
void deletePerson(Addressbooks* abs);//ɾ����ϵ��
void findPerson(Addressbooks* abs);//������ϵ��
void modifyPerson(Addressbooks* abs);//�޸���ϵ��
void clearPerson(Addressbooks* abs);//�����ϵ��

int main()
{
	Addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.size = 0;//��ʼ��ͨѶ¼�е�ǰ��������
	int select = 0;//����û������ѡ��
	while (1)
	{
		menu();//���ò˵��������˳�ͨѶ¼��ÿ�����ܺ��������󶼻�ص���������ѭ�����˵������������
		cin >> select;//�û�����ѡ��
		switch (select)
		{
		case 1:
			addPerson(&abs);//�����ϵ��
			break;
		case 2:
			showPerson(&abs);//2.��ʾ��ϵ��
			break;
		case 3:
			deletePerson(&abs);//3.ɾ����ϵ��	
			break;
		case 4:
			findPerson(&abs);//4.������ϵ��
			break;
		case 5:
			modifyPerson(&abs);//5.�޸���ϵ��
			break;
		case 6:
			{
				cout << "��ȷ���Ƿ�Ҫ���ȫ����ϵ��\n 0 --- ȡ��\n 1 --- ȷ��" << endl;
				int cle = 0;
				cin >> cle;
				if (cle == 1)
				{
					clearPerson(&abs);//6.�����ϵ��
				}
				else
				{
					cout << "��ӭ�´�ʹ��" << endl;
					system("pause");//�����������
				}
				break;
			}
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");//�����������
			return 0;
			break;//0.�˳�ͨѶ¼
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

//�˵�����
void menu()
{
	cout << "*************************" << endl;
	cout << "******	1.�����ϵ��	******" << endl;
	cout << "******	2.��ʾ��ϵ��	******" << endl;
	cout << "******	3.ɾ����ϵ��	******" << endl;
	cout << "******	4.������ϵ��	******" << endl;
	cout << "******	5.�޸���ϵ��	******" << endl;
	cout << "******	6.�����ϵ��	******" << endl;
	cout << "******	0.�˳�ͨѶ¼	******" << endl;
	cout << "*************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//���ж�ͨѶ¼�Ƿ�����
	if (abs->size == MAX)
	{
		cout << "ͨѶ�������޷����" << endl;
		return;
	}
	//����
	cout << "����������" << endl;
	cin >> abs->personArray[abs->size].name;//����ķ��ʷ�ʽ�е��ɻ������±꼴Ϊ������ϵ�˸���
	//�Ա�
	cout << "�������Ա�" << endl;
	cout << "1 --- ��" << endl;
	cout << "2 --- Ů" << endl;
	while (1)//��Ҫѭ�������жϣ�ֱ��������ȷ(1��2��
	{
		int sex = 0;
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].sex = sex;
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	//����
	cout << "����������" << endl;
	while (1)//��Ҫѭ�������жϣ�ֱ��������ȷ(����0��С�ڵ���150��
	{
		int age = 0;
		cin >> age;
		if (age > 0 && age <= 150)
		{
			abs->personArray[abs->size].age = age;
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	//�绰
	cout << "������绰" << endl;
	cin >> abs->personArray[abs->size].phone;
	//��ͥסַ
	cout << "�������ͥסַ" << endl;
	cin >> abs->personArray[abs->size].addr;
	abs->size++;	//������ϵ��������1
	cout << "��ӳɹ�" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}

//��ʾ��ϵ��
void showPerson(Addressbooks* abs)//������ֵ���ݣ����˷ѿռ䣬�����õ�ַ���ݣ��ǲ�����const���θ��ã�
{
	if (abs->size == 0)
	{
		cout << "��¼Ϊ��" << endl;
	}
	for (int i = 0; i < abs->size; i++)
	{
		cout << "������" << abs->personArray[i].name << "\t";
		cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";//ʹ����һ��3Ŀ���������Ϊ1��������У���Ϊ1�������Ů
		cout << "���䣺" << abs->personArray[i].age << "\t";
		cout << "�绰��" << abs->personArray[i].phone << "\t";
		cout << "סַ��" << abs->personArray[i].addr << "\t";
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�����ϵ���Ƿ����
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i;//�ҵ��ˣ�������ϵ�������±�
		}
		return -1;//�������������û���ҵ����򷵻�-1
	}
}

//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//�����ϵ���Ƿ����
	int ret = isExist(abs, name);//�����abs�Ѿ���ָ�����ͣ�����Ҫ��ȡ��ַ
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//��Ҫɾ����ϵ�˺������ϵ����Ϣ����ǰ�ƣ������ϵ��������һ
		for (int i = ret; i < abs->size; i--)
		{
			abs->personArray[i] = abs->personArray[i + 1];//����ֱ�ӽ�������ϵ�˽ṹ�帳��ȥ
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�����ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "�ҵ��˸���ϵ�ˣ���Ϣ���£�" << endl;
		cout << "������" << abs->personArray[ret].name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";//ʹ����һ��3Ŀ���������Ϊ1��������У���Ϊ1�������Ů
		cout << "���䣺" << abs->personArray[ret].age << "\t";
		cout << "�绰��" << abs->personArray[ret].phone << "\t";
		cout << "סַ��" << abs->personArray[ret].addr << "\t";
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//�����ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//����
		cout << "�������޸ĺ������" << endl;
		cin >> abs->personArray[abs->size].name;//����ķ��ʷ�ʽ�е��ɻ������±꼴Ϊ������ϵ�˸���
		//�Ա�
		cout << "�������޸ĺ���Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		while (1)//��Ҫѭ�������жϣ�ֱ��������ȷ(1��2��
		{
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//����
		cout << "�������޸ĺ������" << endl;
		while (1)//��Ҫѭ�������жϣ�ֱ��������ȷ(����0��С�ڵ���150��
		{
			int age = 0;
			cin >> age;
			if (age > 0 && age <= 150)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//�绰
		cout << "�������޸ĺ�ĵ绰" << endl;
		cin >> abs->personArray[abs->size].phone;
		//��ͥסַ
		cout << "�������޸ĺ�ļ�ͥסַ" << endl;
		cin >> abs->personArray[abs->size].addr;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�����ϵ��
void clearPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}