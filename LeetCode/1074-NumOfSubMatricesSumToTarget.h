#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_1074 {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int ans = 0;
		// ö�پ�������±߽磬����߽���ÿһ��Ԫ��֮�ͣ��������к�Ϊ target �����������
		for (int t = 0; t < m; ++t) {
			vector<int> psum(n, 0); // ��߽���ÿһ��Ԫ��֮��
			for (int b = t; b < m; ++b) {
				for (int j = 0; j < n; ++j) {
					psum[j] += matrix[b][j];
				}
				ans += getSubArrCnt(psum, target); // �������к�Ϊ target �����������
			}
		}
		return ans;
	}

private:
	int getSubArrCnt(vector<int> &nums, int target) {
		int sum = 0, ans = 0;
		unordered_map<int, int> cnt; // ����ǰ׺���ֵĴ���
		cnt[0] = 1;
		for (int x : nums) {
			sum += x; // �ۼ��γ�ǰ׺��
			if (cnt.count(sum - target) != 0)
				ans += cnt[sum - target];
			++cnt[sum];
		}
		return ans;
	}
};

void test_1074() {
	vector<vector<int>> matrix = { {1,-1},{-1,1} };
	int target = 0;
	cout << (Solution_1074().numSubmatrixSumTarget(matrix, target) == 5) << endl;
}