#include<iostream>
using namespace std;
struct Node
{
	int _value;
	Node* _left;
	Node* _right;
};
void Convert(Node* root, Node*& prevNode)
{
	if (root == NULL)
	{
		return;
	}
	Convert(root->_left, prevNode);
	root->_left = prevNode;
	if (prevNode)
	{
		prevNode->_right = root;
	}
	prevNode = root;
	Convert(root->_right, prevNode);
}