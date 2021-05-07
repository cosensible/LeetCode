#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution_1473 {
	const int INF = 1e6 + 1; // 房子数 <=100，涂一个房子的最大代价为 1e4，故刷所有房子的最大代价为 1e6
public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		for (int i = 0; i < m; ++i) { --houses[i]; } // 使 houses 颜色与 cost 数组中的颜色相匹配
		// dp[i][j][k]：刷 0~i 号房子，使第 i 号房子的颜色为 j，且属于第 k 个街区的最小代价
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INF)));
		for (int j = 0; j < n; ++j) { // 只有一个房子，只能构成一个街区
			if (houses[0] == -1) dp[0][j][0] = cost[0][j];
			else if (houses[0] == j) dp[0][j][0] = 0;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				// 房子有颜色但和目标颜色不一样，非法
				if (houses[i] != -1 && houses[i] != j) continue;
				for (int k = 0; k < target; ++k) {
					// 前后房子颜色相同也构成一种方案，该方案的街区数不变，房子颜色不同导致街区数相差 1
					for (int pj = 0; pj < n; ++pj) {
						if (pj == j) {
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
						}
						else if (k > 0) {
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][pj][k - 1]);
						}
					}
					// 房子有颜色且和目标颜色一致，不需要加上粉刷代价；房子无颜色，需要加上粉刷代价
					if (houses[i] == -1) {
						dp[i][j][k] += cost[i][j];
					}
				}
			}
		}

		int ans = INF;
		for (int j = 0; j < n; ++j) {
			ans = min(ans, dp[m - 1][j][target - 1]);
		}
		return ans == INF ? -1 : ans;
	}
};


void test_1473() {
	vector<int> houses = { 0,2,1,2,0 };
	vector<vector<int>> cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
	int m = 5, n = 2, target = 3;
	cout << (Solution_1473().minCost(houses, cost, m, n, target) == 11) << endl;
}