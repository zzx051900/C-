#include<iostream>
#include<string>
using namespace std;

//����CPU��
class CPU
{
public:
	//������㺯��
	virtual void calculate() = 0;	//���麯��
};

//�����Կ���
class VideoCard
{
public:
	//������ʾ����
	virtual void display() = 0;	//���麯��
};

//�����ڴ�����
class Memory
{
public:
	//����洢����
	virtual void storage() = 0;	//���麯��
};

//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)	//�вι���
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()	//����������������þ���ӿ�
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		//�ͷ�CPU���
		if (m_cpu)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//�ͷ��Կ����
		if (m_vc)
		{
			delete m_vc;
			m_cpu = NULL;
		}
		//�ͷ��ڴ������
		if (m_mem)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;	//CPU�����ָ��
	VideoCard* m_vc;	//�Կ����ָ��	
	Memory* m_mem;	//�ڴ������ָ��
};

//���峧�̣�
	//Intel����:
		//CPU
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};
		//�Կ�
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ" << endl;
	}
};
		//�ڴ���
class IntelMemory  :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢" << endl;
	}
};

	//Lenovo���̣�
		//CPU
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};
		//�Կ�
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ" << endl;
	}
};
		//�ڴ���
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢" << endl;
	}
};

//������װ��ͬ����
void test01()
{
	//��һ̨�����������Intel�ĵ��������
	CPU* intelCPU = new IntelCPU;	//����ָ��ָ��������󣬶�̬	//��������
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;

	//������һ̨����
	cout << "��һ̨���Կ�ʼ����" << endl;
	Computer* computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
	computer1->work();
	delete computer1;	//��ʱֻ�ͷ��˵�����ָ���ڶ������ڴ棬������ڶ������ڴ滹û���ͷ�

	//�����ڶ�̨���ԣ���Lenovo�ĵ��������
	cout << "----------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	//��������̨���ԣ���ϴ��䣩
	cout << "----------------" << endl;
	cout << "����̨���Կ�ʼ����" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}

int main()
{
	test01();

	system("pause");
	return 0;
}