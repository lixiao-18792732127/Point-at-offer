#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

void MirrorRecurisively(BinaryTreeNode* Node)
{
	if (Node == NULL || (Node->_left == NULL) && Node->_right)
	{
		return;
	}
	BinaryTreeNode *tmp = Node->_left;
	Node->_left = Node->_right;
	Node->_right = tmp;
	if (Node->_left)
	{
		MirrorRecurisively(Node->_left);
	}
	if (Node->_right)
	{
		MirrorRecurisively(Node->_right);
	}
}