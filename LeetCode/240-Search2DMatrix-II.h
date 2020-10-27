#include <vector>
#include <iostream>

using namespace std;

class Solution_240 {
public:
	// 右上角元素: 行最大, 列最小
	// 若target>右上角, 忽略行; 若target<右上角, 忽略列
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) return false;
		int col = matrix[0].size();

		int r = col - 1, t = 0;
		while (r >= 0 && t < row) {
			if (matrix[t][r] < target) { ++t; }
			else if (matrix[t][r] > target) { --r; }
			else { return true; }
		}
		return false;
	}
};

void test_240() {
	vector<vector<int>> matrix = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	int target = 8;
	cout << Solution_240().searchMatrix(matrix, target) << endl;
}