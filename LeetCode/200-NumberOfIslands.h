#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution_200 {
	int m, n;
	int count = 0;
public:
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (0 == m) return 0;
		n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] != '1') continue;
				//dfs(grid, i, j);
				bfs(grid, i, j);
				count++;
			}
		}
		return count;
	}

	void dfs(vector<vector<char>>& grid, int i, int j) {
		grid[i][j] = '2';
		if (isValid(grid, i - 1, j)) dfs(grid, i - 1, j);
		if (isValid(grid, i + 1, j)) dfs(grid, i + 1, j);
		if (isValid(grid, i, j - 1)) dfs(grid, i, j - 1);
		if (isValid(grid, i, j + 1)) dfs(grid, i, j + 1);
	}

	void bfs(vector<vector<char>>& grid, int i, int j) {
		grid[i][j] = '2';
		queue<int> q;
		q.push(i*n + j);
		while (!q.empty()) {
			int xy = q.front();
			q.pop();
			int x = xy / n, y = xy % n;
			if (isValid(grid, x - 1, y)) {
				grid[x - 1][y] = '2';
				q.push((x - 1)*n + y);
			}
			if (isValid(grid, x + 1, y)) {
				grid[x + 1][y] = '2';
				q.push((x + 1)*n + y);
			}
			if (isValid(grid, x, y - 1)) {
				grid[x][y - 1] = '2';
				q.push(x*n + y - 1);
			}
			if (isValid(grid, x, y + 1)) {
				grid[x][y + 1] = '2';
				q.push(x*n + y + 1);
			}
		}
	}

	bool isValid(vector<vector<char>>& grid, int i, int j) {
		return (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1');
	}
};

void test_200() {
	vector<vector<char>> grid = { {'1','0','1'},{'0','0','1'},{'0','0','0'} };
	int count = Solution_200().numIslands(grid);
	cout << (count == 2) << endl;
}