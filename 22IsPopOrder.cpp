#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

bool IsPopOrder(const int* pPush, const int* pPop, size_t length)
{
	assert(length);
	assert(pPush && pPop);

	bool possible = false;

	const int* NextPush = pPush;
	const int* NextPop = pPop;

	stack<int> s;
	while (NextPop - pPop < length)
	{
		while (s.empty() || s.top() != *NextPop)
		{
			if (NextPush - pPop == length)
			{
				break;
			}
			s.push(*NextPush);
			NextPush++;
		}
		if (s.top() != *NextPop)
		{
			break;
		}
		s.pop();
		NextPop++;
	}
	if (s.empty() && NextPop - pPop == length)
	{
		possible = true;
	}
	return possible;
}
