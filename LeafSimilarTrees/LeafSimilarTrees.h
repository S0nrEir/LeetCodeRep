#ifndef LEAF_SIMILAR_TREES_H
#define LEAF_SIMILAR_TREES_H
#include "../Entrance.h"
#include "../BinaryTreeLevelOrderTraversal/TreeNode.h"

/// <summary>
/// 请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
/// </summary>
class LeafSimilarTrees : public Entrance
{
public:
	LeafSimilarTrees();
	~LeafSimilarTrees();

	virtual void Impl();

private:
	/// <summary>
	/// 返回两棵树叶序列值是否相等，相等返回true
	/// </summary>
	bool is_leaf_similar(TreeNode* tree_1, TreeNode* tree_2);

	/// <summary>
	/// 获取叶子节点
	/// </summary>
	TreeNode get_leaf_node(TreeNode* tree);
};
#endif
