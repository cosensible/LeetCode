#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution_322_RC {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return amount == 0 ? 0 : -1;
		if (amount < 0) return -1;
		if (amount == 0) return 0;
		int res = INT_MAX;
		for (int coin : coins) {
			int num = coinChange(coins, amount - coin);
			if (num == -1) continue;
			res = min(res, num + 1);
		}
		return res == INT_MAX ? -1 : res;
	}
};

class Solution_322_RC_MEMO {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return amount == 0 ? 0 : -1;
		if (amount < 0) return -1;
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		return help(dp, coins, amount);
	}

	int help(vector<int>& dp, vector<int>& coins, int amount) {
		if (amount < 0) return -1;
		if (dp[amount] < INT_MAX) return dp[amount];
		int ret = INT_MAX;
		for (int coin : coins) {
			int num = help(dp, coins, amount - coin);
			if (num == -1) continue;
			ret = min(ret, num + 1);
		}
		dp[amount] = (ret == INT_MAX ? -1 : ret);
		return dp[amount];
	}
};

class Solution_322_DP {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return amount == 0 ? 0 : -1;
		if (amount < 0) return -1;
		vector<int> dp(amount + 1, amount + 1); //最多需要 amount 枚硬币
		dp[0] = 0;

		for (int i = 1; i <= amount; ++i) {
			for (int coin : coins) {
				if (i < coin) continue;
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};

void test_322() {
	vector<int> vi = { 1, 2, 5 }, vi1 = { 2 };
	int amount = 11, amount1 = 3;
	cout << (Solution_322_DP().coinChange(vi1, amount1) == -1) << endl;
}