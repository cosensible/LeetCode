#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_340 {
public:
	// 滑动窗口，哈希表统计窗口中的字符种类及其数量
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int ans = 0;
		unordered_map<char, int> cnt;
		for (int l = 0, r = 0; r < s.size(); ++r) {
			cnt[s[r]]++;
			// 字符种类超出限制，移动左边界直至字符种类符合要求
			// 也可用哈希表记录窗口中每个字符最后出现的位置，然后将左边界直接移到位置最小的字符后面
			// 需要按值取哈希表最小元素，同样需要遍历哈希表
			while (cnt.size() > k) {
				if (--cnt[s[l]] == 0) cnt.erase(s[l]);
				++l;
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};


void test_340() {
	string s = "eceba";
	cout << (Solution_340().lengthOfLongestSubstringKDistinct(s, 3) == 4) << endl;
}