#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_664 {
public:
	int strangePrinter(string s) {
		int n = s.size();
		// dp[i][j] 为打印 s[i,j] 的最少次数
		// 若 s[i]==s[j]，打印 s[i] 的时候就能打印 s[j]，dp[i][j]=dp[i][j-1]
		// 若 s[i]!=s[j]，则两个字符不属于同一次打印，需将字符串分为两半，分别打印
		// 尝试每个分割点 k，取总和最小的次数
		vector<vector<int>> dp(n, vector<int>(n, n));
		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; ++j) {
				if (s[i] == s[j]) dp[i][j] = dp[i][j - 1];
				else {
					for (int k = i; k < j; ++k) {
						int cnt = dp[i][k] + dp[k + 1][j];
						dp[i][j] = min(dp[i][j], cnt);
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};


void test_664() {
	string s = "abab";
	cout << (Solution_664().strangePrinter(s) == 3) << endl;
}