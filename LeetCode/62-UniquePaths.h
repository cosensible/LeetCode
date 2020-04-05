#include <vector>
#include <iostream>

using namespace std;

class Solution_62 {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> mp(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
			}
		}
		return mp[m - 1][n - 1];
	}
};

void test_62() {
	cout << (Solution_62().uniquePaths(3, 2) == 3) << endl;
}