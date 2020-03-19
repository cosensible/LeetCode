#include "BinaryTree.h"

/*
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards.
*/

class Solution_437 {
private:
	int count = 0;
	// 从给定节点出发，统计path数目
	void pathSumFromRoot(TreeNode *root, int target) {
		if (root == nullptr) { return; } // 终止条件：触底
		if (target == root->val) { count++; } // 得到目标，path数目+1
		// 更改目标，继续查找左子树和右子树
		pathSumFromRoot(root->left, target - root->val);
		pathSumFromRoot(root->right, target - root->val);
	}

public:
	// 先统计从根节点出发的path数，再统计从儿子出发的path数
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr) { return 0; }
		pathSumFromRoot(root, sum);
		pathSum(root->left, sum);
		pathSum(root->right, sum);
		return count;
	}
};

void test_437() {
	std::vector<const char*> nv = { "10","5","-3","3","2","null","11","3","-2","null","1" };
	TreeNode *t = arr2Tree(nv);
	std::cout << "test_437 : " << (Solution_437().pathSum(t, 8)==3) << std::endl;
}