//һά���鰸����Ѱ�����ֵ
#include<iostream>

using namespace std;

int main()
{
	//1.��������
	int arr[5] = { 50, 40, 60, 70, 90 };
	//2.Ѱ�����ֵ
	int max = 0;//������ֵ
	for (int i = 0; i < 5; i++)
	{
		if (arr[i]>max)
			max = arr[i];//������ʵ�Ԫ�ر����϶���Ԫ�ش���������ֵ
	}
	//3.������ֵ
	cout << "���ֵΪ��" << max << endl;
	system("pause");
	return 0;
}