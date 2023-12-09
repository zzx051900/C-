#pragma once
#include<cstring>
#include<stdlib.h>
using namespace std;
const int Max_num = 105;

//������Ʒ�ṹ�壬����id�����ơ�Ʒ�ơ��۸�����
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

//������Ʒ�ṹ�壬����id�����ơ�Ʒ�ơ��۸����������������û�
struct sale_item
{
	int id;
	string name;
	string brand;
	float price;
	int amount;
	string my_user;
};

//�½�һ������ϵͳ����
class Shopping
{
private:
	const string admin_ID = "aaa"; //����ԱID
	const string admin_passwd = "001003"; //����Ա����

public:

	item all_items[Max_num]; //���̿�棬����Ʒ�ṹ������ʵ��
	int item_num = 0; //��ǰ�����Ʒ������

	user all_users[Max_num]; //�û��б����û��ṹ������ʵ��
	int user_num = 0; //�û��б�����

	

	Shopping();	//���캯��
	void show();  //��ʾ������
	void users_enter(); //�û���¼����
	void users_register(); //�û�ע�����
	void administrator_enter(); //����Ա��¼����
	void admin_operate(); //����Ա��������
	void user_operate(int index, user* this_user); //�û���������,��Ҫ�Ĳ���Ϊ:���û����û��б��е��±��Լ��ýṹ��

	//�ļ���ز���
	void read_all_the_items(); //��ȡ����ļ�
	void write_all_the_items(); //д�����ļ�	
	void read_all_the_users(); //��ȡ�û��б�
	void write_all_the_users(); //д���û��б�
	void read_shopping_car(user* this_user); //��ȡ�û����ﳵ�ļ�
	void write_shopping_car(user* this_user); //д���û����ﳵ�ļ�

	//����Ա��ز���
	void show_items(); //��ѯ��Ʒ
	void add_item(); //������Ʒ
	void delete_item(); //ɾ����Ʒ
	void change_item(); //�޸���Ʒ����
	void show_sales_list(); //�ۻ��嵥

	//�û���ز���
	void visit_items(); //�鿴��Ʒ
	void search_item(); //��Ʒ����
	void add_shopping_car(int index, user* this_user); //�����Ʒ�����ﳵ
	void delete_shopping_car(int index, user* this_user); //ɾ�����ﳵ��Ʒ	
	void change_shopping_car(int index, user* this_user);	//�û��޸Ĺ��ﳵ��Ʒ����
	void visit_shopping_car(int index, user* this_user); //�鿴���ﳵ
	void check_out(int index, user* this_user); //����
	void change_password(int index, user* this_user); //��չ���ܣ��û��޸�����
};