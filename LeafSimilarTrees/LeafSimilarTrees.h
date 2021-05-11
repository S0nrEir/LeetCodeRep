#ifndef LEAF_SIMILAR_TREES_H
#define LEAF_SIMILAR_TREES_H
#include "../Entrance.h"
#include "../BinaryTreeLevelOrderTraversal/TreeNode.h"

/// <summary>
/// �뿼��һ�ö����������е�Ҷ�ӣ���ЩҶ�ӵ�ֵ�������ҵ�˳�������γ�һ�� Ҷֵ���� ��
/// </summary>
class LeafSimilarTrees : public Entrance
{
public:
	LeafSimilarTrees();
	~LeafSimilarTrees();

	virtual void Impl();

private:
	/// <summary>
	/// ����������Ҷ����ֵ�Ƿ���ȣ���ȷ���true
	/// </summary>
	bool is_leaf_similar(TreeNode* tree_1, TreeNode* tree_2);

	/// <summary>
	/// ��ȡҶ�ӽڵ�
	/// </summary>
	TreeNode get_leaf_node(TreeNode* tree);
};
#endif
