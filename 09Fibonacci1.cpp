//Q1��дһ����������쳲��������еĵ�n��

#include<iostream>
using namespace std;
long long Finonacci(int n)
{
	int arr[2] = { 0, 1 };
	if (n < 2)
	{
		return arr[n];
	}
	long FibOne = 1;
	long FibTwo = 0;
	long Fib = 0;
	for (unsigned int i = 2; i <= n;i++)
	{
		Fib = FibTwo + FibOne;
		FibTwo = FibOne;
		FibOne = Fib;
	}
	return Fib;
}
//long long Finonacci(int n)
//{
//	if (n <= 0)
//	{
//		return 0;
//	}
//	if (n == 1)
//	{
//		return 1;
//	}
//	return Finonacci(n - 1) + Finonacci(n - 2);
//}
int main()
{
	int n = 0;
	int result = 0;
	cout << "������һ�����֣�";
	cin >> n;
	/*result = Finonacci(n);
	cout << "�ݹ鷨�����" << n << "��쳲�������Ϊ��" << result << endl;*/
	result = Finonacci(n);
	cout <<"�ǵݹ鷨�����"<<n<<"��쳲�������Ϊ��"<<result << endl;
	system("pause");
	return 0;
}