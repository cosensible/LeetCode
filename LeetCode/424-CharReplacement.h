#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_424 {
public:
	int characterReplacement(string s, int k) {
		int l = 0, r = 0;  // 滑动窗口左右边界
		int maxcnt = 0; // 历史窗口中出现过的最多字母的数量
		vector<int> cnt(26, 0); // 记录窗口中各个字母的数量
		while (r < s.size()) {
			++cnt[s[r] - 'A'];
			maxcnt = max(maxcnt, cnt[s[r] - 'A']);
			if (r - l + 1 > maxcnt + k) { // 加上k后无法填满窗口, 窗口整体右移
				--cnt[s[l] - 'A'];
				++l;
			}
			++r;
		}
		return r - l;
	}
};


void test_424() {
	cout << (Solution_424().characterReplacement("AABABBA", 1) == 4) << endl;
}