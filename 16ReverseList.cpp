#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int _key;
	ListNode* _next;
};

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		ListNode* pNext = pNode->_next;
		if (pNext == NULL)
		{
			pReversedHead = pHead;
		}
		pNext->_next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;

}