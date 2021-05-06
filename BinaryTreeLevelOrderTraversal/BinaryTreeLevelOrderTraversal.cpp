#include "BinaryTreeLevelOrderTraversal.h"
#include "TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

BinaryTreeLevelOrderTraversal::BinaryTreeLevelOrderTraversal()
{
	cout << "BinaryTreeLevelOrderTraversal constructed" << endl;
}

BinaryTreeLevelOrderTraversal::~BinaryTreeLevelOrderTraversal()
{
	cout << "BinaryTreeLevelOrderTraversal destructed" << endl;
}

void BinaryTreeLevelOrderTraversal::Impl()
{
	TreeNode root(3);
	root.left = new TreeNode(9);
	root.right = new TreeNode(20);

	auto temp = root.right;
	temp->left = new TreeNode(15);
	temp->right = new TreeNode(7);

	TreeNode* p = &root;
	auto res = log_tree_level(p);
	auto size = res.size();
	for (int i = 0; i < size; i++)
	{
		auto subSize = res[i].size();
		for (int j = 0; j < subSize; j++)
		{
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
}

vector<vector<int>> BinaryTreeLevelOrderTraversal::log_tree_level(TreeNode* root)
{
	vector<vector<int>> _vec;
	if (root == nullptr)
		return _vec;

	vector<int> first;
	first.push_back(root->val);
	_vec.push_back(first);


	queue<TreeNode> _queue;
	if (root->left != nullptr)
		_queue.push(*root->left);

	if (root->right != nullptr)
		_queue.push(*root->right);

	while (!_queue.empty())
	{
		vector<int> next;
		vector<TreeNode> tempSave;

		while (!_queue.empty())
		{
			auto node = _queue.front();
			next.push_back(node.val);
			tempSave.push_back(node);
			_queue.pop();
		}
		
		_vec.push_back(next);
		
		auto size = tempSave.size();
		for (int i = 0; i < size; i++)
		{
			auto node = tempSave[i];
			if (node.left != nullptr)
				_queue.push(*node.left);

			if (node.right != nullptr)
				_queue.push(*node.right);
		}
		//next.push_back(node.val);
		//if (node.left != nullptr)
		//	_queue.push(*node.left);

		//if (node.right != nullptr)
		//	_queue.push(*node.right);

		//_queue.pop();
		//_vec.push_back(next);
	}
	return _vec;
}