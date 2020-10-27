#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

struct pair_hash
{
	template<class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& p) const
	{
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};

class Solution_494_RC_MEMO {
	unordered_map<pair<int, int>, int, pair_hash> memo;
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		if (S > 1000 || S < -1000) return 0;
		return help(nums, nums.size() - 1, S);
	}

	int help(vector<int> &nums, int back, int S) {
		if (back == -1) return S == 0 ? 1 : 0;
		pair<int, int> p{ back,S };
		if (memo.find(p) != memo.end()) return memo[p];
		int a = help(nums, back - 1, S - nums[back]);
		int b = help(nums, back - 1, S + nums[back]);
		memo[p] = a + b;
		return a + b;
	}
};

class Solution_494_DP {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int len = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (S > sum || S < -sum) return 0;
		vector<vector<int>> dp(len, vector<int>(2 * sum + 1, 0));
		if (nums[0] == 0) dp[0][sum + 0] = 2;
		else dp[0][sum - nums[0]] = dp[0][sum + nums[0]] = 1;

		for (int i = 1; i < len; ++i) {
			for (int j = 0; j <= 2 * sum; ++j) {
				int l = j - nums[i] < 0 ? 0 : j - nums[i];
				int r = j + nums[i] > 2 * sum ? 0 : j + nums[i];
				dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
			}
		}
		return dp[len - 1][sum + S];
	}
};

void test_494() {
	vector<int> vi = { 1,1 };
	cout << Solution_494_DP().findTargetSumWays(vi, 0) << endl;
}