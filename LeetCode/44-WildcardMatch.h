#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_44 {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
		dp[0][0] = true;
		for (int j = 1; j <= n && p[j - 1] == '*'; ++j) {
			dp[0][j] = true;
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				// 星号可以匹配零或任意个小写字母，状态转移方程有两种情况，即使用或不使用星号
				// 不使用星号，dp[i][j]=dp[i][j-1]
				// 使用星号，则消去 s 中的一个字符，dp[i][j]=dp[i-1][j]
				// 由于星号保留，可以选择继续消去 s 中的字符，所以 dp[i][j]=dp[i-1][j] 可行
				else if (p[j - 1] == '*') {
					//for (int k = i; k >= 0; --k) {
					//	if (dp[k][j - 1]) {
					//		dp[i][j] = true;
					//		break;
					//	}
					//}

					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
				}
			}
		}
		return dp[m][n];
	}
};


class Solution_44_ScrollArr {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<int> dp(n + 1, false);  // 记录上一层状态
		vector<int> cdp(n + 1, false); // 记录下一层状态
		dp[0] = true;
		for (int j = 1; j <= n && p[j - 1] == '*'; ++j) {
			dp[j] = true;
		}

		for (int i = 1; i <= m; ++i) {
			cdp.assign(n + 1, false); // 重置 cdp 数组的状态，包含初始化 cdp[0]=false
			for (int j = 1; j <= n; ++j) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					cdp[j] = dp[j - 1];
				}
				// 星号可以匹配零或任意个小写字母，状态转移方程有两种情况，即使用或不使用星号
				// 不使用星号，dp[i][j]=dp[i][j-1]
				// 使用星号，则消去 s 中的一个字符，dp[i][j]=dp[i-1][j]
				// 由于星号保留，可以选择继续消去 s 中的字符，所以 dp[i][j]=dp[i-1][j] 可行
				else if (p[j - 1] == '*') {
					cdp[j] = cdp[j - 1] || dp[j];
				}
			}
			swap(dp, cdp);
		}
		return dp[n];
	}
};


void test_44() {
	string s = "abcdefde", p = "abc*def";
	cout << (Solution_44_ScrollArr().isMatch(s, p)) << endl;
}