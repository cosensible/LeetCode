#include "common.h"
using namespace std;

class Solution_6 {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string ret; // 保存结果
		int n = s.size();
		int cycleLen = 2 * numRows - 2; // 每个周期包含字母的数量 (|/)

		for (int i = 0; i < numRows; i++) { // 按行构造新字符串
			for (int j = 0; j + i < n; j += cycleLen) { // j 为每个周期的起点
				ret += s[j + i]; // 加上每个周期的第i个字母
				// 如果不为首尾行, 还要加上第二部分 (/) 的字母, 其索引为 j+cycLen-i
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
					ret += s[j + cycleLen - i];
			}
		}
		return ret;
	}
};


class Solution_6_Arr {
public:
	string convert(string s, int numRows) {
		if (numRows < 2) return s;
		vector<string> rows(min(numRows, (int)s.size()));

		int idx = 0, d = 1; // idx表示当前字符属于第几行, d为idx的前进方向
		for (char c : s) {
			rows[idx] += c;
			idx += d;
			if (idx == numRows - 1 || idx == 0) d = -d; // 碰到首尾行, 反向
		}
		for (int i = 1; i < rows.size(); ++i) {
			rows[0] += rows[i];
		}
		return rows[0];
	}
};

void test_6() {
	cout << (Solution_6_Arr().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI") << endl;
}