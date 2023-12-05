#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking
{
public:
	virtual void Boil() = 0;		//��ˮ
	virtual void Brew() = 0;		//����
	virtual void PourInCup() = 0;	//���뱭��
	virtual void PutSomething() = 0;//���븨��
	void makeDrink()	//������Ʒ
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "���Ȫˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "�������" << endl;
	}
};

void doWork(AbstractDrinking* abs)	//����һ�������ָ�� //��һ����������Ϊ���ȺͲ趼Ҫ�õ������Ե�����װ����һ��
{
	abs->makeDrink();
	delete abs;
	abs = NULL;
}

void test01()
{
	//��������
	doWork(new Coffee);
	cout << "------------" << endl;
	//������Ҷ
	doWork(new Tea);
}

int main()
{
	test01();

	system("pause");
	return 0;
}