#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution_438 {
public:
	vector<int> findAnagrams(string s, string p) {
		int slen = s.size(), plen = p.size();
		vector<int> res;
		if (slen < plen) return res;
		unordered_map<char, int> smp, pmp;
		for (int i = 0; i < plen; ++i) {
			pmp[p[i]]++;
			smp[s[i]]++;
		}
		if (smp == pmp) res.push_back(0);
		for (int i = 1, j = plen; j < slen; ++i, ++j) {
			if (--smp[s[i - 1]] <= 0) smp.erase(s[i - 1]);
			smp[s[j]]++;
			if (smp == pmp) res.push_back(i);
		}
		return res;
	}
};

class Solution_438_1 {
public:
	vector<int> findAnagrams(string s, string p) {
		int slen = s.size(), plen = p.size();
		vector<int> res;
		if (slen < plen) return res;
		vector<int> smp(26), pmp(26);
		for (int i = 0; i < plen; ++i) {
			pmp[p[i] - 'a']++;
			smp[s[i] - 'a']++;
		}
		if (smp == pmp) res.push_back(0);
		for (int i = 1, j = plen; j < slen; ++i, ++j) {
			smp[s[i - 1] - 'a']--;
			smp[s[j] - 'a']++;
			if (pmp[s[j] - 'a'] == 0) { // 碰到 p 中不存在的元素
				// 直接跳到非法元素之后, 避免 vector 的比较
				for (int k = 1; k <= plen && j + k < slen; ++k) {
					smp[s[i - 1 + k] - 'a']--;
					smp[s[j + k] - 'a']++;
					// 在此过程中, 再次碰到非法元素
					if (pmp[s[j + k] - 'a'] == 0) {
						// 更新窗口位置, 重新执行跳过非法元素的过程
						i += k; j += k; k = 0;
					}
				}
				// 跳过非法元素后, 更新窗口位置
				i += plen;
				j += plen;
			}
			if (smp == pmp) res.push_back(i);
		}
		return res;
	}
};

void test_438() {
	string s = "cbaebabacd", p = "abc";
	vector<int> res = Solution_438_1().findAnagrams(s, p);
	for (int i : res) {
		cout << i << ",";
	}
	cout << endl;
}