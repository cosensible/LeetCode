#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution_120_DP {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 0) return 0;
		// dp[i][j]：从上往下到达第 i 行第 j 个位置的最小路径和
		vector<vector<int>> dp(n, vector<int>(n));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			// 第 i 行只有 0~i 个位置，i 从零开始编号
			for (int j = 0; j <= i; ++j) {
				if (j == i) dp[i][j] = dp[i - 1][j - 1];
				else if (j == 0) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
				dp[i][j] += triangle[i][j];
			}
		}
		return *min_element(dp[n - 1].begin(), dp[n - 1].end());
	}
};

class Solution_120_ScrollArr {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 0) return 0;
		vector<int> dp(n);
		dp[0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			// 第 i 行有 0~i 个位置，i 从 0 开始
			dp[i] = dp[i - 1] + triangle[i][i]; // j==i
			for (int j = i - 1; j > 0; --j) {
				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
			dp[0] += triangle[i][0]; // j==0
		}
		return *min_element(dp.begin(), dp.end());
	}
};


void test_120() {
	vector<vector<int>> triangle = {
	{2},
	{3,4},
	{6,5,7},
	{4,1,8,3} };

	cout << (Solution_120_ScrollArr().minimumTotal(triangle) == 11) << endl;
}