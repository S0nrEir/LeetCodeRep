#ifndef TREE_NODE_H
#define TREE_NODE_H

class  TreeNode
{
public:
	 TreeNode();
	 TreeNode(int x);
	 TreeNode(int x, TreeNode* left, TreeNode* right);
	~ TreeNode();

	int val;
	TreeNode* left;
	TreeNode* right;
private:

};

#endif
