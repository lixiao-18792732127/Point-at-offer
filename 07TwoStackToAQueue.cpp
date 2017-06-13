#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>
template<typename T>
class Queue
{
public:
	void Push(const T& x)
	{
		sin.push(x);
	}

	void Pop()
	{
		assert(!sin.empty() || sout.empty());
		if (sout.empty())//�����ջ������Ϊ��
		{
			while (!sin.empty())//����ջ�����ֲ�Ϊ�յ�ʱ��
			{
				sout.push(sin.top());//��ջ����������������ó����ŵ���ջ����
				sin.pop();//��ջ�����������pop��
			}
		}
		sout.pop();//����ջ�����ֲ�Ϊ��ʱ������ջ��������ֽ���pop
	}

	const T& Front()
	{
		assert(!sin.empty() || !sout.empty());
		if (sout.empty())
		{
			while (!sin.empty())
			{
				sout.push(sin.top());
				sin.pop();
			}
		}return sout.top();
	}
protected:
	stack<T> sin;//������ջ
	stack<T> sout;//�����ջ
};

int main()
{

	system("pause");
	return 0;
}