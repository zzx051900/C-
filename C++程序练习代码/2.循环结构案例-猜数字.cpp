#include<iostream>
#include<ctime>//timeϵͳʱ���ͷ�ļ�
using namespace std;

int main()
{
	//�����������ӣ����õ�ǰϵͳʱ���������������ֹÿ���������һ��
	srand((unsigned int)time(NULL));

	//ϵͳ���������(α�������
	int num = rand() % 100 + 1;//rand()%100������0~99�������
	//cout << num << endl;

	int val = 0;

	while (1)
	{
		//��ҽ��в²�
		cin >> val;

		//�ж���Ҳ²�
		if (val > num)
		{
			cout << "�²����" << endl;
		}
		else if (val < num)
		{
			cout << "�²��С" << endl;
		}
		else
		{
			cout << "��ϲ���¶���" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}