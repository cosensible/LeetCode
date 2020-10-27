#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_96_RC_MEMO {
	unordered_map<int, int> memo;
	int N;
public:
	int numTrees(int n) {
		N = n;
		return help(1, n);
	}

	int help(int l, int r) {
		if (l >= r) return 1;
		if (memo.find(l*N + r) != memo.end()) return memo[l*N + r];
		int ret = 0;
		for (int i = l; i <= r; ++i) {
			ret += help(l, i - 1) * help(i + 1, r);
		}
		memo[l*N + r] = ret;
		return ret;
	}
};

class Solution_96_DP {
public:
	int numTrees(int n) {
		//dp[i] 表示长度为i的序列对应的树的个数
		vector<int> dp(n + 1, 0);
		for (int l = 0; l <= n; ++l) {
			if (l < 2) {
				dp[l] = 1;
				continue;
			}
			for (int i = 1; i <= l; ++i) {
				dp[l] += dp[l - i] * dp[i - 1];
			}
		}
		return dp[n];
	}
};

void test_96() {
	Solution_96_DP s;
	cout << (s.numTrees(3) == 5) << endl;
}