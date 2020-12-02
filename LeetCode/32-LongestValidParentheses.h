#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_32 {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		if (n < 2) return 0;
		int res = 0;
		//��ֹ�ϲ�ͷ��֮ǰ����Ч���Ŵ�ʱԽ��, 0 Ϊ�Ʊ� .(())
		vector<int> dp(n + 1, 0); //dp[i] ��ʾ�� i ��β�����Ч���Ŵ��ĳ���
		for (int i = 1; i < n; ++i) {
			int j = i + 1; //dp �±���Ʊ��ʼ
			if (s[i] == ')') { //ֻ�����������Ųſ���������Ч���Ŵ�
				if (s[i - 1] == '(') dp[j] = dp[j - 2] + 2;
				//ǰһ�������Ų�������󳤶�Ϊdp[j-1]
				else if (i - dp[j - 1] >= 1 && s[i - dp[j - 1] - 1] == '(')
					dp[j] = dp[j - 1] + 2 + dp[j - dp[j - 1] - 2];
			}
			res = dp[j] > res ? dp[j] : res;
		}
		return res;
	}

	int longestValidParentheses1(string s)
	{
		int length = s.size();
		if (length < 2) return 0;
		vector<int> dp(length);

		int res = 0;
		for (int i = 1; i < length; ++i)
		{
			if (s[i] == ')' && s[i - 1] == '(')
			{
				dp[i] = i < 2 ? 2 : dp[i - 2] + 2;
			}
			else if (s[i] == ')' && s[i - 1] == ')' && s[i - dp[i - 1] - 1] == '(')
			{
				int flag = i - dp[i - 1] - 2;
				dp[i] = flag < 0 ? dp[i - 1] + 2 : dp[i - 1] + dp[flag] + 2;
			}
			if (res < dp[i])
			{
				res = dp[i];
			}
		}
		return res;
	}

	int longestValidParentheses2(string s)
	{
		int length = s.size();
		if (length < 2) return 0;

		stack<int> is;
		is.push(-1);
		int res = 0;
		for (int i = 0; i < length; ++i)
		{
			if (s[i] == '(')
				is.push(i);
			else
			{
				is.pop();
				if (is.empty())
					is.push(i);
				else if (res < i - is.top())
					res = i - is.top();
			}
		}
		return res;
	}
};

void test_32() {
	string s = ")()())";
	cout << (Solution_32().longestValidParentheses2(s) == 4) << endl;
}