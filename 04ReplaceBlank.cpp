//��ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20����
//���磺���롰We are happy.���������We%20are%20happy.����
#include<iostream>
using namespace std;
#include<assert.h>


void ReplaceBlank(char *arr)
{
	assert(arr);
	//��ͳ���ַ�����ʵ�ʳ��ȺͿո�ĸ���
	int OldLen = 0;//���������ʵ�ʳ���
	int NewLen = 0;
	int BlankNum = 0;//������������еĿո�ĸ���
	int NewBack = 0;
	int OldBack = 0;



	while (arr[OldLen] != '\0')//��û�е��ַ�����β��ʱ������ִ��
	{
		if (arr[OldLen] == ' ')//�������ո�ʱ���ո��������1��
		{
			BlankNum++;
		}
		OldLen++;//ֻҪ����û�е����β��length1������1
	}

	NewLen = OldLen + BlankNum * 2;//�滻�ո�������ĳ��ȵ���ԭ���ĳ���+�ո�ĳ��ȳ���2
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

void PrintArr(char arr[])//��ӡ����ĺ��� 
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
	cout << "�滻ǰ���ַ�����";
	PrintArr(arr);
	ReplaceBlank(arr);
	cout << "�滻����ַ�����";
	PrintArr(arr);
	system("pause");
	return 0;
}