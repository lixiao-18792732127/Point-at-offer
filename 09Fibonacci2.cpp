//Q：菲波那切数列中的扩展：变态青蛙问题
//一只青蛙一次可以跳上一级台阶，也可以跳上两级，
//求该青蛙跳上一个n级的台阶有多少种跳法
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
	cout << "请输入台阶的阶数：";
	cin >> n;
	result = Sum(n);
	cout << "青蛙跳上" << n << "阶的台阶需要" << result << "种跳法"<<endl;
	system("pause");
	return 0;
}