#include "common.h"
using namespace std;

class Solution_156 {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		// 树为空或叶节点，无需翻转
		if (!root || !root->left && !root->right) return root;
		// 右子树要么为空要么为叶节点，翻转后只能作为左叶节点，因此只需遍历左子树
		// 递归遍历左子树，翻转树的根节点在左子树中
		TreeNode *newRoot = upsideDownBinaryTree(root->left);
		// 每次递归左子树返回后，根节点的左右儿子还未被改变，可利用父子关系将上层节点翻转
		root->left->left = root->right;
		root->left->right = root;
		root->left = root->right = nullptr;
		return newRoot;
	}
};


void test_156() {
	vector<const char*> v = { "1","2","3","4","5" };
	TreeNode *tree = arr2Tree(v);
	TreeNode *ans = Solution_156().upsideDownBinaryTree(tree);
	printTree(ans);
}