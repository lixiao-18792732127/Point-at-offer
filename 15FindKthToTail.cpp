#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
#include<stack>
struct  ListNode
{
	int value;
	ListNode* next;
};

ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
	if (pListHead == NULL || k == 0)//当头结点为空或者k等于0时
	{
		return NULL;//直接返回
	}
	ListNode *pHead1 = pListHead;//定义第一个指针等于头节点
	ListNode *pHead2 = NULL;//定义第二个指针为空
	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pHead1->next != NULL)//的一个指针的下一个不为空的时候，向后走，直到k-1的位置
		{
			pHead1 = pHead1->next;
		}
		else
		{
			return NULL;
		}
	}
	//当pHead1走到第k-1位置时，第二个指针开始向后走
	pHead2 = pListHead;//第二个指针等于头节点
	while (pHead1->next != NULL)
	{//两个指针都向后走，第一个指针走到最后时，第二个指针刚好就是倒数第K的节点
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	return pHead2;
}