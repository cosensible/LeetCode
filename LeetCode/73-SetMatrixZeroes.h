#include <iostream>
#include <vector>
using namespace std;

class Solution_73_M_N {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		if (n == 0) return;
		// �ֱ��¼�������Щ�к���Щ����Ҫ����
		vector<bool> rows(m, false);
		vector<bool> cols(n, false);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					rows[i] = true;
					cols[j] = true;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			if (rows[i]) matrix[i].assign(n, 0);
		}
		for (int j = 0; j < n; ++j) {
			if (cols[j]) {
				for (int i = 0; i < m; ++i) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

class Solution_73_Const {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		if (n == 0) return;
		// �����ö���ռ䣬�þ���ĵ�һ�к͵�һ�м�¼��Щ�к���Щ����Ҫ����
		// ��ȷ����һ�к͵�һ���Ƿ�ԭ���ʹ��� 0��������¼���ܻὫ��Ԫ������
		// ��¼ʣ�µ��к����Ƿ���Ҫ���㣬�����ݼ�¼����Ӧ�к�������
		// ���ݵ�һ�к͵�һ���Ƿ�ԭ���ʹ��� 0�������Ƿ�������
		bool row0_zero = false, col0_zero = false;
		for (int i = 0; i < m && !col0_zero; ++i) {
			if (matrix[i][0] == 0) col0_zero = true;
		}
		for (int j = 0; j < n && !row0_zero; ++j) {
			if (matrix[0][j] == 0) row0_zero = true;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (row0_zero) {
			matrix[0].assign(n, 0);
		}
		if (col0_zero) {
			for (int i = 0; i < m; ++i) {
				matrix[i][0] = 0;
			}
		}
	}
};


void test_73() {
	vector<vector<int>> matrix = { {0, 1, 2, 0},{3, 4, 5, 2},{1, 3, 1, 5} };
	Solution_73_Const().setZeroes(matrix);
	for (auto &v : matrix) {
		for (int i : v) cout << i << " ";
		cout << endl;
	}
}