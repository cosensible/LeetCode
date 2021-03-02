#include "common.h"
using namespace std;

class Solution_95 {
	vector<vector<vector<TreeNode*>>> memo;
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n < 1) return {};
		// 用[i,j]构造子树时, 当i为根节点, 左子树为[i,i-1], 对应null;
		// 当j为根节点, 右子树为[j+1,j], 对应null
		// [1,0] 和 [n+1,n] 分别对应最左左子树和最右右子树, 均为null
		memo.resize(n + 2, vector<vector<TreeNode*>>(n + 2));
		for (int i = 1; i <= n + 1; ++i) {
			// memo[i][i].emplace_back(new TreeNode(i));
			memo[i][i - 1].emplace_back(nullptr);
		}
		for (int l = 1; l <= n; ++l) {
			for (int i = 1; i <= n - l + 1; ++i) {
				int j = i + l - 1;
				for (int k = i; k <= j; ++k) {
					for (auto p1 : memo[i][k - 1]) {
						for (auto p2 : memo[k + 1][j]) {
							memo[i][j].emplace_back(new TreeNode(k, p1, p2));
						}
					}
				}
			}
		}
		return memo[1][n];
	}
};

void test_95() {
	vector<TreeNode*> res = Solution_95().generateTrees(3);
	for (auto p : res) {
		printTree(p);
	}
}