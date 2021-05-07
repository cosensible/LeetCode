#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_44 {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
		dp[0][0] = true;
		for (int j = 1; j <= n && p[j - 1] == '*'; ++j) {
			dp[0][j] = true;
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				// �Ǻſ���ƥ����������Сд��ĸ��״̬ת�Ʒ����������������ʹ�û�ʹ���Ǻ�
				// ��ʹ���Ǻţ�dp[i][j]=dp[i][j-1]
				// ʹ���Ǻţ�����ȥ s �е�һ���ַ���dp[i][j]=dp[i-1][j]
				// �����Ǻű���������ѡ�������ȥ s �е��ַ������� dp[i][j]=dp[i-1][j] ����
				else if (p[j - 1] == '*') {
					//for (int k = i; k >= 0; --k) {
					//	if (dp[k][j - 1]) {
					//		dp[i][j] = true;
					//		break;
					//	}
					//}

					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
				}
			}
		}
		return dp[m][n];
	}
};


class Solution_44_ScrollArr {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<int> dp(n + 1, false);  // ��¼��һ��״̬
		vector<int> cdp(n + 1, false); // ��¼��һ��״̬
		dp[0] = true;
		for (int j = 1; j <= n && p[j - 1] == '*'; ++j) {
			dp[j] = true;
		}

		for (int i = 1; i <= m; ++i) {
			cdp.assign(n + 1, false); // ���� cdp �����״̬��������ʼ�� cdp[0]=false
			for (int j = 1; j <= n; ++j) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					cdp[j] = dp[j - 1];
				}
				// �Ǻſ���ƥ����������Сд��ĸ��״̬ת�Ʒ����������������ʹ�û�ʹ���Ǻ�
				// ��ʹ���Ǻţ�dp[i][j]=dp[i][j-1]
				// ʹ���Ǻţ�����ȥ s �е�һ���ַ���dp[i][j]=dp[i-1][j]
				// �����Ǻű���������ѡ�������ȥ s �е��ַ������� dp[i][j]=dp[i-1][j] ����
				else if (p[j - 1] == '*') {
					cdp[j] = cdp[j - 1] || dp[j];
				}
			}
			swap(dp, cdp);
		}
		return dp[n];
	}
};


void test_44() {
	string s = "abcdefde", p = "abc*def";
	cout << (Solution_44_ScrollArr().isMatch(s, p)) << endl;
}