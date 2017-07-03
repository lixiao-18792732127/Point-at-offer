#include<iostream>
using namespace std;
#include<assert.h>
struct Node
{
	Node* _value;
	Node* _next;
	Node* _Sibling;
};
Node* CopyComplexList(Node*& phead)
{
	assert(phead);
	Node* Cur = phead;
	Node* tmp = NULL;
	while (Cur)
	{
		tmp = Cur;
		Cur = Cur->_next;

		Node* newNode = new Node(tmp->_value);
		tmp->_next = newNode;
		newNode->_next = Cur;
	}

	Cur = phead;
	Node* newNode = NULL;
	while (Cur)
	{
		newNode = Cur->_next;
		if (Cur->_Sibling)
		{
			newNode->_Sibling = Cur->_Sibling->_next;
			Cur = newNode->_next;
		}
	}
}