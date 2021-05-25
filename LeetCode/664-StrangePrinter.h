#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_664 {
public:
	int strangePrinter(string s) {
		int n = s.size();
		// dp[i][j] Ϊ��ӡ s[i,j] �����ٴ���
		// �� s[i]==s[j]����ӡ s[i] ��ʱ����ܴ�ӡ s[j]��dp[i][j]=dp[i][j-1]
		// �� s[i]!=s[j]���������ַ�������ͬһ�δ�ӡ���轫�ַ�����Ϊ���룬�ֱ��ӡ
		// ����ÿ���ָ�� k��ȡ�ܺ���С�Ĵ���
		vector<vector<int>> dp(n, vector<int>(n, n));
		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; ++j) {
				if (s[i] == s[j]) dp[i][j] = dp[i][j - 1];
				else {
					for (int k = i; k < j; ++k) {
						int cnt = dp[i][k] + dp[k + 1][j];
						dp[i][j] = min(dp[i][j], cnt);
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};


void test_664() {
	string s = "abab";
	cout << (Solution_664().strangePrinter(s) == 3) << endl;
}