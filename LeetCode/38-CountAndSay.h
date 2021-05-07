#include <string>
#include <iostream>
using namespace std;

class Solution_38 {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; ++i) {
			string news;
			for (int j = 0; j < s.size();) {
				char c = s[j];
				int cnt = 1;
				// 计算数字连续出现的次数
				int k = j + 1;
				for (; k < s.size() && s[k] == c; ++k) { ++cnt; }
				cnt = cnt * 10 + c - '0'; // 次数 + 数字
				news += to_string(cnt);
				j = k; // 右移至下一个数字的起始位置
			}
			swap(s, news);
		}
		return s;
	}
};

void test_38() {
	cout << (Solution_38().countAndSay(4)) << endl;
}