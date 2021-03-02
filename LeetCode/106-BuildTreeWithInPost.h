#include "common.h"
using namespace std;

class Solution_106 {
	int postIdx;
	unordered_map<int, int> mp;
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		postIdx = postorder.size() - 1;
		// 保存节点在中序遍历序列中的索引，便于将子树分割为左右子树
		for (int i = 0; i < inorder.size(); ++i) {
			mp[inorder[i]] = i;
		}
		return helper(inorder, postorder, 0, inorder.size() - 1);
	}

	TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int l, int r) {
		if (l > r) return nullptr;
		// 先构造根节点, 再构造右子树和左子树, 与后序遍历的顺序相反, 所以 postIdx 可以递减
		int val = postorder[postIdx--];
		TreeNode *root = new TreeNode(val);
		root->right = helper(inorder, postorder, mp[val] + 1, r);
		root->left = helper(inorder, postorder, l, mp[val] - 1);
		return root;
	}
};

void test_106() {
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	TreeNode *tree = Solution_106().buildTree(inorder, postorder);
	printTree(tree);
}