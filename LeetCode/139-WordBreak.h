#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_139 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool> dp(n + 1, false); // dp[i]：s 的前 i 个字符是否能由单词构成
		dp[0] = true;
		for (int i = 0; i < n; ++i) { // s 的前 i 个字符加上一个单词
			if (!dp[i]) continue;
			for (string &word : wordDict) {
				int wlen = word.size();
				if (i + wlen > n) { continue; }
				if (word == s.substr(i, wlen)) {
					dp[i + wlen] = true;
				}
			}
		}
		return dp[n];
	}
};


void test_139() {
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	cout << (Solution_139().wordBreak(s, wordDict) == true) << endl;
}