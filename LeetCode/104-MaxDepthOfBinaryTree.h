#include "BinaryTree.h"

#include <algorithm>
#include <vector>
#include <iostream>

/*
Given a binary tree, find its maximum depth.
*/

class Solution_104 {
public:
	int maxDepth(TreeNode *root) {
		if (root == nullptr) { return 0; }
		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

void test_104() {
	std::vector<const char*> nv = { "3","9","20","null","null","15","7" };
	std::cout << "test_104 : " << (Solution_104().maxDepth(arr2Tree(nv)) == 3) << std::endl;
}