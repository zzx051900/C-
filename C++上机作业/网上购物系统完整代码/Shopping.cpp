#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include"Shopping.h"
using namespace std;

Shopping::Shopping()
{
	char all_items_address[20] = "���.txt"; //����ļ���ַ
	char sales_list_address[20] = "�����嵥.txt"; //�ۻ��嵥�ļ���ַ
	char all_users_address[20] = "�û�.txt"; //�û��б��ļ���ַ
	char users_shopping_address[20] = "�ջ���ַ.txt"; //�û��ջ���ַ�ļ���ַ
}


//��ʾ������	��
void Shopping::show()
{
	cout << "===============================================================================================================" << endl;
	cout << "��ӭʹ�� ����ϵͳ" << "�������Ӧ����" << endl;
	cout << "===============================================================================================================" << endl;
	cout << "1.�û���¼		2.�û�ע��		3.����Ա��¼		4.�˳�ϵͳ		5.�û��鿴��Ʒ��Ϣ" << endl;
	int n;
	cout << "���������" << endl;
	cin >> n;
	while (n != 4)
	{
		switch (n)
		{
		case 1:
			users_enter();
			break;
		case 2:
			users_register();
			break;
		case 3:
			administrator_enter();
			break;
		case 5:
			Shopping::show_items();
			break;
		case 8:
			admin_operate(); //ֱ�ӵ������Ա�������debug
			break;
		case 9:
			user_operate(0, &all_users[0]);
			break;
		default:
			cout << "����Ĳ���ָ�" << endl;
			break;
		}
		cout << "===============================================================================================================" << endl;
		cout << "1.�û���¼		2.�û�ע��		3.����Ա��¼		4.�˳�ϵͳ		5.�û��鿴��Ʒ��Ϣ" << endl;
		cout << "===============================================================================================================" << endl;
		cout << "���������" << endl;
		cin >> n;
	}
	cout << "��ӭ�´�ʹ�ã�" << endl;
}

//�û���¼���� ��
void Shopping::users_enter()	//���ӹ��ܣ����������ʾ����������
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
			if ((name.compare(all_users[i].name) == 0) && (passwd.compare(all_users[i].password) == 0))
			{
				cout << "===========" << endl;
				cout << "��¼�ɹ���" << endl;
				cout << "===========" << endl;
				user_operate(i, &all_users[i]); //�����û����û��б��е��±�͸��û�����������
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

//�û�ע�����	��
void Shopping::users_register()	//���ӹ��ܣ��Ѵ��ڵ��û�������̵����붼������Ҫ����Ҫ��������
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

	all_users[user_num - 1].shopping_car_num = 0;	//���ﳵ����Ʒ��������
	write_shopping_car(&all_users[user_num - 1]); //�������ﳵ�ļ�


	write_all_the_users(); //д���û��б�

	//ע��ɹ�����¼
	cout << "=================*" << endl;
	cout << "ע��ɹ�����¼�ɹ���" << endl;
	cout << "=================*" << endl;
	user_operate(user_num - 1, &all_users[user_num - 1]);//�����û����û��б��е��±�ͽṹ��ָ��

}

//����Ա��¼���� ��
void Shopping::administrator_enter()	//���ӹ��ܣ����������ʾ����������
{

	int cnt = 0;
	while (cnt < 3)
	{
		cout << "�������ԱID��";
		string id, passwd;
		cin >> id;
		cout << "�������Ա���룺";
		cin >> passwd;
		if (((id.compare(admin_ID)) == 0) && ((passwd.compare(admin_passwd)) == 0))
		{
			cout << "=========" << endl;
			cout << "��¼�ɹ���" << endl;
			cout << "=========" << endl;
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


//�ļ���ز�����//��ȡ����ļ�	��
void Shopping::read_all_the_items()
{
	item_num = 0;//�Ƚ�������������Ϊ0

	ifstream in_file;
	in_file.open("���.txt", ios::in);

	if (!in_file.is_open())
		cout << "���ļ�����" << endl;
	string a, b, c, d, e;

	in_file >> a >> b >> c >> d >> e;//�����ļ���ͷ

	while (in_file >> all_items[item_num].id &&
		in_file >> all_items[item_num].name &&
		in_file >> all_items[item_num].brand &&
		in_file >> all_items[item_num].price &&
		in_file >> all_items[item_num].amount)//����������
	{
		item_num++;
	}
}

//д�����ļ�	��
void Shopping::write_all_the_items()
{
	//���µ���Ʒ��Ϣд�����ļ�
	ofstream out_file;
	out_file.open("���.txt", ios::out);

	out_file << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
	for (int i = 0; i < item_num; i++)
	{
		out_file << all_items[i].id << "\t"
			<< all_items[i].name << "\t"
			<< all_items[i].brand << "\t"
			<< all_items[i].price << "\t"
			<< all_items[i].amount << "\t" << endl;
	}
}

//��ȡ�ۻ��嵥
void Shopping::read_the_sales_list()
{
	sale_item_num = 0;//�Ƚ��ۻ��嵥������Ϊ0

	ifstream in_file;
	in_file.open("�����嵥.txt", ios::in);
	if (in_file.is_open() == 0)
		cout << "���ļ�����" << endl;
	string a, b, c, d, e, f;
	in_file >> a >> b >> c >> d >> e >> f; //�����ļ���ͷ

	while (in_file.peek() != EOF)
	{
		in_file >> all_sales[sale_item_num].id;
		in_file >> all_sales[sale_item_num].name;
		in_file >> all_sales[sale_item_num].brand;
		in_file >> all_sales[sale_item_num].price;
		in_file >> all_sales[sale_item_num].amount;
		in_file >> all_sales[sale_item_num].my_user;
		if (all_sales[sale_item_num].id == 'F') //���ڹ���ļ���β�Ŀհ���
			sale_item_num++;
	}
}

//д���ۻ��嵥
void Shopping::write_the_sales_list()
{
	//���µ��ۻ��嵥д���ļ�
	ofstream out_file;
	out_file.open("�����嵥.txt", ios::out);
	out_file << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
	for (int i = 0; i < sale_item_num; i++)
	{
		if (all_sales[i].id < 10)
			out_file << "0";
		out_file << all_sales[i].id << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_sales[i].name << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_sales[i].brand << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_sales[i].price << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_sales[i].amount << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_sales[i].my_user << "\t";
		out_file << endl;
	}
}

//��ȡ�û��б�	��
void Shopping::read_all_the_users()
{
	user_num = 0;//�Ƚ��û�������Ϊ0

	ifstream in_file;
	in_file.open("�û�.txt", ios::in);

	//�ļ������ڵ����
	if (in_file.is_open() == 0)
	{
		cout << "�ļ������ڣ�" << endl;
		in_file.close();
		return;
	}
	else
	{
		in_file.close();
	}

	in_file.open("�û�.txt", ios::in);
	string a, b;
	in_file >> a >> b; //�����ļ���ͷ
	//�ļ����ڣ�����¼Ϊ�յ����
	char ch;
	in_file >> ch;	//�����ļ��е�һ���ַ������ļ�Ϊ�գ���������EOF����������̫��⣩
	if (in_file.eof())	//�ж϶����Ƿ�ΪEOF�����ǣ���Ϊ��
	{
		cout << "�ļ�Ϊ�գ�" << endl;		
		in_file.close();
		return;
	}
	else
	{
		in_file.close();
	}

	//�ļ����ڣ��Ҵ�������
	in_file.open("�û�.txt", ios::in);
	in_file >> a >> b; //�����ļ���ͷ
	while (in_file >> all_users[user_num].name && in_file >> all_users[user_num].password)
	{
		user_num++;	//�û�����++
	}
	in_file.close();
}

//д���û��б�	��
void Shopping::write_all_the_users()
{
	//���µ��û��б�д�����ļ�
	ofstream out_file;
	out_file.open("�û�.txt", ios::out);
	out_file << "�û���\t" << "����\t" << endl;
	for (int i = 0; i < user_num; i++)
	{
		out_file << all_users[i].name << "\t"
			<< all_users[i].password << "\t" << endl;
	}
}

//��ȡ�ջ���ַ
void Shopping::read_shopping_address()
{
	read_all_the_users(); //�ȶ�ȡ�û��б�

	ifstream in_file;
	in_file.open("�ջ���ַ.txt", ios::in);
	if (in_file.is_open() == 0)
		cout << "���ļ�����" << endl;

	string a, b;
	in_file >> a >> b; //�����ļ���ͷ

	while (in_file.peek() != EOF)
	{
		string name, address;
		in_file >> name >> address;
		for (int i = 0; i < user_num; i++)
		if (name == all_users[i].name) //�ҵ����û�
			all_users[i].address = address; //�޸ĸ��û���ַ
	}
}

//д���ջ���ַ
void Shopping::write_shopping_address()
{
	read_all_the_users(); //�ȶ�ȡ�û��б�

	//���µ��ջ���ַд���ļ�
	ofstream out_file;
	out_file.open("�ջ���ַ.txt", ios::out);

	out_file << "�û���\t" << "�ջ���ַ\t\t" << endl;

	for (int i = 0; i < user_num; i++)
	{
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_users[i].name << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_users[i].address << "\t";
		out_file << endl;
	}
}

//��ȡ�û����ﳵ	��
void Shopping::read_shopping_car(user* this_user)
{
	this_user->shopping_car_num = 0;//�Ƚ����ﳵ��Ʒ������Ϊ0
	string shopping_car_address = this_user->name + ".txt";//���ù��ﳵ�ļ���ַ

	ifstream in_file;
	in_file.open(shopping_car_address, ios::in);

	if (in_file.is_open() == 0)
	{
		cout << "���ļ�����" << endl;
	}

	string a, b, c, d, e;
	in_file >> a >> b >> c >> d >> e; //�����ļ���ͷ

	while (in_file >> this_user->shopping_car[this_user->shopping_car_num].id &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].name &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].brand &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].price &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].amount) //����������
	{
		this_user->shopping_car_num++;
	}
}

//д���û����ﳵ	��
void Shopping::write_shopping_car(user* this_user)
{
	//���µ��û����ﳵд�����ļ�
	string shopping_car_address = this_user->name + ".txt"; //���ù��ﳵ�ļ���ַ
	ofstream out_file;
	out_file.open(shopping_car_address, ios::out);	//��д��ʽ��������
	out_file << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
	if (this_user->shopping_car_num != 0)
	{
		for (int i = 0; i < this_user->shopping_car_num; i++)
		{
			out_file << this_user->shopping_car[i].id << "\t"
				<< this_user->shopping_car[i].name << "\t"
				<< this_user->shopping_car[i].brand << "\t"
				<< this_user->shopping_car[i].price << "\t"
				<< this_user->shopping_car[i].amount << "\t" << endl;
		}
	}
}


//����Ա��ز�����	//����Ա��������	��
void Shopping::admin_operate()
{
	cout << "===============================================================================================================" << endl;
	cout << "0.ע����¼     1.��ѯ��Ʒ     2.������Ʒ     3.ɾ����Ʒ     4.�޸Ĳ�Ʒ��Ϣ     5.��ѯ�ۻ��嵥" << endl;
	cout << "===============================================================================================================" << endl;

	cout << "���������";
	int n;
	cin >> n;
	while (n != 0)
	{
		switch (n)
		{
		case 1:
			show_items();
			break;
		case 2:
			add_item();
			break;
		case 3:
			delete_item();
			break;
		case 4:
			change_item();
			break;
		case 5:
			show_sales_list();
			break;
		default:
			cout << "����Ĳ���ָ�" << endl;
			break;
		}
		cout << "===============================================================================================================" << endl;
		cout << "0.ע����¼     1.��ѯ��Ʒ     2.������Ʒ     3.ɾ����Ʒ     4.�޸Ĳ�Ʒ��Ϣ     5.��ѯ�ۻ��嵥" << endl;
		cout << "===============================================================================================================" << endl;

		cout << "���������";
		cin >> n;
	}
	cout << "�˳���¼��" << endl;
}

//����Ա�鿴��Ʒ	��
void Shopping::show_items()	//�ȶ������ļ����ٽ������
{
	read_all_the_items(); //�������ļ�

	//��������Ʒ���ݣ�����Ϊ0����ƷҲҪ���
	if (item_num == 0)
		cout << "��ǰ���Ϊ�գ�" << endl;

	else
	{
		cout << "==================================================" << endl;
		cout << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
		for (int i = 0; i < item_num; i++)
		{
			//��������Ʒ��Ϣ��ͨ������λ����Ʊ��ʵ�������˳��
			if (all_items[i].amount >= 0 || all_items[i].amount == -1)
			{
				cout << all_items[i].id << "\t";
				cout << all_items[i].name << "\t";
				cout << all_items[i].brand << "\t";
				cout << all_items[i].price << "\t";
				cout << all_items[i].amount << "\t" << endl;
			}
		}
		cout << "==================================================" << endl;
	}
}

//����Ա�����Ʒ	��
void Shopping::add_item()	//�ȶ������ļ����������Ʒ�����д�����ļ�
{
	read_all_the_items();

	cout << "������Ҫ��������ƷID��";

	int id;
	cin >> id;

	int i = 0;
	for (i = 0; i<item_num; i++)
	{
		if (all_items[i].id == id)
		{
			int n;
			cout << "��������Ʒ������Ϊ��";
			cin >> n;
			all_items[i].amount += n;
			cout << "�����ɹ�������Ʒ���ڵ�����Ϊ" << all_items[i].amount << endl;
			break;
		}
	}
	if (i == item_num && item_num<Max_num) //û���ҵ���Ӧ��ID���½�һ����Ʒ
	{
		item_num++; //��Ʒ������+1

		all_items[item_num - 1].id = id;

		cout << "�����û���ҵ���ӦID�����Զ��½�һ����Ʒ�����������Ʒ�����ƣ�";
		cin >> all_items[item_num - 1].name;
		cout << "���������Ʒ��Ʒ�ƣ�";
		cin >> all_items[item_num - 1].brand;
		cout << "���������Ʒ�ļ۸�";
		cin >> all_items[item_num - 1].price;
		cout << "���������Ʒ��������";
		cin >> all_items[item_num - 1].amount;
		cout << "��ӳɹ���" << endl;
	}

	//���µ���Ʒ��Ϣд�����ļ�
	write_all_the_items();
}

//����Աɾ����Ʒ	��
void Shopping::delete_item()	//�ȶ������ļ�����ɾ����Ʒ�����д�����ļ�
{
	read_all_the_items();

	cout << "������Ҫɾ������Ʒid��";
	int id;
	cin >> id;

	int i = 0;
	bool flag = false;	//���ڱ�־�Ƿ�ɾ���ɹ�
	for (i = 0; i < item_num; i++)
	{
		if (all_items[i].id == id)
		{
			//����ǰ�Ƹ���
			for (int j = i; j < item_num; j++)
			{
				all_items[j] = all_items[j + 1];
				item_num--;
				cout << "��Ʒɾ���ɹ���" << endl;
				flag = true;
				break;
			}
			break;
		}
	}
	if (flag == false) //û���ҵ���Ӧ��id
		cout << "û���ҵ���Ӧ����Ʒ��" << endl;

	//���µ���Ʒ��Ϣд�����ļ�
	write_all_the_items();
}

//����Ա�޸���Ʒ	��
void Shopping::change_item()	//�ȶ������ļ������޸���Ʒ��Ϣ�����д�����ļ�
{
	read_all_the_items();

	cout << "������Ҫ�޸ĵ���Ʒid��";
	int id;
	cin >> id;

	int i = 0;
	for (i = 0; i < item_num; i++)
	{
		if (all_items[i].id == id)
		{
			string str;

			cout << "�������޸ĺ�����ƣ�";
			cin >> str;
			all_items[i].name = str;
			cout << "�������޸ĺ��Ʒ�ƣ�";
			cin >> str;
			all_items[i].brand = str;
			cout << "�������޸ĺ�ļ۸�";
			float x;
			cin >> x;
			if (x < 0)
				cout << "�޸�ʧ�ܣ��۸���Ϊ����" << endl;
			else
				all_items[i].price = x;
			cout << "�������޸ĺ��������";
			int amt;
			cin >> amt;
			all_items[i].amount = amt;
			cout << "�޸ĳɹ���" << endl;
			break;
		}
	}
	if (i == item_num) //û���ҵ���Ӧ��id
		cout << "û���ҵ���Ӧ����Ʒ��" << endl;

	//���µ���Ʒ��Ϣд�����ļ�
	write_all_the_items();
}

//����Ա��ѯ�۳��嵥
void Shopping::show_sales_list()	//�ȶ��ļ����ٺϲ�ͬ��������ID�������
{
	read_the_sales_list(); //��ȡ�ۻ��嵥

	//����IDð������
	for (int i = 0; i < sale_item_num - 1; i++)
	{
		for (int j = 0; j < sale_item_num - i - 1; j++)
		{
			//��ǰ��ID���ں��ߣ��ṹ�����ݽ���
			if (all_sales[j].id > all_sales[j + 1].id)
			{
				int temp1 = all_sales[j].id;
				all_sales[j].id = all_sales[j + 1].id;
				all_sales[j + 1].id = temp1;

				char temp2 = all_sales[j].id;
				all_sales[j].id = all_sales[j + 1].id;
				all_sales[j + 1].id = temp2;

				string temp3 = all_sales[j].name;
				all_sales[j].name = all_sales[j + 1].name;
				all_sales[j + 1].name = temp3;

				string temp4 = all_sales[j].brand;
				all_sales[j].brand = all_sales[j + 1].brand;
				all_sales[j + 1].brand = temp4;

				float temp5 = all_sales[j].price;
				all_sales[j].price = all_sales[j + 1].price;
				all_sales[j + 1].price = temp5;

				int temp6 = all_sales[j].amount;
				all_sales[j].amount = all_sales[j + 1].amount;
				all_sales[j + 1].amount = temp6;

				string temp7 = all_sales[j].my_user;
				all_sales[j].my_user = all_sales[j + 1].my_user;
				all_sales[j + 1].my_user = temp7;
			}
		}
	}


	//�ϲ�ͬ���������ͬ����Ʒ�����������ۼӵ���һ����¼�У�������Ϊ-1
	for (int i = 0; i < sale_item_num - 1; i++)
	{
		if (all_sales[i].amount == -1)
			continue;
		for (int j = i + 1; j < sale_item_num; j++)
		{
			if (all_sales[j].amount == -1)
				continue;
			if (all_sales[i].id == all_sales[j].id && all_sales[i].name == all_sales[j].name && all_sales[i].brand == all_sales[j].brand && all_sales[i].price == all_sales[j].price)
			{
				all_sales[i].amount += all_sales[j].amount;
				all_sales[j].amount = -1;
			}
		}
	}
	if (sale_item_num == 0)
		cout << "��ǰ�ۻ��嵥Ϊ�գ�" << endl;

	else
	{
		cout << "********************************************************************************" << endl;
		cout << "id" << "		" << "����" << "		" << "Ʒ��" << "		" << "�۸�" << "		" << "��������" << endl;
		for (int i = 0; i < sale_item_num; i++)
		{
			//��������Ʒ��Ϣ��ͨ������λ����Ʊ��ʵ�������˳��
			if (all_sales[i].amount > 0)
			{
				if (all_sales[i].id < 10)
					cout << "0";
				cout << all_sales[i].id << "\t\t";
				cout.width(10);
				cout.setf(ios::left);
				cout << all_sales[i].name << "\t";
				cout.width(10);
				cout.setf(ios::left);
				cout << all_sales[i].brand << "\t";
				cout.width(10);
				cout.setf(ios::left);
				cout << all_sales[i].price << "\t";
				cout.width(10);
				cout.setf(ios::left);
				cout << all_sales[i].amount << "\t";
				cout << endl;
			}
		}
		cout << "********************************************************************************" << endl;
	}
}


//�û���ز�����//�û���������		��
void Shopping::user_operate(int index, user* this_user)
{
	cout << "===============================================================================================================" << endl;
	cout << "1.ע����¼     2.�鿴��Ʒ     3.��Ʒ����     4.�����Ʒ�����ﳵ	5.ɾ�����ﳵ��Ʒ" << endl;
	cout << "6.�鿴���ﳵ     7.����     8.�޸�����	9.�����ջ���ַ	10.�޸Ĺ��ﳵ��Ʒ����" << endl;
	cout << "===============================================================================================================" << endl;

	cout << "���������";
	int n;
	cin >> n;
	write_shopping_address();
	while (n != 1)
	{
		switch (n)
		{
		case 2:
			visit_items();
			break;
		case 3:
			search_item();
			break;
		case 4:
			add_shopping_car(index, this_user);
			break;
		case 5:
			delete_shopping_car(index, this_user);
			break;
		case 6:
			visit_shopping_car(index, this_user);
			break;
		case 7:
			check_out(index, this_user);
			break;
		case 8:
			change_password(index, this_user);
			break;
		case 9:
			change_address(index, this_user);
			break;
		case 10:
			change_shopping_car(index, this_user);
			break;
		default:
			cout << "����Ĳ���ָ�" << endl;
			break;
		}
		cout << "===============================================================================================================" << endl;
		cout << "1.ע����¼     2.�鿴��Ʒ     3.��Ʒ����     4.�����Ʒ�����ﳵ" << endl;
		cout << "5.ɾ�����ﳵ��Ʒ     6.�鿴���ﳵ     7.����     8.�޸�����	9.�����ջ���ַ" << endl;
		cout << "===============================================================================================================" << endl;
		cout << "���������" << endl;
		cin >> n;
	}
	cout << "�˳���¼��" << endl;
}

//�û��鿴��Ʒ	��
void Shopping::visit_items()	//�������ļ����ٰ�Ҫ�����
{
	read_all_the_items(); //�������ļ�

	//��������Ʒ���ݣ�����Ϊ0����Ʒ����Ҫ���
	if (item_num == 0)
	{
		cout << "��ǰ���Ϊ�գ�" << endl;
	}
	else
	{
		cout << "==================================================" << endl;
		cout << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
		for (int i = 0; i < item_num; i++)
		{
			if (all_items[i].amount >= 0 || all_items[i].amount == -1)
			{
				cout << all_items[i].id << "\t";

				cout << all_items[i].name << "\t";

				cout << all_items[i].brand << "\t";

				cout << all_items[i].price << "\t";

				cout << all_items[i].amount << "\t";
				cout << endl;
			}
		}
		cout << "==================================================" << endl;
	}
}

//�û�������Ʒ 
void Shopping::search_item()	//��չ���ܣ���ѡ������+Ʒ�Ƶ�������ʽ
{
	read_all_the_items(); //��ȡ���

	int flag = 0; //��ʾ�����Ƿ�ɹ�
	cout << "��������Ʒ���ƣ�";
	string name;
	cin >> name;

	for (int i = 0; i < item_num; i++)
	{
		if (all_items[i].amount > 0 && (all_items[i].name == name || (all_items[i].name.find(name) != string::npos))) //֧����ȫƥ���ģ��ƥ��
		{
			if (flag == 0) //�������ĵ�һ����Ʒ�������ͷ�����������ɹ�����Ʒ����Ҫ�����ͷ
			{
				cout << "==================================================" << endl;
				cout << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
				flag = 1;
			}
			//����������
			cout << all_items[i].id << "\t";
			cout << all_items[i].name << "\t";
			cout << all_items[i].brand << "\t";
			cout << all_items[i].price << "\t";
			cout << all_items[i].amount << "\t";
			cout << endl;
		}
	}
	if (flag == 1) //�����ɹ��������β
		cout << "==================================================" << endl;
	else //����ʧ�ܣ������ʾ��
		cout << "δ�ҵ�����Ʒ�����Ի�һ���������ɣ�" << endl;
	/*
	string choice; //ѡ��������ʽ
	cout << "��ѡ����Ʒ������ʽ��1.��������     2.����+Ʒ������" << endl;
	cout << "��������Ʒ������ʽ��";
	cin >> choice;
	//��һ��������ʽ
	if (choice == "1")
	{
		int flag = 0; //��ʾ�����Ƿ�ɹ�
		cout << "��������Ʒ���ƣ�";
		string name;
		cin >> name;

		for (int i = 0; i < item_num; i++)
		{
			if (all_items[i].amount > 0 && all_items[i].name == name) //�����ɹ�
			{
				if (flag == 0) //������������ĵ�һ����Ʒ�������ͷ
				{
					cout << "==================================================" << endl;
					cout << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
					flag = 1;
				}
				//����������
				cout << all_items[i].id << "\t";

				cout << all_items[i].name << "\t";

				cout << all_items[i].brand << "\t";

				cout << all_items[i].price << "\t";

				cout << all_items[i].amount << "\t";
				cout << endl;
			}
		}

		if (flag == 1) //�����ɹ��������β
			cout << "==================================================" << endl;
		else //����ʧ�ܣ������ʾ��
			cout << "δ�ҵ�����Ʒ�����Ի�һ���������ɣ�" << endl;
	}

	//�ڶ���������ʽ
	else if (choice == "2")
	{
		int flag = 0; //��ʾ�����Ƿ�ɹ�
		cout << "��������Ʒ���ƣ�";
		string name;
		cin >> name;
		cout << "��������ƷƷ�ƣ�";
		string brand;
		cin >> brand;

		for (int i = 0; i < item_num; i++)
		{
			if (all_items[i].amount > 0 && all_items[i].name == name&& all_items[i].brand == brand) //�����ɹ�
			{
				if (flag == 0) //������������ĵ�һ����Ʒ�������ͷ
				{
					cout << "==================================================" << endl;
					cout << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
					flag = 1;
				}
				//����������
				cout << all_items[i].id << "\t";
				cout << all_items[i].name << "\t";
				cout << all_items[i].brand << "\t";
				cout << all_items[i].price << "\t";
				cout << all_items[i].amount << "\t";
				cout << endl;
			}
		}

		if (flag == 1) //�����ɹ��������β
			cout << "==================================================" << endl;
		else //�������ɹ��������ʾ��
			cout << "δ�ҵ�����Ʒ�����Ի�һ���������ɣ�" << endl;
	}
	else
		cout << "����Ĳ���ָ�" << endl;
		*/
}

//�û������Ʒ�����ﳵ	��
void Shopping::add_shopping_car(int index, user* this_user)
{
	read_all_the_items(); //��ȡ���
	read_shopping_car(this_user); //��ȡ���û����ﳵ

	cout << "������������ﳵ����Ʒid��";
	int id;
	cin >> id;
	cout << "������������ﳵ����Ʒ������";
	int amount;
	cin >> amount;

	int i;
	for (i = 0; i < this_user->shopping_car_num; i++)
	{
		if (this_user->shopping_car[i].id == id)
		{
			int index = 0; //������¼����Ʒ�ڹ��ﳵ�е��±�
			for (int j = 0; j<item_num; j++)
			if (all_items[j].id = id)
				index = j;

			if (amount > all_items[index].amount)//�������������棬���ʧ��
			{
				cout << "���ʧ�ܣ��������������Ʒ��棬���޸ģ�" << endl;
				break;
			}

			else //��ӳɹ� 
			{
				this_user->shopping_car[i].amount += amount;
				cout << "================" << endl;
				cout << "���빺�ﳵ�ɹ���" << endl;
				cout << "================" << endl;
				write_shopping_car(this_user);
				break;
			}
		}
	}

	if (i == this_user->shopping_car_num) //���ﳵ��δ�ҵ���ӦID
	{
		int j;
		for (j = 0; j<item_num; j++)
		if (all_items[j].id == id) //�ڿ�����ҵ��˶�ӦID
		{
			if (id > all_items[i].amount) //�������������棬���ʧ��
			{
				cout << "���ʧ�ܣ��������������Ʒ��棬���޸ģ�" << endl;
				break;
			}
			else //��ӳɹ������ﳵ�����һ
			{
				this_user->shopping_car_num++;
				this_user->shopping_car[this_user->shopping_car_num - 1].id = id;
				this_user->shopping_car[this_user->shopping_car_num - 1].name = all_items[j].name;
				this_user->shopping_car[this_user->shopping_car_num - 1].brand = all_items[j].brand;
				this_user->shopping_car[this_user->shopping_car_num - 1].price = all_items[j].price;
				this_user->shopping_car[this_user->shopping_car_num - 1].amount = amount;
				write_shopping_car(this_user);
				cout << "================" << endl;
				cout << "���빺�ﳵ�ɹ���" << endl;
				cout << "================" << endl;
				break;
			}
		}

		if (j == item_num)
		{
			cout << "������û�ҵ���ID��Ӧ����Ʒ�������Ƿ�������ȷ��" << endl;
		}
	}

	//չʾ���ﳵ
	cout << "���ﳵ�������У�" << endl;
	visit_shopping_car(index, this_user);
}

//�û�ɾ�����ﳵ��Ʒ	��
void Shopping::delete_shopping_car(int index, user* this_user)
{
	read_shopping_car(this_user); //��ȡ���û����ﳵ

	cout << "�����ɾ������ƷID��";
	int id;
	cin >> id;

	int i;
	bool flag = false;	//���ڱ�־�Ƿ�ɾ���ɹ�
	for (i = 0; i < this_user->shopping_car_num; i++)
	{
		if (this_user->shopping_car[i].id == id)
		{
			for (int j = i; j < this_user->shopping_car_num; j++)
			{
				this_user->shopping_car[j] = this_user->shopping_car[j + 1];
			}
			this_user->shopping_car_num--;
			flag = true;
			write_shopping_car(this_user);
			cout << "============" << endl;
			cout << "ɾ���ɹ���" << endl;
			cout << "============" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "���ﳵ��û�и�ID��Ӧ����Ʒ�������Ƿ��������" << endl;

	//չʾ���ﳵ
	cout << "���ﳵ�������У�" << endl;
	visit_shopping_car(index, this_user);

}

//�û��޸Ĺ��ﳵ��Ʒ����
void Shopping::change_shopping_car(int index, user* this_user)
{
	read_shopping_car(this_user); //��ȡ���û����ﳵ

	cout << "������޸ĵ���ƷID��";
	int id;
	cin >> id;

	cout << "������Ҫ�޸ĵ�������" << endl;
	int num;
	cin >> num;

	int i;
	bool flag = false;	//���ڱ�־�Ƿ��޸ĳɹ�
	for (i = 0; i < this_user->shopping_car_num; i++)
	{
		if (this_user->shopping_car[i].id == id)
		{
			this_user->shopping_car[i].amount = num;
			flag = true;
			write_shopping_car(this_user);
			cout << "============" << endl;
			cout << "�޸ĳɹ���" << endl;
			cout << "============" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "���ﳵ��û�и�ID��Ӧ����Ʒ�������Ƿ��������" << endl;

	//չʾ���ﳵ
	cout << "���ﳵ�������У�" << endl;
	visit_shopping_car(index, this_user);

}


//�û��鿴���ﳵ	��
void Shopping::visit_shopping_car(int index, user* this_user)	//�ȶ�ȡ��Ӧ�Ĺ��ﳵ�ļ������
{
	read_shopping_car(this_user); //���빺�ﳵ�ļ�

	//��������Ʒ���ݣ�����Ϊ0����ƷҲҪ���
	if (this_user->shopping_car_num == 0)
	{
		cout << "��ǰ���ﳵΪ�գ�ȥ�𴦹��ɣ�" << endl;
	}
	else
	{
		cout << "==================================================" << endl;
		cout << "id\t" << "����\t" << "Ʒ��\t" << "�۸�\t" << "����" << endl;
		for (int i = 0; i < this_user->shopping_car_num; i++)
		{
			cout << this_user->shopping_car[i].id << "\t";
			cout << this_user->shopping_car[i].name << "\t";
			cout << this_user->shopping_car[i].brand << "\t";
			cout << this_user->shopping_car[i].price << "\t";
			cout << this_user->shopping_car[i].amount << "\t" << endl;
		}
		cout << "==================================================" << endl;
	}
}

//�û����ˣ���Ҫ�޸��û����ﳵ�������ۻ��嵥
void Shopping::check_out(int index, user* this_user)
{
	//��ȡ��棬���ﳵ���ջ���ַ���ۻ��嵥
	read_all_the_items();
	read_shopping_car(this_user);
	read_the_sales_list();
	read_shopping_address();

	visit_shopping_car(index, this_user);	//�鿴���ﳵ

	if (this_user->shopping_car_num > 0)
	{
		//�ջ���ַ
		/*if (this_user->address == "none")
		{
		string address;
		cout << "��ǰ�ջ���ַΪ�գ�������һ���ջ���ַ��";
		cin >> address;
		this_user->address = address;
		write_shopping_address();
		cout << "���óɹ���" << endl;
		}
		cout << "��ǰ�ջ���ַΪ��" << this_user->address << endl;*/

		float money = 0; //�������=sum(����*����)
		for (int i = 0; i < this_user->shopping_car_num; i++)
		{
			money += this_user->shopping_car[i].price * this_user->shopping_car[i].amount;	//ÿ����Ʒ�ļ۸�˹�������
		}
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "���ﳵ��Ʒ�ܼ�Ϊ" << money << "Ԫ��" << endl;
		cout << "��ѡ�����Ĳ�����" << endl;
		cout << "0.ȡ������" << endl;
		cout << "1.ȫ������" << endl;
		cout << "2.ѡ���ﳵ�ڲ�����Ʒ����" << endl;
		cout << "�����������";
		int choice;
		cin >> choice;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		if (choice == 0)
		{
			cout << "��ȡ�����" << endl;
		}
		else if (choice == 1)
		{
			//�޸Ŀ��
			/*for (int i = 0; i < this_user->shopping_car_num; i++)
			{
			int num = this_user->shopping_car[i].id;
			for (int j = 0; j < item_num; j++)
			{
			if (all_items[j].id == num)
			{
			all_items[j].amount -= this_user->shopping_car[i].amount;
			}
			}
			}
			write_all_the_items();*/

			//�޸��ۻ��嵥
			/*for (int i = 0; i < this_user->shopping_car_num; i++)
			{
			sale_item_num++;
			all_sales[sale_item_num - 1].id = this_user->shopping_car[i].id;
			all_sales[sale_item_num - 1].name = this_user->shopping_car[i].name;
			all_sales[sale_item_num - 1].brand = this_user->shopping_car[i].brand;
			all_sales[sale_item_num - 1].price = this_user->shopping_car[i].price;
			all_sales[sale_item_num - 1].amount = this_user->shopping_car[i].amount;
			all_sales[sale_item_num - 1].my_user = this_user->name;
			}
			write_the_sales_list();*/

			//����û����ﳵ
			for (int i = 0; i < this_user->shopping_car_num; i++)
			{
				this_user->shopping_car_num = 0;
				
			}
			
		}
		else if (choice == 2)
		{
			money = 0;
			while (1)
			{
				cout << "�����빺�ﳵ��Ҫѡ�������Ʒid:";
				int id;
				cin >> id;
				cout << "������Ҫ�������Ʒ������:";
				int num;
				cin >> num;

				int i;
				bool flag = false;	//���ڱ�־�Ƿ�ѡ��ɹ�
				for (i = 0; i < this_user->shopping_car_num; i++)
				{
					if (this_user->shopping_car[i].id == id)
					{
						if (num == this_user->shopping_car[i].amount)
						{
							for (int j = i; j < this_user->shopping_car_num; j++)	//�ӹ��ﳵɾ��������ǰ��
							{
								this_user->shopping_car[j] = this_user->shopping_car[j + 1];
							}
							this_user->shopping_car_num--;
							money += this_user->shopping_car[i].price * num;
							flag = true;
							break;
						}
						if (this_user->shopping_car_num > num)
						{

							this_user->shopping_car[i].amount -= num;
							money += this_user->shopping_car[i].price * num;
							flag = true;
							break;
						}
					}

				}
				if (flag == false)
				{
					cout << "���ﳵ��û�и�ID��Ӧ����Ʒ�������Ƿ��������" << endl;
				}
				else
				{
					cout << "ѡ��ɹ�" << endl;
				}
				cout << "����������������ѡ��" << endl;
				cout << "1.����ѡ��" << endl;
				cout << "0.����ѡ��" << endl;
				cout << "�����룺" << endl;
				int select;
				cin >> select;
				if (select == 0)
					break;
			}	//while����
		}
		write_shopping_car(this_user);	//д�빺�ﳵ�ļ�

		//��������Ż�ȯ
		int m = rand() % 10;
		cout << "��ϲ�����һ�����Ϊ" << m << "���Ż�ȯ���Ż�ȯ��Ϊ123456�������ڸ���ʱѡ��ʹ��" << endl;

		//��ۿ�
		cout << "�̳ǽ����ϼܻ��ȫ����Ʒ�����" << endl;


		//�����ʾ��
		cout << "��ѡ���Ƿ�ʹ���Ż�ȯ" << endl;
		cout << "0.��ʹ��" << endl;
		cout << "1.ʹ���Ż�ȯ" << endl;
		int select = 0;
		cin >> select;
		if (select == 0)
		{
			cout << "=========" << endl;
			cout << "����ɹ��������Żݺ󸶿���Ϊ��" << money*0.9 << endl;
			cout << "=========" << endl;
		}
		else if (select == 1)
		{
			cout << "�������Ż�ȯ�룺" << endl;
			string str = "";
			cin >> str;
			if (str == "123456")
			{
				cout << "=========" << endl;
				cout << "����ɹ��������Ż���ʹ���Ż�ȯ��ĸ�����Ϊ��" << (money*0.9 - m) << endl;
				cout << "=========" << endl;
			}
		}
		else
		{
			cout << "��������������ѡ��" << endl;
		}	
	}
}

//��չ���ܣ��û��޸�����	��
void Shopping::change_password(int index, user* this_user)
{
	cout << "������ԭ���룺";
	string old_pass;
	cin >> old_pass;

	if (old_pass == this_user->password)
	{
		string new_pass;
		cout << "�����������룺";
		cin >> new_pass;
		//���������볤�ȴ�����λ
		while (new_pass.size() <= 3)
		{
			cout << "���볤��̫�̣����������룡" << endl;
			cout << "�������룺";
			cin >> new_pass;
		}
		this_user->password = new_pass;
		write_all_the_users();
		cout << "=========" << endl;
		cout << "�޸ĳɹ���" << endl;
		cout << "=========" << endl;
	}

	else
		cout << "������������޸�ʧ�ܣ�" << endl;
}

//��չ���ܣ������ջ���ַ
void Shopping::change_address(int index, user* this_user)
{
	read_shopping_address(); //��ȡ�ջ���ַ

	if (this_user->address != "none") //��ǰ��ַ��Ϊ��
	{
		string address;
		cout << "��ǰ���ջ���ַΪ��" << this_user->address << endl;
		cout << "�޸ĺ���ջ���ַΪ��";
		cin >> address;
		this_user->address = address;
		cout << "**********" << endl;
		cout << "�޸ĳɹ���" << endl;
		cout << "**********" << endl;
	}
	else
	{
		cout << "��ǰ��ַΪ�գ�����������ջ���ַ��";
		string address;
		cin >> address;
		this_user->address = address;
		cout << "**********" << endl;
		cout << "�޸ĳɹ���" << endl;
		cout << "**********" << endl;
	}
	write_shopping_address(); //д���ļ���
}
