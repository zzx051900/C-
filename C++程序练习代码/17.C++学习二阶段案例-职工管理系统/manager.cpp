#include"manager.h"

Manager::Manager(int id, string name, int dId)	//�вι��캯������������ְ����ţ����������ű�ţ�
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo()	//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()	//��ȡ��λ��Ϣ
		<< "\t��λְ������ϰ彻�������񣬲����·��������ͨԱ��" << endl;
}

string Manager::getDeptName()	//��ȡ��λ��Ϣ
{
	return string("����");
}