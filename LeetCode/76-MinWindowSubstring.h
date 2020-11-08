#include "common.h"

using namespace std;

class Solution_76 {
public:
	string minWindow(string s, string t) {
		int n = s.size(), count = t.size();
		int l = 0, r = 0, minStart = 0, minLen = n + 1;
		unordered_map<char, int> mp;
		for (char c : t) { ++mp[c]; }

		while (r < n) {
			if (mp[s[r]]-- > 0) { --count; }
			++r;
			while (count == 0) {
				if (r - l < minLen) {
					minLen = r - l;
					minStart = l;
				}
				if (++mp[s[l]] > 0) { ++count; }
				++l;
			}
		}
		return minLen <= n ? s.substr(minStart, minLen) : "";
	}
};

void test_76() {
	string s = "ADOBECODEBANC", t = "ABC";
	string res = "BANC";
	cout << (Solution_76().minWindow(s, t) == res) << endl;
}