#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution_1738 {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int m = matrix.size();
		if (m == 0) return -1;
		int n = matrix[0].size();
		if (n == 0) return -1;
		if (k<1 || k>m*n) return -1;

		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i > 0) matrix[i][j] ^= matrix[i - 1][j];
				if (j > 0) matrix[i][j] ^= matrix[i][j - 1];
				if (i > 0 && j > 0) matrix[i][j] ^= matrix[i - 1][j - 1];
				if (pq.size() == k && pq.top() >= matrix[i][j]) continue;
				pq.push(matrix[i][j]);
				if (pq.size() > k) {
					pq.pop();
				}
			}
		}
		return pq.top();
	}
};


void test_1738() {
	vector<vector<int>> matrix = { {5,2},{1,6} };
	cout << (Solution_1738().kthLargestValue(matrix, 2) == 5) << endl;
}