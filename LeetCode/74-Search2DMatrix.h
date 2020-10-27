#include <vector>
#include <iostream>

using namespace std;

class Solution_74 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) return false;
		int col = matrix[0].size();
		if (col == 0) return false;

		int t = 0, b = row - 1;
		while (t <= b) {
			int m = (t + b) >> 1;
			if (matrix[m][0] > target) { b = m - 1; }
			else if (matrix[m][0] < target) { t = m + 1; }
			else { return true; }
		}
		if (b < 0) return false;
		int l = 0, r = col - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (matrix[b][m] > target) { r = m - 1; }
			else if (matrix[b][m] < target) { l = m + 1; }
			else { return true; }
		}
		return false;
	}
};


// 把二维数组看成一维数组
class Solution_74_1 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) return false;
		int col = matrix[0].size();

		int l = 0, r = row * col - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (matrix[m / col][m%col] > target) { r = m - 1; }
			else if (matrix[m / col][m%col] < target) { l = m + 1; }
			else { return true; }
		}
		return false;
	}
};

void test_74() {
	vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
	int target = 3;
	cout << Solution_74().searchMatrix(matrix, target) << endl;
}