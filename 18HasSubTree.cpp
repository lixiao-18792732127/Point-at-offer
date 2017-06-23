#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

bool DoesTree1HaveTree2(BinaryTreeNode* Root1, BinaryTreeNode* Root2)
{
	if (Root2 == NULL)//子树2为空的时候有，返回正确，因为空树也是一棵树的子树
	{
		return true;
	}
	if (Root1 == NULL)//如果子树1为空，则返回错误，任何树都不是空树的子树
	{
		return false;
	}
	if (Root1->_value != Root2->_value)//如果Root1的值和Root2的值不相等，返回false
	{
		return false;
	}
	return DoesTree1HaveTree2(Root1->_left, Root2->_left) && DoesTree1HaveTree2(Root1->_right, Root2->_right);//然后返回Root1和Root2的左子树和右子树
}