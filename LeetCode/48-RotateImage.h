#include <vector>
#include <iostream>

using namespace std;

class Solution_48 {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n / 2; ++i) {
			swap(matrix[i], matrix[n - 1 - i]);
		}
		printDVector(matrix);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		printDVector(matrix);
	}

private:
	void printDVector(const vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				cout << matrix[i][j] << ",";
			}
			cout << endl;
		}
		cout << endl;
	}
};

void test_48() {
	vector<vector<int>> matrix = { {1,2,3 },{4,5,6},{7,8,9 } };
	Solution_48().rotate(matrix);
}