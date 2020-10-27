#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_10_1 {
public:
	bool isMatch(string s, string p) {
		return help(s, p, 0, 0);
	}

	bool help(const string &s, const string &p, int i, int j) {
		int m = s.size(), n = p.size();
		if (j == n) return i == m;
		bool first_match = i < m && (s[i] == p[j] || p[j] == '.');
		if (j + 1 < n && p[j + 1] == '*')
			return first_match && help(s, p, i + 1, j) || help(s, p, i, j + 2);
		else return first_match && help(s, p, i + 1, j + 1);
	}
};



class Solution_10 {
	int m, n;
	vector<vector<int>> memo;
public:
	bool isMatch(string s, string p) {
		m = s.size(), n = p.size();
		//需要记录到达s末尾时, 是否和p匹配的情况
		memo = vector<vector<int>>(m + 1, vector<int>(n, -1));
		return help(s, p, 0, 0);
	}

	bool help(const string &s, const string &p, int i, int j) {
		if (j == n) return i == m;
		//结果已经被保存
		if (memo[i][j] != -1) return memo[i][j];
		bool ans = false;
		bool first_match = i < m && (s[i] == p[j] || p[j] == '.');
		if (j + 1 < n && p[j + 1] == '*')
			ans = first_match && help(s, p, i + 1, j) || help(s, p, i, j + 2);
		else ans = first_match && help(s, p, i + 1, j + 1);
		memo[i][j] = ans ? 1 : 0;
		return ans;
	}
};

void test_10() {
	string s = "", p = ".*";
	string s1 = "aa", p1 = "a";
	cout << (Solution_10().isMatch(s1, p1) == false) << endl;
}