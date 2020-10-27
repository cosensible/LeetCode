#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_647_DP {
public:
	int countSubstrings(const string &s) {
		int n = s.size(), res = 0;
		if (0 == n) return 0;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for (int l = 0; l < n; ++l) {
			for (int i = 0; i + l < n; ++i) {
				if (0 == l) {
					dp[i][i] = true;
				}
				else if (l == 1) {
					dp[i][i + 1] = (s[i] == s[i + 1]);
				}
				else {
					dp[i][i + l] = (s[i] == s[i + l] && dp[i + 1][i + l - 1]);
				}
				if (dp[i][i + l]) ++res;
			}
		}
		return res;
	}
};

class Solution_647_EXPAND {
public:
	int countSubstrings(const string &s) {
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			res += expand(s, i, i);
			res += expand(s, i, i + 1);
		}
		return res;
	}

private:
	int expand(const string &s, int l, int r) {
		int ret = 0;
		while (l >= 0 && r < s.size()) {
			if (s[l] != s[r]) break;
			++ret;
			--l;
			++r;
		}
		return ret;
	}
};

void test_647() {
	string s1 = "abc", s2 = "aaa";
	Solution_647_EXPAND sol;
	cout << (sol.countSubstrings(s1) == 3 && sol.countSubstrings(s2) == 6) << endl;
}