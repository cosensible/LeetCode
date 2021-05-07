#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_131 {
	vector<vector<string>> res;
public:
	// 先用动态规划求出所有子串是否为回文串，再用回溯法从前往后切割形成回文子串
	vector<vector<string>> partition(string s) {
		int n = s.size();
		if (n == 0) return res;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i + k < n; ++i) {
				if (k == 0) dp[i][i] = true;
				else if (k == 1) dp[i][i + 1] = s[i] == s[i + 1];
				else dp[i][i + k] = s[i] == s[i + k] && dp[i + 1][i + k - 1];
			}
		}
		vector<string> path;
		dfs(s, dp, 0, path);
		return res;
	}

private:
	void dfs(string &s, vector<vector<bool>> &dp, int i, vector<string> &path) {
		if (i == s.size()) {
			res.push_back(path);
			return;
		}
		// 列举切割位置
		for (int k = i; k < s.size(); ++k) {
			if (dp[i][k]) {
				path.push_back(s.substr(i, k - i + 1));
				dfs(s, dp, k + 1, path);
				path.pop_back();
			}
		}
	}
};


void test_131() {
	auto ans = Solution_131().partition("aab");
	for (auto &v : ans) {
		for (auto &s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
}