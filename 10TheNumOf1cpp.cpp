//Q:��ʵ��һ������������һ����������������������е�
//1�ĸ��������磺��9��ʾ�ɶ�������1001����2λ��1.��ˣ����������9
//�ĺ������2��
#include<iostream>
using namespace std;
//int TheNumOf1(int num)//ʹ��ģ�������
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	return count;
//}
//int TheNumOf1(unsigned int num)//Ϊ�˱��⴫����ֵ�Ǹ���
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	return count;
//}

//int TheNumOf1(unsigned int num)//�Ż���ÿһ��������32λ�ı���λ
//{
//	int count = 0;
//	for (int i = 1; i < 32; i++)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	return count;
}

int TheNumOf1(unsigned int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	return count;
}

int main()
{
	int num = 0; 
	int ret = 0;
	cout << "������һ�����֣�";
	cin >> num;
	ret = TheNumOf1(num);
	cout << num << "�Ķ��������е�1�ĸ���Ϊ��" << ret << endl;
	system("pause");
	return 0;
}