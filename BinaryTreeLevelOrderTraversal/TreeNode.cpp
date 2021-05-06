#include "TreeNode.h"
#include <iostream>

using namespace std;

TreeNode::TreeNode()
{
	val = 0;
	left = nullptr;
	right = nullptr;
}

TreeNode::TreeNode(int x)
{
	val = x;
	left = nullptr;
	right = nullptr;
}

TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right)
{
	val = x;
	this->left = left;
	this->right = right;
}

TreeNode::~TreeNode()
{

}

