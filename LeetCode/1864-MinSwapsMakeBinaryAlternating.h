#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1864 {
public:
	int minSwaps(string s) {
		int cnt0 = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') ++cnt0;
		}
		int cnt1 = s.size() - cnt0;
		if (abs(cnt0 - cnt1) > 1) return -1;

		// 字符串形式为 10101010... 或 01010101...
		// 所有的 1 要么全出现在奇数位，要么全出现在偶数位，若 cnt1>cnt0，则只能出现在奇数位
		// 如果应该出现 1 的位置上出现了 0，说明需要交换一次
		int ans = 0;
		if (cnt0 == cnt1) { // 可以以 1 开头，也可以以 0 开头
			int ans1 = 0, ans2 = 0;
			for (int i = 0; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans1;
			}
			for (int i = 1; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans2;
			}
			ans = min(ans1, ans2);
		}
		else if (cnt0 < cnt1) { // 必须以 1 开头
			for (int i = 0; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans;
			}
		}
		else { // 必须以 0 开头
			for (int i = 1; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans;
			}
		}
		return ans;
	}
};

void test_1864() {
	string s = "111000";
	cout << (Solution_1864().minSwaps(s) == 1) << endl;
}