#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_1074 {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int ans = 0;
		// 枚举矩阵的上下边界，求出边界内每一列元素之和，求数组中和为 target 的子数组个数
		for (int t = 0; t < m; ++t) {
			vector<int> psum(n, 0); // 求边界内每一列元素之和
			for (int b = t; b < m; ++b) {
				for (int j = 0; j < n; ++j) {
					psum[j] += matrix[b][j];
				}
				ans += getSubArrCnt(psum, target); // 求数组中和为 target 的子数组个数
			}
		}
		return ans;
	}

private:
	int getSubArrCnt(vector<int> &nums, int target) {
		int sum = 0, ans = 0;
		unordered_map<int, int> cnt; // 保存前缀出现的次数
		cnt[0] = 1;
		for (int x : nums) {
			sum += x; // 累加形成前缀和
			if (cnt.count(sum - target) != 0)
				ans += cnt[sum - target];
			++cnt[sum];
		}
		return ans;
	}
};

void test_1074() {
	vector<vector<int>> matrix = { {1,-1},{-1,1} };
	int target = 0;
	cout << (Solution_1074().numSubmatrixSumTarget(matrix, target) == 5) << endl;
}