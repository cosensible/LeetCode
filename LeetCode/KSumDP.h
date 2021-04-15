#include <vector>
#include <iostream>
using namespace std;

class Solution_KSUM {
public:
	int kSum(vector<int> &nums, int k, int target) {
		// dp[i][j][t]: ��ǰi������ȡj�����ĺ�Ϊt���������
		vector<vector<vector<int>>> dp(nums.size() + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));

		for (int i = 0; i <= nums.size(); i++) dp[i][0][0] = 1;
		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 1; j <= k && j <= i; j++) {
				for (int t = 1; t <= target; t++) {
					dp[i][j][t] = dp[i - 1][j][t];
					// ��Ϊnumsֻ��������, �����nums[i-1]����tʱ�������t�ĺ�
					if (nums[i - 1] <= t) dp[i][j][t] += dp[i - 1][j - 1][t - nums[i - 1]];
				}
			}
		}
		return dp[nums.size()][k][target];
	}
};


void test_ksum() {
	vector<int> nums = { 1,2,3,4 };
	cout << (Solution_KSUM().kSum(nums, 2, 5)) << endl;
}