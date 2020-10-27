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
		for (int j = 1; j < n; ++j) { //���㵽���һ�и���Ԫ��·����
			obstacleGrid[0][j] = 1 - obstacleGrid[0][j];
			if (obstacleGrid[0][j])   //�õ�Ԫ�����ϰ�,·����= ��+��(=0)
				obstacleGrid[0][j] = obstacleGrid[0][j - 1];
		}
		for (int i = 1; i < m; ++i) { //���㵽���һ�и���Ԫ��·����
			obstacleGrid[i][0] = 1 - obstacleGrid[i][0];
			if (obstacleGrid[i][0])   //�õ�Ԫ�����ϰ�,·����= ��(=0)+��
				obstacleGrid[i][0] = obstacleGrid[i - 1][0];
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) { //������������Ԫ��·����
				obstacleGrid[i][j] = 1 - obstacleGrid[i][j];
				if (obstacleGrid[i][j]) { //�õ�Ԫ�����ϰ�,·����= ��+��
					unsigned tmp = 0; //��ֹ·��������int��Χ
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