//打印1到最大的n位数
//输入数字n，按顺序打印从1到最大的n位十进制数。
//例如输入3，则打印出1，2，3，一直到最大的三位数999。
#include<iostream>
using namespace std;
#include<math.h>
//void Print1ToN(int n)
//{
//	int MaxNum = pow(10, n)-1;
//	int i = 1;
//	for (i = 1; i <= MaxNum; i++)
//	{
//		printf("%10d", i);
//	}
//	cout << endl;
//}

bool Increament(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
		{
			nSum++;
		}
		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0&&number[i] != '0')
		{
			isBeginning0 = false;
		}
		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
}
void Print1ToN(int n)
{
	if (n <= 0)
	{
		return;
	}
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!Increament(number))
	{
		PrintNumber(number);
	}
	delete []number;
}
int main()
{
	int n = 0;
	cout << "请输入n的值->";
	cin >> n;
	Print1ToN(n);
	printf("\n");
	system("pause");
	return 0;
}