#include "common.h"
using namespace std;

class Solution_129 {
	int res = 0; // 保存数字之和
	int num = 0; // 保存当前数字
public:
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) return 0;
		// 处理当前节点
		num = num * 10 + root->val;
		// 如果当前节点为叶节点, 累加res, 还原num, 并返回上一层
		if (root->left == nullptr&&root->right == nullptr) {
			res += num;
			num /= 10;
			return res;
		}
		// 不是叶节点, 递归处理左子树和右子树
		if (root->left) sumNumbers(root->left);
		if (root->right) sumNumbers(root->right);
		num /= 10; // 左右儿子都处理完了, 返回上一层处理
		return res;
	}
};

void test_129() {
	vector<const char*> vi = { "4","9","0","5","1" };
	TreeNode *tree = arr2Tree(vi);
	cout << (Solution_129().sumNumbers(tree) == 1026) << endl;
}