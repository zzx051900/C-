//(δ���ƣ�
#include<iostream>
using namespace std;

/*
����������ƣ�
1.������������
2.�������
3.�����Ϊ����ȡ��������������
4.�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
*/

class Cube
{
public:
	//���ó�
	void setL(int l)
	{
		m_L = l;
	}
	//��ȡ��
	int getL()
	{
		return m_L;
	}
	//���ÿ�
	void setW(int w)
	{
		m_W = w;
	}
	//��ȡ��
	int getW()
	{
		return m_W;
	}
	//���ø�
	void setH(int h)
	{
		m_H = h;
	}
	//��ȡ��
	int getH()
	{
		return m_H;
	}
	//��ȡ���������
	int calculateS()
	{
		return 2 * (m_L*m_W + m_L*m_H + m_W*m_H);
	}
	//��ȡ���������
	int calculateV()
	{
		return m_L * m_W * m_H;
	}
	//���ó�Ա�����ж������������Ƿ���ȣ���ʱ����ֻ��һ������Ϊ����һ����������õ������Ա����������Ҫ���Σ�
	bool isSameByClass(Cube &c)
	{
		//�ж�����
		//m_L   
		//c2.getL()
		return 1;
	}

private:
	int m_L;//��
	int m_W;//��
	int m_H;//��
};

bool isSame(Cube &c1, Cube &c2);

int main()
{
	//����һ�����������
	Cube c1;
	c1.setL(10);//����Ϊ10
	c1.setW(10);
	c1.setH(10);

	cout << "c1�����Ϊ��" << c1.calculateS() << endl;
	cout << "c1�����Ϊ��" << c1.calculateV() << endl;

	//�����ڶ���������
	Cube c2;
	c2.setL(10);//����Ϊ10
	c2.setW(10);
	c2.setH(10);

	//����ȫ�ֺ����ж�
	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "ȫ�ֺ����ж����" << endl;
	}
	else
	{
		cout << "ȫ�ֺ����жϲ����" << endl;
	}

	//���ó�Ա�����ж�
	ret = c1.isSameByClass(c2);
	if (ret)
	{
		cout << "��Ա�����ж����" << endl;
	}
	else
	{
		cout << "��Ա�����жϲ����" << endl;
	}

	system("pause");
	return 0;
}

//����ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube &c1, Cube &c2)
{
	//�ж�����
	return 1;
}