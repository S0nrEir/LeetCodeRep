#include "LeafSimilarTrees.h"
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include "../BinaryTreeLevelOrderTraversal/TreeNode.h"

using namespace std;

LeafSimilarTrees::LeafSimilarTrees()
{
	cout << "LeafSimilarTrees Constructed" << endl;
}

LeafSimilarTrees::~LeafSimilarTrees()
{
	cout << "LeafSimilarTrees Destructed" << endl;
}

void LeafSimilarTrees::Impl()
{
	TreeNode root_1(3);
	root_1.left = new TreeNode(5);
	root_1.right = new TreeNode(1);

	auto node = root_1.right;
	node->left = new TreeNode(9);
	node->right = new TreeNode(8);

	node = root_1.left;
	node->left = new TreeNode(6);
	node->right = new TreeNode(2);

	node = node->right;
	node->left = new TreeNode(7);
	node->right = new TreeNode(4);


	TreeNode root_2(3);
	root_2.left = new TreeNode(5);
	root_2.right = new TreeNode(1);

	node = root_2.left;
	node->left = new TreeNode(6);
	node->right = new TreeNode(7);

	node = root_2.right;
	node->left = new TreeNode(4);
	node->right = new TreeNode(2);

	node = node->right;
	node->left = new TreeNode(9);
	node->right = new TreeNode(8);

	cout << "is similar " << is_leaf_similar(&root_1, &root_2) << endl;
}

bool LeafSimilarTrees::is_leaf_similar(TreeNode* tree_1, TreeNode* tree_2)
{
	stack<TreeNode> treeStack;
	treeStack.push(*tree_1);

	vector<int> vec_1;
	vector<int> vec_2;

	while (!treeStack.empty())
	{
		auto temp = treeStack.top();
		treeStack.pop();

		if (temp.left == nullptr && temp.right == nullptr)
			vec_1.push_back(temp.val);

		if (temp.right != nullptr)
			treeStack.push(*temp.right);

		if (temp.left != nullptr)
			treeStack.push(*temp.left);
	}

	//clear stack
	while (!treeStack.empty())
		treeStack.pop();

	treeStack.push(*tree_2);
	while (!treeStack.empty())
	{
		auto temp = treeStack.top();
		treeStack.pop();

		if (temp.left == nullptr && temp.right == nullptr)
			vec_2.push_back(temp.val);

		if (temp.right != nullptr)
			treeStack.push(*temp.right);

		if (temp.left != nullptr)
			treeStack.push(*temp.left);
	}

	auto size_1 = vec_1.size();
	auto size_2 = vec_2.size();

	if (size_1 != size_2)
		return false;

	for (int i=0 ; i < size_1 && i < size_2 ; i++ )
	{
		if (vec_1[i] != vec_2[i])
			return false;
	}

	return true;
}

TreeNode LeafSimilarTrees::get_leaf_node(TreeNode* tree)
{
	return NULL;
}

