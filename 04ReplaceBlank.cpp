//请实现一个函数，把字符串中的每个空格替换成“%20”。
//例如：输入“We are happy.”则输出“We%20are%20happy.”。
#include<iostream>
using namespace std;
#include<assert.h>


void ReplaceBlank(char *arr)
{
	assert(arr);
	//先统计字符串的实际长度和空格的个数
	int OldLen = 0;//定义数组的实际长度
	int NewLen = 0;
	int BlankNum = 0;//定义计算数组中的空格的个数
	int NewBack = 0;
	int OldBack = 0;



	while (arr[OldLen] != '\0')//当没有到字符串结尾处时，继续执行
	{
		if (arr[OldLen] == ' ')//当遇到空格时，空格个数增加1；
		{
			BlankNum++;
		}
		OldLen++;//只要数组没有到达结尾，length1就增加1
	}

	NewLen = OldLen + BlankNum * 2;//替换空格后的数组的长度等于原来的长度+空格的长度乘以2
	OldBack = OldLen - 1;
	NewBack = NewLen - 1;
	while (OldBack != 0)
	{
		if (arr[OldBack] == ' ')
		{
			arr[NewBack--] = '0';
			arr[NewBack--] = '2';
			arr[NewBack] = '%';
		}
		else
		{
			arr[NewBack] = arr[OldBack];
		}
		OldBack--;
		NewBack--;
	}
}

void PrintArr(char arr[])//打印数组的函数 
{
	int len = strlen(arr);
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		cout << arr[i];
	}
	cout << endl;
}

int main()
{
	char arr[20] = "We are happy.";
	cout << "替换前的字符串：";
	PrintArr(arr);
	ReplaceBlank(arr);
	cout << "替换后的字符串：";
	PrintArr(arr);
	system("pause");
	return 0;
}