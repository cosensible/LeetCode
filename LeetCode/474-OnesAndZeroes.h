#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_474 {
public:
	// f[i][j][k]：前 i 个元素，0 和 1 的上限分别为 j 和 k 时，最大子集的大小
	// 选第 i 个元素，0 和 1 的上限减少，子集大小加一
	// 不选第 i 个元素，0 和 1 上限不变，子集大小不变
	// 状态压缩，可以减少一个维度
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (string &s : strs) {
			int cnt0 = 0, cnt1 = 0;
			for (char c : s) {
				if (c == '0') ++cnt0;
			}
			cnt1 = s.size() - cnt0;

			for (int i = m; i >= cnt0; --i) {
				for (int j = n; j >= cnt1; --j) {
					dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
				}
			}
		}
		return dp[m][n];
	}
};

void test_474() {
	vector<string> strs = { "10", "0001", "111001", "1", "0" };
	int m = 5, n = 3;
	cout << (Solution_474().findMaxForm(strs, m, n) == 4) << endl;
}