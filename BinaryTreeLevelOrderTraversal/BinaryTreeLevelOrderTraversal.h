#ifndef BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "../Entrance.h"
#include "TreeNode.h"
#include <vector>

using namespace std;

//����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
//
//ʾ����
//��������[3, 9, 20, null, null, 15, 7],
//
// 3
/// \
//9  20
//   / \
//  15  7
//�����������������
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
