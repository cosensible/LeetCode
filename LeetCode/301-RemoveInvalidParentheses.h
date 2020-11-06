#include "common.h"

using namespace std;

class Solution_301_BFS {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		unordered_set<string> cur({ s }); // 去重
		while (!cur.empty()) {
			for (const string &cs : cur) {
				if (isValid(cs)) {
					res.push_back(std::move(cs));
				}
			}
			if (!res.empty()) { return res; }
			unordered_set<string> next; // 下一层扩展节点
			for (const string &cs : cur) {
				for (int i = 0; i < cs.size(); ++i) {
					if (cs[i] == '(' || cs[i] == ')') {
						if (i > 0 && s[i] == s[i - 1]) { continue; }
						string tmp = cs.substr(0, i) + cs.substr(i + 1);
						next.insert(std::move(tmp));
					}
				}
			}
			swap(cur, next);
		}
		return { "" };
	}

private:
	bool isValid(const string &s) {
		int count = 0;
		for (char c : s) {
			if (c == '(')++count;
			else if (c == ')')--count;
			if (count < 0) return false;
		}
		return count == 0;
	}
};

class Solution_301_DFS {
public:
	vector<string> removeInvalidParentheses(const string &s) {
		vector<string> res;
		// 计算无效的左右括号的数量
		int lnum = 0, rnum = 0;
		for (char ch : s) {
			if (ch == '(') { ++lnum; }
			else if (ch == ')') {
				if (lnum == 0) { ++rnum; }
				else { --lnum; }
			}
		}
		dfs(res, s, 0, lnum, rnum);
		return res;
	}

private:
	// s 为当前字符串, start 为之前未遍历过的最新位置
	void dfs(vector<string> &res, const string &s, int start, int lnum, int rnum) {
		if (lnum == 0 && rnum == 0) {
			if (isValid(s)) res.push_back(s);
			return;
		}
		for (int i = start; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == ')') {
				if (i > 0 && s[i] == s[i - 1]) { continue; } // 去重
				string tmp = s.substr(0, i) + s.substr(i + 1);
				if (s[i] == ')' && rnum > 0) dfs(res, tmp, i, lnum, rnum - 1);
				if (s[i] == '(' && lnum > 0) dfs(res, tmp, i, lnum - 1, rnum);
			}
		}
	}
	bool isValid(const string &s) {
		int count = 0;
		for (char c : s) {
			if (c == '(')++count;
			else if (c == ')')--count;
			if (count < 0) return false;
		}
		return count == 0;
	}
};

void test_301() {
	string s = "(a)())()";
	vector<string> res = Solution_301_DFS().removeInvalidParentheses(s);
	for (string s : res) {
		cout << s << ",";
	}
	cout << endl;
}