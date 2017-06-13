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
		if (sout.empty())//如果出栈的数字为空
		{
			while (!sin.empty())//当入栈的数字不为空的时候
			{
				sout.push(sin.top());//入栈里面的最上面数字拿出来放到出栈里面
				sin.pop();//入栈最上面的数字pop掉
			}
		}
		sout.pop();//当出栈的数字不为空时，将出栈里面的数字进行pop
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
	stack<T> sin;//定义入栈
	stack<T> sout;//定义出栈
};

int main()
{

	system("pause");
	return 0;
}