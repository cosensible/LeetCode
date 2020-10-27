#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution_64 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (i == 0 && j > 0)
					grid[i][j] += grid[i][j - 1];
				else if (j == 0 && i > 0)
					grid[i][j] += grid[i - 1][j];
				else if (i > 0 && j > 0)
					grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[grid.size() - 1][grid[0].size() - 1];
	}

	int minPathSum_1(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		if (n == 0) return 0;

		vector<vector<pair<char, int>>> path(m, vector<pair<char, int>>(n));
		path[0][0] = { ' ',grid[0][0] };
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j > 0) {
					path[i][j] = { 'r',grid[i][j] };
					grid[i][j] += grid[i][j - 1];
				}
				else if (j == 0 && i > 0) {
					path[i][j] = { 'd',grid[i][j] };
					grid[i][j] += grid[i - 1][j];
				}
				else if (i > 0 && j > 0) {
					if (grid[i][j - 1] < grid[i - 1][j]) {
						path[i][j] = { 'r',grid[i][j] };
						grid[i][j] += grid[i][j - 1];
					}
					else {
						path[i][j] = { 'd',grid[i][j] };
						grid[i][j] += grid[i - 1][j];
					}
				}
			}
		}
		vector<int> paths;
		for (int i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
			paths.push_back(path[i][j].second);
			if (path[i][j].first == 'r') { j--; }
			else { i--; }
		}
		for (auto it = paths.rbegin(); it != paths.rend(); ++it) {
			cout << *it << ",";
		}
		cout << endl;
		return grid[m - 1][n - 1];
	}
};

void test_64() {
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	int res = 7;
	cout << "result = " << (Solution_64().minPathSum_1(grid) == 7) << endl;
}