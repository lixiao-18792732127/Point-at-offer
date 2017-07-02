#include<iostream>
using namespace std;
#include<vector>
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

};

void FindPath(BinaryTreeNode* root, int exp)
{
	if (root == NULL)
	{
		return;
	}
	std::vector<int> path;
	int curr = 0;
	FindPath(root, exp, path, curr);
}

void FindPath(BinaryTreeNode* root, int exp, std::vector<int>& path, int& curr)
{
	curr += root->_value;
	path.push_back(root->_value);

	bool isLeaf = root->_left == NULL&&root->_right == NULL;
	if (curr == exp&&isLeaf)
	{
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
		{
			printf("%d\t", *iter);
		}
		printf("\n");
	}
	if (root->_left != NULL)
	{
		FindPath(root->_left, exp, path, curr);
	}
	if (root->_right != NULL)
	{
		FindPath(root->_right, exp, path, curr);
	}
	curr -= root->_value; path.pop_back();
}