#include <vector>

using namespace std;

class Solution_22 {
	vector<string> res;
public:
	vector<string> generateParenthesis(int n) {
		string s(2 * n, '.');
		backtrace(s, 0, 0);
		return res;
	}

	void backtrace(string &s, int l, int r) {
		if (r > l) return; //当前右括号比左括号多,会导致括号字符串非法
		int n = s.size() / 2;
		if (l + r == 2 * n) { //括号用完且得到合法括号字符串,加入结果集
			res.push_back(s);
			return;
		}
		//左括号没用完,可选择左括号
		if (l < n) {
			s[l + r] = '(';
			backtrace(s, l + 1, r);
		}
		//右括号没用完,可选择右括号
		if (r < n) {
			s[l + r] = ')';
			backtrace(s, l, r + 1);
		}
	}
};