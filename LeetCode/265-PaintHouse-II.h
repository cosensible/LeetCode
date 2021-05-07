/*
假如有一排房子，共 n 个，每个房子可以被粉刷成 k 种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x k 的矩阵来表示的。
进阶：您能否在 O(nk) 的时间复杂度下解决此问题？
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_265 {
public:
	int minCostII(vector<vector<int>>& costs) {
		int n = costs.size();
		if (n == 0) return 0;  // 没有房子要刷，代价为零
		int k = costs[0].size();
		if (k == 0) return -1; // 没有颜色，刷不了房子
		if (k == 1) {          // 有一种颜色，只能刷一个房子
			if (n == 1) return costs[0][0];
			return -1;
		}

		// dp[i][j]：刷 0-i 号房子，最后一个房子刷成 j 号颜色
		// dp[i][j]=min(dp[i-1][j'!=j])+costs[i][j]，只需要两个数组滚动更新
		// 求前 i-1 个房子涂色方案的最小值时，保存最小和次小涂色方案，在 i-1 的颜色与 i 冲突时，选次小方案
		vector<vector<int>> dp(2, vector<int>(k));

		// 刷到房子 i 产生最小和次小代价的颜色，刷到房子 i-1 产生最小和次小代价的颜色，min 用于更新 preMin
		int minColor1 = -1, minColor2 = -1, preMinColor1 = -1, preMinColor2 = -1;
		int minVal1 = INT_MAX, minVal2 = INT_MAX; // 最小和次小代价
		for (int i = 0; i < n; ++i) {
			minVal1 = INT_MAX, minVal2 = INT_MAX;
			for (int j = 0; j < k; ++j) {
				if (i == 0) {
					dp[1][j] = costs[0][j];
				}
				else {
					if (j == preMinColor1) {
						dp[1][j] = costs[i][j] + dp[0][preMinColor2];
					}
					else {
						dp[1][j] = costs[i][j] + dp[0][preMinColor1];
					}
				}
				// 计算刷到房子 i 产生最小和次小代价对应的颜色
				if (dp[1][j] < minVal1) {
					minColor2 = minColor1;
					minColor1 = j;
					minVal2 = minVal1;
					minVal1 = dp[1][j];
				}
				else if (dp[1][j] < minVal2) {
					minColor2 = j;
					minVal2 = dp[1][j];
				}
			}
			preMinColor1 = minColor1;
			preMinColor2 = minColor2;
			swap(dp[0], dp[1]);
		}
		return dp[0][preMinColor1];
	}
};


void test_265() {
	vector<vector<int>> costs = { {4,16},{15,5},{18,17},{10,12},{14,10},{3,10},{2,11},{18,14},{9,1},{14,13} };
	cout << (Solution_265().minCostII(costs) == 101) << endl;
}