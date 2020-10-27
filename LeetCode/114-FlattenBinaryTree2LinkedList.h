/* https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */

#include "BinaryTree.h"

class Solution_114 {
public:
	void flatten(TreeNode* root) {
		TreeNode *curNode = root;
		while (curNode) {
			if (curNode->left) {
				TreeNode *preNode = curNode->left;
				while (preNode->right) preNode = preNode->right;
				preNode->right = curNode->right;
				curNode->right = curNode->left;
				curNode->left = nullptr;
			}
			curNode = curNode->right;
		}
	}
};