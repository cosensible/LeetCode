#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_132 {
public:
	int minCut(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, true));
		for (int i = n - 2; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
			}
		}
		// dp[i] ��ʾ s[0..i] ����С�и�������� s[0..i] �ǻ��ģ����и����Ϊ��
		// ����dp[i]=min{ dp[j] } ���� s[j+1..i] �ǻ��Ĵ�
		vector<int> minc(n, n);
		for (int i = 0; i < n; ++i) {
			if (dp[0][i]) minc[i] = 0;
			else {
				for (int j = i; j > 0; --j) {
					if (dp[j][i])
						minc[i] = min(minc[i], minc[j - 1] + 1);
				}
			}
		}
		return minc[n - 1];
	}
};


void test_132() {
	cout << (Solution_132().minCut("coder") == 4) << endl;
}