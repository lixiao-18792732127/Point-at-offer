//Q1：写一个函数，求斐波那契数列的第n项

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
	cout << "请输入一个数字：";
	cin >> n;
	/*result = Finonacci(n);
	cout << "递归法：求第" << n << "个斐波那契数为：" << result << endl;*/
	result = Finonacci(n);
	cout <<"非递归法：求第"<<n<<"个斐波那契数为："<<result << endl;
	system("pause");
	return 0;
}