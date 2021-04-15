#include "common.h"
using namespace std;

class Solution_783 {
public:
	int minDiffInBST(TreeNode* root) {
		int ans = INT_MAX;
		TreeNode *pre = nullptr, *cur = root;
		stack<TreeNode*> stk;
		while (cur || !stk.empty()) {
			while (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			if (pre) {
				ans = min(ans, cur->val - pre->val);
			}
			pre = cur;
			cur = cur->right;
			stk.pop();
		}
		return ans;
	}
};


void test_783() {
	vector<const char *> v = { "1","0","48","null","null","12","49" };
	TreeNode *root = arr2Tree(v);
	cout << (Solution_783().minDiffInBST(root) == 1) << endl;
}