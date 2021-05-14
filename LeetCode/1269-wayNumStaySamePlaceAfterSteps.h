#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1269 {
	const int MOD = 1e9 + 7;
public:
	int numWays(int steps, int arrLen) {
		int idxNum = min(arrLen, steps + 1); // // 最远能走到 arrLen-1 或 steps
		vector<vector<int>> dp(steps + 1, vector<int>(idxNum)); // dp[i][j]: 走 i 步到 j 的方案数
		dp[0][0] = 1; // 初始位置为 0, 不需要走就能到
		for (int i = 1; i <= steps; ++i) {
			for (int j = 0; j < idxNum; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
				if (j < idxNum - 1) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
			}
		}
		return dp[steps][0];
	}
};

class Solution_1269_Better {
	const int MOD = 1e9 + 7;
public:
	int numWays(int steps, int arrLen) {
		int idxNum = min(arrLen, steps / 2 + 1); // 最远能走到 arrLen-1 或 steps/2, 因为走太远了回不到初始位置
		vector<int> dp(idxNum); // dp 的每一行只和上一行有关
		dp[0] = 1;
		for (int i = 1; i <= steps; ++i) {
			vector<int> dpNext(idxNum);
			for (int j = 0; j < idxNum; ++j) {
				dpNext[j] = dp[j];
				if (j > 0) dpNext[j] = (dpNext[j] + dp[j - 1]) % MOD;
				if (j < idxNum - 1) dpNext[j] = (dpNext[j] + dp[j + 1]) % MOD;
			}
			swap(dp, dpNext);
		}
		return dp[0];
	}
};


void test_1269() {
	cout << (Solution_1269().numWays(4, 2) == 8) << endl;
}