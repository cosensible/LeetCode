#include "common.h"
using namespace std;

class Solution_105 {
	int preIdx = 0;
	unordered_map<int, int> mp;
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int m = preorder.size(), n = inorder.size();
		if (m != n || n == 0) return nullptr;
		// 保存节点在中序遍历序列中的索引，便于将子树分割为左右子树
		for (int i = 0; i < n; ++i) {
			mp[inorder[i]] = i;
		}
		return helper(preorder, inorder, 0, n - 1);
	}

	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l, int r) {
		if (l > r) return nullptr;
		// 先构造根节点, 再构造左子树和右子树, 与前序遍历的顺序一致, 所以 preIdx 可以递增
		int val = preorder[preIdx++];
		TreeNode *root = new TreeNode(val);
		root->left = helper(preorder, inorder, l, mp[val] - 1);
		root->right = helper(preorder, inorder, mp[val] + 1, r);
		return root;
	}
};

void test_105() {
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode *tree = Solution_105().buildTree(preorder, inorder);
	printTree(tree);
}