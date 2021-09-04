#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 如果从左上往右下进行动态规划，需要同时考虑 "最大化路径和" 和 "最小化初始值"，两者都会影响动态规划，无法进行正确的状态转移
// 因此，从右下往左上进行动态规划。令 f(i,j) 为从 (i,j) 到终点所需的最小初始值，不用考虑从起点到 (i,j) 的路径和

class Solution_174 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size(), n = dungeon[0].size();
		// 选择从右边或下面到终点所需血量的最小值，减去当前位置的值得到 f(i,j)
		// 由于骑士任何时刻血量都必须大于 0，因此要和 1 取最大值
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
		dp[m][n - 1] = 1;
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
			}
		}
		return dp[0][0];
	}
};

void test_174() {
	vector<vector<int>> dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
	cout << (Solution_174().calculateMinimumHP(dungeon) == 7) << endl;
}