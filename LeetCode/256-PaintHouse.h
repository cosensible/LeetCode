/*
假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的矩阵来表示的。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_256 {
public:
	int minCost(vector<vector<int>>& costs) {
		int m = costs.size(), n = costs[0].size();
		// dp[i][j]：刷 0-i 号房子，最后一个房子刷成 j 号颜色
		// dp[i][j]=min(dp[i-1][j'!=j])+costs[i][j]，只需要两个数组滚动更新
		vector<vector<int>> dp(2, vector<int>(n));
		for (int j = 0; j < n; ++j) { dp[0][j] = costs[0][j]; }

		for (int i = 1; i < m; ++i) {
			dp[1].assign(n, INT_MAX); // 每次计算需重置为最大值
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					if (k == j) continue;
					dp[1][j] = min(dp[0][k], dp[1][j]);
				}
				dp[1][j] += costs[i][j];
			}
			swap(dp[0], dp[1]);
		}
		int ans = *min_element(dp[0].begin(), dp[0].end());
		return ans;
	}
};


void test_256() {
	vector<vector<int>> costs = { {17, 2, 17},{16, 16, 5},{4, 3, 19} };
	cout << (Solution_256().minCost(costs) == 10) << endl;
}