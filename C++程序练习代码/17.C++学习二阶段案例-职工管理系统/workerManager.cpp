#include"workerManager.h"

//���캯����cpp�ļ���ʵ��
WorkerManager::WorkerManager()	
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ������ڵ����
	if (!ifs.is_open())	//����ļ���ʧ�ܣ�����0��ȡ��Ϊ1
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;	//��ʼ������Ϊ0
		this->m_FileIsEmpty = true;	//��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL;	//��ʼ������ָ��Ϊ��
		ifs.close();
		return;
	}

	//�ļ����ڣ�����¼Ϊ�յ����
	char ch;
	ifs >> ch;	//�����ļ��е�һ���ַ������ļ�Ϊ�գ���������EOF����������̫��⣩
	if (ifs.eof())	//�ж϶����Ƿ�ΪEOF�����ǣ���Ϊ��
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;	//��ʼ������Ϊ0
		this->m_FileIsEmpty = true;	//��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL;	//��ʼ������ָ��Ϊ��
		ifs.close();
		return;
	}

	//�ļ����ڣ��Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;

	//��ʼ���޸�ְ������
	this->m_EmpNum = num;	

	//��ʼ���޸�ְ������
	this->m_EmpArray = new Worker*[this->m_EmpNum];	//�ò���Ӧ���Ƕ�̬���������ڴ��С
	this->init_Emp(); //��ʼ��ְ�����飨���ļ��е�ְ����Ϣ�ŵ����������ְ�������У����ڳ���ִ�У�

	//��ʼ���޸��ļ��ձ�־Ϊ�ǿ�
	this->m_FileIsEmpty = false;

	/*
	//����Ӧ���ǲ���
	//���������ְ����Ϣ�������Ƿ���ļ�����ȷ��ȡ
	//����Ҳ���Ե���worker�����������showInfo()��������Ϊ�ڳ�ʼ��������worker**�����д����¶����ʱ����Ѿ�����ʶ��ͬ�����ˣ����п������ö�̬��ʾְ����Ϣ
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< "\tְ��������" << this->m_EmpArray[i]->m_Name
			<< "\t���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}*/
}

//�˵�����
void WorkerManager::Show_Menu()	
{
	cout << "**********************************" << endl;
	cout << "****** ��ӭʹ��ְ������ϵͳ ******" << endl;
	cout << "********* 0.�˳�����ϵͳ *********"  << endl;
	cout << "********* 1.����ְ����Ϣ *********" << endl;
	cout << "********* 2.��ʾְ����Ϣ *********" << endl;
	cout << "********* 3.ɾ����ְְ�� *********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ *********" << endl;
	cout << "********* 5.����ְ����Ϣ *********" << endl;
	cout << "********* 6.���ձ������ *********" << endl;
	cout << "********* 7.��������ĵ� *********" << endl;
	cout << "**********************************" << endl;
}

//���ְ��
void WorkerManager::Add_Emp()		
{
	cout << "���������ְ��������" << endl;
	int addNum;	//�����û�����������
	cin >> addNum;
	//�ж����������Ƿ���Ч������������Ч��������ʾ��������
	if (addNum > 0)
	{
		//���˼·���ڶ�������һ���µ������ڴ�ռ䣬��С����ԭְ������������ӵ�ְ����������ԭ���������ƶ��������飬�ں�����������ְ���������ɺ��ͷ�ԭ����ռ䣬��Ա��������ָ��ָ���µ��ڴ�ռ䣬����ְ������
		int newSize = this->m_EmpNum + addNum;	//�����¿ռ�Ĵ�С������ԭ����������ӵ�����
		Worker** newSpace = new Worker*[newSize];	//�����¿ռ�
		if (this->m_EmpArray != NULL)	//�ж������Ƿ�Ϊ�գ�����������⣩������Ϊ�գ���ԭ���������ƶ���������
		{
			for (int i = 0; i < this->m_EmpNum; i++)	//��������ԭ������
			{
				newSpace[i] = this->m_EmpArray[i];	//���������������Ϳ��Կ�����
			}
		}
		for (int i = 0; i < addNum; i++)	//�����������
		{
			int id;	//ְ�����
			string name;	//����
			int dSelect;	//���ű��
			cout << "�������" << i + 1 << "��Ա����ְ�����:" << endl;
			cin >> id;
			cout << "�������Ա��������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;	//�¼�������ְ���������е�λ����this->m_EmpNum + i
		}
		delete[] this->m_EmpArray;	//�ͷ�ԭ������
		this->m_EmpArray = newSpace;	//����ְ�������ָ��ָ���½�������׵�ַ
		this->m_EmpNum = newSize;	//����ְ��������
		this->m_FileIsEmpty = false;	//�����ļ�Ϊ�ǿ�״̬
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		this->save();	//��ӳɹ���д���ļ�
	}
	else
	{
		cout << "������������" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}

//��ȡ�ļ��е�ְ������
int WorkerManager::get_EmpNum()	
{
	ifstream ifs;	//�������ļ���
	ifs.open(FILENAME, ios::in);	//���ļ���Ϊ���ļ���

	int id;
	string name;
	int dId;

	int num = 0;	//ͳ������

	while (ifs >> id && ifs >> name && ifs >> dId)	//�ɹ�����һ���˵����ݣ�num�Ϳ��Լ�1
	{
		num++;
	}

	ifs.close();	//�ر��ļ�
	return num;
}

//��ʼ��ְ������
void WorkerManager::init_Emp()	
{
	ifstream ifs;	//�������ļ���
	ifs.open(FILENAME, ios::in);	//���ļ���Ϊ���ļ���

	int id;
	string name;
	int dId;

	int index = 0;	//���������±�
	while (ifs >> id && ifs >> name && ifs >> dId)	//�ɹ�����һ���˵�����
	{
		Worker* worker = NULL;	//������ʱ����ÿ��ְ��
		//���ݲ�ͬ���Ŵ�����ͬ����
		if (dId == 1)	//��ְͨ��
		{
			worker = new Employee(id, name, 1);
		}
		else if (dId == 2)	//����
		{
			worker = new Manager(id, name, 2);
		}
		else	//�ܲ�
		{
			worker = new Boss(id, name, 3);
		}
		//�浽������
		this->m_EmpArray[index] = worker;
		index++;	//�����±�++
	}
	ifs.close();
}

//��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
	//�ж��ļ��ձ�־�Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//���ö�̬���ýӿ�
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ���ڣ�����id�жϣ�
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)	//���ҵ��������ţ����������±�
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);	//�жϸ�ְ���Ƿ���ڣ������������±�
		if (index == -1)	//����ְ��������
		{
			cout << "ɾ��ʧ�ܣ���ְ�������ڣ�" << endl;
		}
		else
		{
			//��������ǰ�Ƹ���
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//ְ����������һ
			if (this->m_EmpNum == 0)
				this->m_FileIsEmpty = true;
			this->save();	//���±����ļ�
			cout << "ɾ���ɹ���" << endl;
		}
	}
	//ɾ���ɹ������������������
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);	//�жϸ�ְ���Ƿ���ڣ������������±�
		if (index == -1)	//����ְ��������
		{
			cout << "�޸�ʧ�ܣ���ְ�������ڣ�" << endl;
		}
		else
		{
			delete this->m_EmpArray[index];	//ΪʲôҪdelete��ֱ���޸��滻�������� ��Ϊ�޸�ְ���������ܻ�ı䣬���Ǽ򵥵��޸�����
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽�˱��Ϊ" << id << "��ְ�����������µ�ְ����ţ�" << endl;
			cin >> newId;
			cout << "�������µ�ְ��������" << endl;
			cin >> newName;
			cout << "�������µĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			if (dSelect == 1)
			{
				worker = new Employee(newId, newName, 1);
			}
			else if (dSelect == 2)
			{
				worker = new Manager(newId, newName, 2);
			}
			else if (dSelect == 3)
			{
				worker = new Boss(newId, newName, 3);
			}
			else
			{
				cout << "�������" << endl;
			}
			this->m_EmpArray[index] = worker;	//���µ�������
			cout << "�޸ĳɹ�!" << endl;
			this->save();	//���浽�ļ���
		}
	}
	//ɾ���ɹ������������������
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ����ҵķ�ʽ��" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[index]->showInfo();	//��̬ʵ�ֵ���ʾְ����Ϣ
			}
			else
			{
				cout << "����ʧ��!��ְ��������" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			cin >> name;
			bool flag = false;	//���ڱ�־�Ƿ��ҵ���Ĭ��Ϊflase
			int num = 0;	//���ڼ�¼���������һ���м�������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
					num++;
				}
			}
			if (num>1)
			{
				cout << "�������������������ְ����" << num << "λ" << endl;
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ���ְ��������!" << endl;
			}
			
		}
		else
		{
			cout << "�����������������" << endl;
		}	
	}
	//���ҳɹ������������������
	system("pause");
	system("cls");
}

//����
void WorkerManager::Sort_Emp()
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)	//����
		{
			Worker* worker = NULL;
			for (int i = 0; i < this->m_EmpNum - 1; i++)	//n������Ҫð������n-1��
			{
				bool flag = false;	//���ڱ�־һ���������Ƿ����˽�������δ��������˵���Ѿ�����ɹ�������ѭ��
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++)	//ÿ�ν��������Խ�һ�����������С���ƶ�����Ӧ���ڵ�λ�ã�����ÿ����Ҫ�Ƚϵ�������һ
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
						flag = true;
					}
				}
				if (!flag)
					break;
			}
		}
		else if (select == 2)	//����
		{
			Worker* worker = NULL;
			for (int i = 0; i < this->m_EmpNum - 1; i++)	//n������Ҫð������n-1��
			{
				bool flag = false;	//���ڱ�־һ���������Ƿ����˽�������δ��������˵���Ѿ�����ɹ�������ѭ��
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++)	//ÿ�ν��������Խ�һ�����������С���ƶ�����Ӧ���ڵ�λ�ã�����ÿ����Ҫ�Ƚϵ�������һ
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
						flag = true;
					}
				}
				if (!flag)
					break;
			}
		}
		else
		{
			cout << "�������" << endl;
		}
		this->Show_Emp();	//���������ְ��
		this->save();	//���±����ļ�
	}		
	//����ɹ������������������
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()	
{
	//���ַ���ÿ�ζ��ǽ�ȫ����������д���ļ�
	ofstream ofs;	//����������
	ofs.open(FILENAME, ios::out);	//�򿪷�ʽ
	for (int i = 0; i<this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();	//�ر��ļ�
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "���ٴ�ȷ���Ƿ�Ҫ����ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);	//�򿪷�ʽΪ��ɾ���ļ������´���
		//Ҳ��ֱ��д�ɣ�ofstream ofs(FILENAME, ios::trunc);��
		ofs.close();
		//�ͷŶ������ݣ����ļ���ʱ���캯���ڶ������ٵĿռ䣨�����������ܲ�ȫ����ִ������������ʱ�����ж������������ظ��ͷţ�
		if (this->m_EmpArray)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i])	//�ж�ÿһ��������ÿһ�������Ƿ����ڶ������ٿռ䣬����У�������ͷ�
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;	//ְ����������
			this->m_FileIsEmpty = true;	//�ļ��ձ�־��Ϊ��
		}
	}
	system("pause");
	system("cls");
}

//�˳�ϵͳ
void WorkerManager::exitSystem()	
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);	//������������ã����򶼿���ֱ���˳�
}

//����������cpp�ļ���ʵ��
WorkerManager::~WorkerManager()	
{
	//�ͷŶ�������
	if (this->m_EmpArray)	
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i])	//�ж�ÿһ��������ÿһ�������Ƿ����ڶ������ٿռ䣬����У�������ͷ�
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
