#include <string>
#include <iostream>
using namespace std;

class Solution_65 {
public:
	bool isNumber(string s) {
		int i = 0, n = s.size();
		// 开头没有形成合法的数，不是有效数字
		if (!crossNum(s, i)) return false;
		if (i < n && (s[i] == 'e' || s[i] == 'E')) {
			++i;
			// 'e','E' 后面没出现整数，不是有效数字
			if (i < n && (s[i] == '+' || s[i] == '-')) ++i;
			if (!crossDigit(s, i)) return false;
		}
		return i == n;
	}

private:
	// 是否经过一串数字
	bool crossDigit(string &s, int &i) {
		int j = i;
		while (i < s.size() && s[i] >= '0'&&s[i] <= '9') ++i;
		return i > j;
	}
	// 是否形成一个数（整数部分和小数部分至少有一个存在）
	bool crossNum(string &s, int &i) {
		bool ans = false;
		// 符号位
		if (i < s.size() && (s[i] == '+' || s[i] == '-')) ++i;
		ans = crossDigit(s, i) || ans; // 整数部分
		if (i < s.size() && s[i] == '.') {
			++i;
			ans = crossDigit(s, i) || ans; // 小数部分
		}
		return ans;
	}
};


void test_65() {
	cout << (Solution_65().isNumber("53.5e-93")) << endl;
}