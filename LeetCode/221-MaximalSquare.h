#include <vector>
#include <iostream>

using namespace std;

/* https://leetcode.com/problems/maximal-square/ */

class Solution_221_MYDP {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = 0, area = 0;
		if (m > 0) n = matrix[0].size();
		int ml = m > n ? n : m;

		vector<vector<int>> dp(m, vector<int>(n, 0));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j] = matrix[i][j] - '0';
				if (dp[i][j]) area = 1;
			}
		}

		for (int l = 2; l <= ml; ++l) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (0 == dp[i][j]) continue;
					int test = 1;
					for (int k = 0; k <= dp[i][j]; ++k) {
						if (i + dp[i][j] >= m || j + dp[i][j] >= n) {
							test = 0;
							break;
						}
						test &= (matrix[i + dp[i][j]][j + k] - '0');
						test &= (matrix[i + k][j + dp[i][j]] - '0');
						if (!test) break;
					}
					if (test) {
						dp[i][j] += 1;
						area = dp[i][j] * dp[i][j];
					}
					else {
						dp[i][j] = 0;
					}
				}
			}
		}
		return area;
	}
};


class Solution_221_DP {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = 0, maxlen = 0;
		if (m > 0) n = matrix[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (matrix[i - 1][j - 1] == '0') continue;
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				maxlen = max(maxlen, dp[i][j]);
			}
		}
		return maxlen * maxlen;
	}
};

void test_221() {
	vector<vector<char>> matrix = {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'} };
	cout << (Solution_221_DP().maximalSquare(matrix) == 4) << endl;
}