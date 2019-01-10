#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
//965. Univalued Binary Tree
//Easy
//
//A binary tree is univalued if every node in the tree has the same value.
//Return true if and only if the given tree is univalued.
//
//Example 1:
//
//Input: [1, 1, 1, 1, 1, null, 1]
//	Output : true
//	Example 2 :
//
//	Input : [2, 2, 2, 5, 2]
//	Output : false
//
//	Note :
//	The number of nodes in the given tree will be in the range[1, 100].
//	Each node's value will be an integer in the range [0, 99].
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (root)
		{
			return isUnivalTree(root, root->val);
		}

		return false;
	}

	bool isUnivalTree(TreeNode* root, int val)
	{
		if (root && root->val == val)
		{
			return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
		}
		else if (!root)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};