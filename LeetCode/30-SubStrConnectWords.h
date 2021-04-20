#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_30 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty()) return ans;
		int wnum = words.size(), wlen = words[0].size();
		int window = wnum * wlen; // 子串长度为窗口大小

		unordered_map<string, int> mp; // 记录每个单词的数量
		for (string &w : words) { mp[w]++; }

		for (int i = 0; i + window <= s.size(); ++i) {
			unordered_map<string, int> cmp; // 记录当前窗口中每个单词的数量
			int j = i;
			for (; j - i < window; j += wlen) {
				string stmp = s.substr(j, wlen);
				if (mp.count(stmp) == 0) break; // 单词不存在，一定不匹配
				cmp[stmp]++; // 增加单词数量
				if (cmp[stmp] > mp[stmp]) break; // 单词数量超过结果，一定不匹配
			}
			if (j - i == window) ans.push_back(i); // j 到达窗口末尾，说明窗口子串满足条件
		}
		return ans;
	}

	vector<int> findSubstringFast(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty()) return ans;
		int wnum = words.size(), wlen = words[0].size();
		int window = wnum * wlen;

		unordered_map<string, int> mp;
		for (string &w : words) { mp[w]++; }
		// 因为窗口每次移动一个单词的长度，所以分为 wlen 种情况，每种情况的起点分别是 [0, wlen-1]
		for (int k = 0; k < wlen; ++k) {
			unordered_map<string, int> cmp; // 当前窗口包含的各种单词的数量
			int i = k, j = k; // 对于每种情况，先将左右边界 i 和 j 放在起点，然后执行窗口的滑动，每次滑动一个单词的长度
			// 左边界到字符串末尾应该至少为窗口大小，右边界到末尾应该至少有一个单词的长度
			while (i + window <= s.size() && j + wlen <= s.size()) {
				string stmp = s.substr(j, wlen); // 得到当前单词
				if (mp.count(stmp) == 0) { // 单词不在单词表中，无法形成合法串，将左边界移动到 j+wlen
					j += wlen;
					i = j;
					cmp.clear();
				}
				else { // 单词在单词表中，扩展右边界，单词数量加一
					cmp[stmp]++;
					j += wlen;
					// 如果单词数量非法，缩小左边界直至合法，更新单词数量
					while (cmp[stmp] > mp[stmp]) {
						cmp[s.substr(i, wlen)]--;
						i += wlen;
					}
					// 如果窗口大小达到 window，表明找到合法串，记录索引并缩小左边界，继续查找
					if (j - i == window) {
						ans.push_back(i);
						cmp[s.substr(i, wlen)]--;
						i += wlen;
					}
				}
			}
		}
		return ans;
	}
};


void test_30() {
	string s = "barfoothefoobarman";
	vector<string> words = { "foo","bar" };
	//auto ans = Solution_30().findSubstring(s, words);
	auto ans = Solution_30().findSubstringFast(s, words);
	for (int i : ans) cout << i << " ";
	cout << endl;
}