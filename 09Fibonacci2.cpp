//Q���Ʋ����������е���չ����̬��������
//һֻ����һ�ο�������һ��̨�ף�Ҳ��������������
//�����������һ��n����̨���ж���������
#include<iostream>
using namespace std;
long long Sum(int n)
{
	int arr[2] = { 0, 1 };
	if (n < 2)
	{
		return arr[n];
	}
	long F1 = 1;
	long F2 = 0;
	long ret = 0;
	for (unsigned int i = 0; i <= n; i++)
	{
		ret = F1 + F2;
		F2 = F1;
		F1 = ret;
	}
	return ret;
}
int main()
{
	int n = 0;
	int result = 0;
	cout << "������̨�׵Ľ�����";
	cin >> n;
	result = Sum(n);
	cout << "��������" << n << "�׵�̨����Ҫ" << result << "������"<<endl;
	system("pause");
	return 0;
}