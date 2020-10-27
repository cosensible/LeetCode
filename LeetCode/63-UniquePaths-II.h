#include <vector>
#include <iostream>

using namespace std;

class Solution_63 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = 0;
		if (m > 0) n = obstacleGrid[0].size();
		if (n == 0) return 0;
		if (obstacleGrid[0][0] == 1) return 0;

		obstacleGrid[0][0] = 1;
		for (int j = 1; j < n; ++j) { //计算到达第一行各单元的路径数
			obstacleGrid[0][j] = 1 - obstacleGrid[0][j];
			if (obstacleGrid[0][j])   //该单元不是障碍,路径数= 左+上(=0)
				obstacleGrid[0][j] = obstacleGrid[0][j - 1];
		}
		for (int i = 1; i < m; ++i) { //计算到达第一列各单元的路径数
			obstacleGrid[i][0] = 1 - obstacleGrid[i][0];
			if (obstacleGrid[i][0])   //该单元不是障碍,路径数= 左(=0)+上
				obstacleGrid[i][0] = obstacleGrid[i - 1][0];
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) { //到达其他各单元的路径数
				obstacleGrid[i][j] = 1 - obstacleGrid[i][j];
				if (obstacleGrid[i][j]) { //该单元不是障碍,路径数= 左+上
					unsigned tmp = 0; //防止路径数超过int范围
					tmp = tmp + obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
					obstacleGrid[i][j] = int(tmp);
				}
			}
		}
		return obstacleGrid[m - 1][n - 1];
	}
};

void test_63() {
	vector<vector<int>> grid = { {0,0,0 },{0,1,0},{0,0,0 } };
	cout << (Solution_63().uniquePathsWithObstacles(grid) == 2) << endl;
}