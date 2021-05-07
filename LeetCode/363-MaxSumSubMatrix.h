#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_363 {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int ans = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		// ��������Ͻǵ�ÿ��λ�� (i,j) ���ɵľ�������ĺ�
		vector<vector<int>> nsum(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				nsum[i][j] = nsum[i - 1][j] + nsum[i][j - 1] - nsum[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
		// �о�ÿ�����½� (i,j)�����о�ÿ�����Ͻ� (ii,jj)��������Ӧ��������ĺ�
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int ii = 0; ii < i; ++ii) {
					for (int jj = 0; jj < j; ++jj) {
						int num = nsum[i][j] - nsum[ii][j] - nsum[i][jj] + nsum[ii][jj];
						if (num <= k) ans = max(ans, num);
					}
				}
			}
		}
		return ans;
	}
};

class Solution_FixLeftRight {
public:
	// �̶����ұ߽磬����߽���ÿ�еĺ͹������飬������������� sum������ sum<=k
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		int ans = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < n; ++i) { // �̶���߽�
			vector<int> nsum(m, 0);   // ����߽緶Χ��ÿһ�еĺ�
			for (int j = i; j < n; ++j) { // �ƶ��ұ߽�
				for (int k = 0; k < m; ++k) {
					nsum[k] += matrix[k][j];
				}
				set<int> presum = { 0 };
				int cursum = 0;
				for (int num : nsum) {
					cursum += num;
					auto pos = lower_bound(presum.begin(), presum.end(), cursum - k);
					if (pos != presum.end()) ans = max(ans, cursum - *pos);
					presum.insert(cursum);
				}
			}
		}
		return ans;
	}
};

class Solution_FixUpDown {
public:
	// �̶����±߽磬����߽���ÿ�еĺ͹������飬������������� sum������ sum<=k
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		int ans = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; ++i) { // �̶��ϱ߽�
			vector<int> nsum(n, 0);   // ����߽緶Χ��ÿһ�еĺ�
			for (int j = i; j < m; ++j) { // �ƶ��±߽�
				for (int k = 0; k < n; ++k) {
					nsum[k] += matrix[j][k];
				}
				set<int> presum = { 0 }; // ���򱣴������ǰ׺�ͣ���ʼǰ׺Ϊ 0
				int cursum = 0;
				for (int num : nsum) {
					cursum += num; // �õ���ͷ����ǰλ�õĺ�
					// �ҵ�һ������������ǰ׺�ͣ�����С��ǰ׺��
					auto pos = lower_bound(presum.begin(), presum.end(), cursum - k);
					if (pos != presum.end()) ans = max(ans, cursum - *pos);
					presum.insert(cursum);
				}
			}
		}
		return ans;
	}
};

void test_363() {
	vector<vector<int>> matrix = {
		{1,0,1},
		{0,-2,3}
	};
	cout << (Solution_FixUpDown().maxSumSubmatrix(matrix, 2) == 2) << endl;
}