 //在O(1)时间删除链表结点
//给定单项链表的头指针和一个结点指针，定义一个函数
//在O(1)时间删除该结点。
#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* next;
};
void DeleteNode(ListNode** pListHead, ListNode* pToBeDelete)
{
	if (!pListHead || !pToBeDelete)//如果头结点为空或者将要删除的节点为空，就返回
	{
		return;
	}
	if (pToBeDelete->next != NULL)
	{
		ListNode* pNext = pToBeDelete->next;
		pToBeDelete->_value = pNext->_value;
		pToBeDelete->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->next != pToBeDelete)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
		delete pToBeDelete;
		pToBeDelete = NULL;
	}
}
