#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


// 初始步长为 0，每经过一块石头 k 才有可能加一，最后一块石头不必加一，故 k 的最大值为 snum-1
// 因此，memo 中记录 <sid,k> 的结果可以用 sid*snum + k 作为键
class Solution_403 {
	int snum; // 石头的总数
	unordered_map<int, int> mp; // 每个位置对应的石头的编号
	unordered_map<int, int> memo;
public:
	bool canCross(vector<int>& stones) {
		snum = stones.size();
		for (int i = 0; i < snum; ++i) mp[stones[i]] = i;
		return dfs(stones, 0, 0); // 从第 0 块石头开始，到达步长为 0
	}

private:
	// 以步长 k 跳到编号为 sid 的石头，最终能否到达最后一块石头
	bool dfs(vector<int> &stones, int sid, int k) {
		if (sid == snum - 1) return true; // 到达最后一块石头
		if (memo.count(sid*snum + k) == 1) return memo[sid*snum + k];
		memo[sid*snum + k] = false; // 初始化
		for (int i = -1; i <= 1; ++i) {
			if (k + i <= 0) continue; // 无法前进，跳过
			int pos = stones[sid] + k + i;
			if (mp.count(pos) != 0) { // 新的位置有石头，可以跳过去
				if (dfs(stones, mp[pos], k + i)) {
					memo[sid*snum + k] = true;
					return true;
				}
			}
		}
		return false;
	}
};


class Solution_403_DP {
public:
	bool canCross(vector<int>& stones) {
		int n = stones.size();
		// dp[s][k] 能否以步长 k 跳到石头 s
		vector<vector<bool>> dp(n, vector<bool>(n));
		dp[0][0] = true;
		// 存在两块相邻的石头，距离大于该跳的最大步长
		for (int i = 1; i < n; ++i) {
			if (stones[i] - stones[i - 1] > i) {
				return false;
			}
		}
		for (int i = 1; i < n; ++i) { // 从左到右列举每块石头
			for (int j = i - 1; j >= 0; --j) { // 列举前面的石头
				int k = stones[i] - stones[j]; // 前一块石头到后一块石头的距离
				if (k > j + 1) { // 第 j 块石头处最大的步长为 j+1
					break;
				}
				dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
				// 列举到最后一块石头，且找到可以到达最后石头的前一块石头
				if (i == n - 1 && dp[i][k]) {
					return true;
				}
			}
		}
		return false;
	}
};


void test_403() {
	vector<int> stones = { 0,1,3,5,6,8,12,17 };
	cout << (Solution_403_DP().canCross(stones) == true) << endl;
}