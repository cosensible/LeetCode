#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_474 {
public:
	// f[i][j][k]��ǰ i ��Ԫ�أ�0 �� 1 �����޷ֱ�Ϊ j �� k ʱ������Ӽ��Ĵ�С
	// ѡ�� i ��Ԫ�أ�0 �� 1 �����޼��٣��Ӽ���С��һ
	// ��ѡ�� i ��Ԫ�أ�0 �� 1 ���޲��䣬�Ӽ���С����
	// ״̬ѹ�������Լ���һ��ά��
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (string &s : strs) {
			int cnt0 = 0, cnt1 = 0;
			for (char c : s) {
				if (c == '0') ++cnt0;
			}
			cnt1 = s.size() - cnt0;

			for (int i = m; i >= cnt0; --i) {
				for (int j = n; j >= cnt1; --j) {
					dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
				}
			}
		}
		return dp[m][n];
	}
};

void test_474() {
	vector<string> strs = { "10", "0001", "111001", "1", "0" };
	int m = 5, n = 3;
	cout << (Solution_474().findMaxForm(strs, m, n) == 4) << endl;
}