//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
//ÿһ�඼���մ��ϵ��µ�����˳�����С������һ��������
//����������һ����ά�����һ���������ж��������Ƿ��и�����
#include<iostream>
using namespace std;
#include<assert.h>
const int M = 3;
const int N = 3;

bool Find(const int *a, int x, int y,int &key)
{
	assert(a);
	while (x < M&&x >= 0 && y < N&&y >= 0)
	{
		int num = a[x*M + y];
		if (key>num)//������ҵ����ִ��ڵ�һ�����һ�����֣���x++��
		{
			x++;
		}
		else if(key<num)//������ҵ�����С��ĳһ�����һ�����֣���y--��
		{
			y--;
		}
		else
		{
			return true;
		}
	}
	return false;
}
void Judge(int ret, int key)
{
	if (ret == 1)
	{
		cout << "����" << key << "�ҵ���!" << endl;
	}
	else//if (ret=0)
	{
		cout << "����" << key << "û���ҵ���" << endl;
	}
}

int main()
{
	int a[9] = { 1, 2, 3, 
		         4, 5, 6,
		         7, 8, 9 };
	int num = 0;
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> num;
	int ret = Find(a, 0, M - 1, num);
	Judge(ret,num);
	system("pause");
	return 0;
}