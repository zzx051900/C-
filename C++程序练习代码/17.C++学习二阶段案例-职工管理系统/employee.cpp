#include"employee.h"

Employee::Employee(int id, string name, int dId)	//�вι��캯������������ְ����ţ����������ű�ţ�
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
	//�β������Ա������һ��ʱ�����thisָ�룬��һ��ʱ�ɼӿɲ���
}

void Employee::showInfo()	//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()	//��ȡ��λ��Ϣ
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName()	//��ȡ��λ��Ϣ
{
	return string("Ա��");
}