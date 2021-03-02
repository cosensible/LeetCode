#include "common.h"
using namespace std;

// 前缀和
class Solution_1208 {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int m = s.size(), n = t.size();
		if (m != n || maxCost < 0 || m == 0) return 0;
		// 子串 (-1,i] 的开销和为 diff[i]. 每个子串 s(i,j] 的开销和为 diff[j]-diff[i]
		vector<int> diff(m + 1, 0);
		for (int i = 0; i < m; ++i) {
			diff[i + 1] = abs(s[i] - t[i]);
			diff[i + 1] += diff[i];
		}
		int maxLen = 0;
		for (int l = 0, r = 1; r <= m;) {
			if (diff[r] - diff[l] <= maxCost) {
				maxLen = max(maxLen, r - l);
				++r;
			}
			else {
				++l;
			}
		}
		return maxLen;
	}
};

// 双指针法
class Solution_1208_2P {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int maxLen = 0;
		for (int l = 0, r = 0; r < s.size();) {
			if (abs(s[r] - t[r]) <= maxCost) { // 合法，更新资源占用，扩展右边界
				maxCost -= abs(s[r] - t[r]);
				++r;
				maxLen = max(maxLen, r - l); // 求合法的最大长度
			}
			else { // 非法，释放资源占用，压缩左边界
				maxCost += abs(s[l] - t[l]);
				++l;
			}
		}
		return maxLen;
	}
};

void test_1208() {
	int ans = Solution_1208().equalSubstring("abcd", "acde", 0);
	cout << (ans == 1) << endl;
}