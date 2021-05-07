#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_363 {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int ans = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		// 保存从左上角到每个位置 (i,j) 构成的矩形区域的和
		vector<vector<int>> nsum(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				nsum[i][j] = nsum[i - 1][j] + nsum[i][j - 1] - nsum[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
		// 列举每个右下角 (i,j)，再列举每个左上角 (ii,jj)，计算相应矩形区域的和
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int ii = 0; ii < i; ++ii) {
					for (int jj = 0; jj < j; ++jj) {
						int num = nsum[i][j] - nsum[ii][j] - nsum[i][jj] + nsum[ii][jj];
						if (num <= k) ans = max(ans, num);
					}
				}
			}
		}
		return ans;
	}
};

class Solution_FixLeftRight {
public:
	// 固定左右边界，求出边界内每行的和构成数组，求子数组的最大和 sum，满足 sum<=k
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		int ans = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < n; ++i) { // 固定左边界
			vector<int> nsum(m, 0);   // 保存边界范围内每一行的和
			for (int j = i; j < n; ++j) { // 移动右边界
				for (int k = 0; k < m; ++k) {
					nsum[k] += matrix[k][j];
				}
				set<int> presum = { 0 };
				int cursum = 0;
				for (int num : nsum) {
					cursum += num;
					auto pos = lower_bound(presum.begin(), presum.end(), cursum - k);
					if (pos != presum.end()) ans = max(ans, cursum - *pos);
					presum.insert(cursum);
				}
			}
		}
		return ans;
	}
};

class Solution_FixUpDown {
public:
	// 固定上下边界，求出边界内每列的和构成数组，求子数组的最大和 sum，满足 sum<=k
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		int ans = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; ++i) { // 固定上边界
			vector<int> nsum(n, 0);   // 保存边界范围内每一列的和
			for (int j = i; j < m; ++j) { // 移动下边界
				for (int k = 0; k < n; ++k) {
					nsum[k] += matrix[j][k];
				}
				set<int> presum = { 0 }; // 有序保存数组的前缀和，初始前缀为 0
				int cursum = 0;
				for (int num : nsum) {
					cursum += num; // 得到从头到当前位置的和
					// 找第一个满足条件的前缀和，即最小的前缀和
					auto pos = lower_bound(presum.begin(), presum.end(), cursum - k);
					if (pos != presum.end()) ans = max(ans, cursum - *pos);
					presum.insert(cursum);
				}
			}
		}
		return ans;
	}
};

void test_363() {
	vector<vector<int>> matrix = {
		{1,0,1},
		{0,-2,3}
	};
	cout << (Solution_FixUpDown().maxSumSubmatrix(matrix, 2) == 2) << endl;
}