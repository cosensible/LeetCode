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
};

void test_64() {
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	int res = 7;
	cout << (Solution_64().minPathSum(grid) == 7) << endl;
}