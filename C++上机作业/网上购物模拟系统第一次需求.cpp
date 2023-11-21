#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

const int Max_num = 100;

//������Ʒ�ṹ�壬����ID�����ơ�Ʒ�ơ��۸�����
struct item
{
	int id;
	string name;
	string brand;
	float price;
	int amount;
};

//�û��ṹ�壬�����û����ƣ��û����룬�ջ���ַ���û����ﳵ
struct user
{
	string name;
	string password;
	string address = "none";
	item shopping_car[Max_num];//���ﳵ����Ʒ�ṹ������ʵ��
	int shopping_car_num = 0; //���ﳵ����Ʒ����
};

//�½�һ������ϵͳ����
class Shopping
{
private:
	const string admin_ID = "id123456"; //����ԱID
	const string admin_passwd = "123456"; //����Ա����
	const char all_users_address[20] = "E:\\C++��ϰ\\�û�.txt"; //�û��б��ļ���ַ

public:
	user all_users[Max_num]; //�û��б����û��ṹ������ʵ��
	int user_num = 0; //�û��б�����

	void show();  //��ʾ������
	void users_enter(); //�û���¼����
	void users_register(); //�û�ע�����
	void administrator_enter(); //����Ա��¼����
	void admin_operate();//�������ҳ��
	void read_all_the_users();//��ȡ�û��б�
	void write_all_the_users();//д���û��б�
	void visit_items();//�û��鿴��Ʒ
	void user_operate(int index, user* this_user);//�û���������
};
	

int main() //��С������main����(bushi
{
	Shopping sp;
	sp.show();
	system("pause");
	return 0;
}

void Shopping::show()
{
	cout << "====================================================================================================" << endl;
	cout << "==================1.�û���¼     2.�û�ע��     3.����Ա��¼     4.�˳�ϵͳ     5.��ѯ��Ʒ============================" << endl;
	cout << "====================================================================================================" << endl;

	int n;
	cout << "���������" << endl;
	cin >> n;
	while (n != 4)
	{
		switch (n)
		{
		case 1:
			users_enter();//�û���¼
			break;
		case 2:
			users_register();//�û�ע��
			break;
		case 3:
			administrator_enter();//����Ա��¼
			break;
		case 5:
			visit_items();//��ѯ��Ʒ
		default:
			cout << "����������" << endl;
			break;
		}
		cout << "====================================================================================================" << endl;
		cout << "==================1.�û���¼     2.�û�ע��     3.����Ա��¼     4.�˳�ϵͳ============================" << endl;
		cout << "====================================================================================================" << endl;
		cout << "���������" << endl;
		cin >> n;
	}
	cout << "��ӭ�´�ʹ��" << endl;
}

//�û���¼���� ���ӹ��ܣ����������ʾ����������
void Shopping::users_enter()
{
	read_all_the_users(); //��ȡ�û��б�


	int cnt = 0;
	while (cnt < 3)
	{
		string name, passwd;
		cout << "�����û�����";
		cin >> name;
		cout << "�������룺";
		cin >> passwd;

		int i;
		for (i = 0; i < user_num; i++)
		{
			if (name == all_users[i].name && passwd == all_users[i].password)
			{
				cout << "*******" << endl;
				cout << "��¼�ɹ���" << endl;
				cout << "*******" << endl;
				user_operate(i, &all_users[i]); //�����û����û��б��е��±�ͽṹ��ָ��
				break;
			}
		}
		if (i < user_num)
			break;
		else if (i == user_num)
		{
			cnt++;
			cout << "�û���������������ٴ������û��������룬";
			cout << "�㻹��" << 3 - cnt << "�λ���" << endl;
		}
	}

	if (cnt == 3)
		cout << "��������Ѵ����ޣ�ϵͳ�رգ�" << endl;
}

//�û�ע����� ���ӹ��ܣ��Ѵ��ڵ��û�������̵����붼������Ҫ����Ҫ��������
void Shopping::users_register()
{
	read_all_the_users(); //��ȡ�û��б�

	string name, passwd;
	cout << "�����û�����";
	cin >> name;
	while (true)
	{
		int i;
		for (i = 0; i < user_num; i++)
		{
			if (all_users[i].name == name)
			{
				cout << "�û����Ѵ��ڣ����������룡" << endl;
				break;
			}
		}
		if (i == user_num) //�Ϸ����û���
			break;
		else if (i < user_num)
		{
			cout << "�����û�����";
			cin >> name;
		}
	}

	cout << "�������룺";
	cin >> passwd;
	while (passwd.size() <= 3)
	{
		cout << "���볤��̫�̣����������룡" << endl;
		cout << "�������룺";
		cin >> passwd;
	}

	//�½�һ���û�
	user_num++;
	all_users[user_num - 1].name = name;
	all_users[user_num - 1].password = passwd;
	all_users[user_num - 1].shopping_car_num = 0;
	


	write_all_the_users(); //д���û��б�

	//ע��ɹ�����¼
	cout << "***************" << endl;
	cout << "ע��ɹ�����¼�ɹ���" << endl;
	cout << "***************" << endl;
	user_operate(user_num - 1, &all_users[user_num - 1]);//�����û����û��б��е��±�ͽṹ��ָ��

}


//�û���ز���
//�û���������
void Shopping::user_operate(int index, user* this_user)
{
	cout << "=========================================================================================" << endl;
	cout << "1.ע����¼     2.�鿴��Ʒ     3.��Ʒ����     4.�����Ʒ�����ﳵ\033[0m" << endl;
	cout << "\033[33;1m5.ɾ�����ﳵ��Ʒ     6.�鿴���ﳵ     7.����     8.�޸�����	9.�����ջ���ַ\033[0m" << endl;
	cout << "���������";
	int n;
	cin >> n;
	
	while (n != 1)
	{
		switch (n)
		{
		case 2:
			visit_items();
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		default:
			cout << "\033[31;1m����Ĳ���ָ�\033[0m" << endl;
			break;
		}
		cout << "=========================================================================================" << endl;
		cout << "\033[33;1m1.ע����¼     2.�鿴��Ʒ     3.��Ʒ����     4.�����Ʒ�����ﳵ\033[0m" << endl;
		cout << "\033[33;1m5.ɾ�����ﳵ��Ʒ     6.�鿴���ﳵ     7.����     8.�޸�����	9.�����ջ���ַ\033[0m" << endl;
		cout << "���������" << endl;
		cin >> n;
	}
	cout << "�˳���¼��" << endl;
}

//����Ա��¼���� ���ӹ��ܣ����������ʾ����������
void Shopping::administrator_enter()
{

	int cnt = 0;
	while (cnt < 3)
	{
		cout << "�������ԱID��";
		string id, passwd;
		cin >> id;
		cout << "�������Ա���룺";
		cin >> passwd;
		if (id == admin_ID && passwd == admin_passwd)
		{
			cout << "*******" << endl;
			cout << "��¼�ɹ���" << endl;
			cout << "*******" << endl;
			admin_operate();
			break;
		}
		else
		{
			cnt++;
			cout << "ID������������ٴ��������ԱID�����룬";
			cout << "�㻹��" << 3 - cnt << "�λ���" << endl;
		}
	}
	if (cnt == 3)
		cout << "��������Ѵ����ޣ�ϵͳ�رգ�" << endl;
}

//����Ա��������
void Shopping::admin_operate()
{
	cout << "=========================================================================================" << endl;
	cout << "\033[33;1m0.ע����¼     1.��ѯ��Ʒ     2.������Ʒ     3.ɾ����Ʒ     4.�޸Ĳ�Ʒ����     5.��ѯ�ۻ��嵥\033[0m" << endl;
	cout << "���������";
	int n;
	cin >> n;
	while (n != 0)
	{
		switch (n)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		default:
			cout << "\033[31;1m����Ĳ���ָ�\033[0m" << endl;
			break;
		}
		cout << "=========================================================================================" << endl;
		cout << "\033[33;1m0.ע����¼     1.��ѯ��Ʒ     2.������Ʒ     3.ɾ����Ʒ     4.�޸Ĳ�Ʒ����     5.�ۻ��嵥\033[0m" << endl;
		cout << "���������" << endl;
		cin >> n;
	}
	cout << "�˳���¼��" << endl;
}


//��ȡ�û��б�
void Shopping::read_all_the_users()
{
	user_num = 0;//�Ƚ��û�������Ϊ0

	ifstream in_file(all_users_address, ios::in);
	if (in_file.is_open() == 0)
		cout << "���ļ�����" << endl;
	string a, b;
	in_file >> a >> b; //�����ļ���ͷ

	while (in_file.peek() != EOF)
	{
		in_file >> all_users[user_num].name;
		in_file >> all_users[user_num].password;
		if (all_users[user_num].name[0] >= 'a'&& all_users[user_num].name[0] <= 'z') //���ڹ���ļ���β�Ŀհ���
			user_num++;
	}
}

//д���û��б�
void Shopping::write_all_the_users()
{
	//���µ��û��б�д�����ļ�
	ofstream out_file(all_users_address, ios::out);
	out_file << "�û���\t" << "����\t\t" << endl;
	for (int i = 0; i < user_num; i++)
	{
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_users[i].name << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_users[i].password << "\t";
		out_file << endl;
	}
}

//�û��鿴��Ʒ���������ļ����ٰ�Ҫ�����
void Shopping::visit_items()
{

}