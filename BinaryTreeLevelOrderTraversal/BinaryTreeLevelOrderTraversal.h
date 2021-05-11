#ifndef BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "../Entrance.h"
#include "TreeNode.h"
#include <vector>

using namespace std;

//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
//
//示例：
//二叉树：[3, 9, 20, null, null, 15, 7],
//
// 3
/// \
//9  20
//   / \
//  15  7
//返回其层序遍历结果：
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]
class BinaryTreeLevelOrderTraversal : public Entrance
{
public:
	BinaryTreeLevelOrderTraversal();
	~BinaryTreeLevelOrderTraversal();

	virtual void Impl();
private:
	vector<vector<int>> log_tree_level(TreeNode *root);
};

//Definition for a binary tree node.
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};


#endif
