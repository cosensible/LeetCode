#include "common.h"

using namespace std;

class Solution_124 {
	int maxSum = INT_MIN;
public:
	// 最长路径由三部分组成：左上升 + 顶点 + 右下降
	// 求每个节点作为顶点所得最长路径的最大值
	// 需要求出左上升和右下降部分的长度
	int maxPathSum(TreeNode* root) {
		if (root == nullptr) { return 0; }
		helper(root);
		return maxSum;
	}

private:
	// 返回从 root 节点往下走能够获得的最长路径
	int helper(TreeNode *root) {
		if (root == nullptr) { return 0; }
		// 往最大方向走, 若左右都 <0, 则不再往下走
		// 递归计算左右子树往下走的最长路径
		int lsum = max(helper(root->left), 0);
		int rsum = max(helper(root->right), 0);
		// 求每个节点作为顶点能够产生的最长路径
		maxSum = max(maxSum, lsum + rsum + root->val);
		return root->val + max(lsum, rsum);
	}
};

void test_124() {
	vector<const char*> nodes = { "-10","9","20","null","null","15","7" };
	TreeNode *tree = arr2Tree(nodes);
	cout << (Solution_124().maxPathSum(tree) == 42) << endl;
}