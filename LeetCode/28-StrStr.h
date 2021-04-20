#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution_28 {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		if (n == 0) return 0; // needle为空, 返回零
		// 构造 next 数组
		// next 数组中存的是，当 p[j]!=s[i] 时，j 应该等于多少，即 p 串要向右移动多少位，此时 i 不变
		// next[j] 代表以第 j-1 个字符结尾的串中，相同前缀后缀的最大长度
		// 当 p[j]!=s[i] 时，令 j=next[j]，由于前缀与后缀相同，故此时前 j 个字符仍是匹配的
		vector<int> next(n);
		buildNext(needle, next);

		int i = 0, j = 0;
		while (i < m&&j < n) {
			// 从头开始匹配或当前字符匹配
			if (j == -1 || haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else {
				j = next[j];
			}
		}
		if (j == n) return i - j; // p 被匹配到末尾，代表匹配成功，在 s 串中的索引为 i-j
		return -1;
	}

private:
	void buildNext(const string &p, vector<int> &next) {
		int n = p.size();
		next.resize(n);
		if (n == 0) return;

		next[0] = -1; // 令 next[0]=-1，类似字符通配符，这样能在 p 没有前缀同 s[i] 匹配时，从p的头部开始匹配
		int t = -1, i = 0; // t 前缀字符串索引，j 后缀字符串索引
		while (i < n - 1) {
			if (t == -1 || p[t] == p[i]) {
				++t;
				++i;
				// 在求最长前缀后缀时，没有将 p[i] 考虑进去
				// 如果前缀字符串的后一个字符 p[t] 与 p[i] 相等，那么在 p[i] 失配时
				// 即使将索引移动到 next[i]=t，当前字符 p[t] 依然是失配的，所以需要递归移动
				if (p[t] == p[i]) {
					next[i] = next[t];
				}
				else {
					next[i] = t;
				}
			}
			else {
				t = next[t];
			}
		}
	}
};

void test_28() {
	cout << (Solution_28().strStr("abcabce", "cbce") == -1) << endl;
}