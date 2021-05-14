#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_93_ScrollingArr {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size(), n = s2.size();
		if (m + n != s3.size()) return false;
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i > 0) dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]);
				if (j > 0) dp[j] = dp[j] || (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
			}
		}
		return dp[n];
	}
};

class Solution_93_DP {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size(), n = s2.size();
		if (m + n != s3.size()) return false;
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i > 0)
					dp[i][j] = dp[i][j] || (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]);
				if (j > 0)
					dp[i][j] = dp[i][j] || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
			}
		}
		return dp[m][n];
	}
};


void test_97() {
	//string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
	cout << (Solution_93_DP().isInterleave(s1, s2, s3) == false) << endl;
}