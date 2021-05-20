#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_139 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool> dp(n + 1, false); // dp[i]��s ��ǰ i ���ַ��Ƿ����ɵ��ʹ���
		dp[0] = true;
		for (int i = 0; i < n; ++i) { // s ��ǰ i ���ַ�����һ������
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