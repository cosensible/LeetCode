#include "common.h"
using namespace std;

class Solution_95 {
	vector<vector<vector<TreeNode*>>> memo;
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n < 1) return {};
		// ��[i,j]��������ʱ, ��iΪ���ڵ�, ������Ϊ[i,i-1], ��Ӧnull;
		// ��jΪ���ڵ�, ������Ϊ[j+1,j], ��Ӧnull
		// [1,0] �� [n+1,n] �ֱ��Ӧ����������������������, ��Ϊnull
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