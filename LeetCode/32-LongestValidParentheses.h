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
		//防止合并头部之前的有效括号串时越界, 0 为哑标 .(())
		vector<int> dp(n + 1, 0); //dp[i] 表示以 i 结尾的最长有效括号串的长度
		for (int i = 1; i < n; ++i) {
			int j = i + 1; //dp 下标从哑标后开始
			if (s[i] == ')') { //只有遇到闭括号才可能生成有效括号串
				if (s[i - 1] == '(') dp[j] = dp[j - 2] + 2;
				//前一个闭括号产生的最大长度为dp[j-1]
				else if (i - dp[j - 1] >= 1 && s[i - dp[j - 1] - 1] == '(')
					dp[j] = dp[j - 1] + 2 + dp[j - dp[j - 1] - 2];
			}
			res = dp[j] > res ? dp[j] : res;
		}
		return res;
	}
};

void test_32() {
	string s = ")()())";
	cout << (Solution_32().longestValidParentheses(s) == 4) << endl;
}