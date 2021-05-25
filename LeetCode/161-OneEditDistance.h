#include <string>
#include <iostream>
using namespace std;

class Solution_161_Substr {
public:
	// 假设 s.size()<=t.size()，若长度之差大于 1，编辑距离不可能为 1
	// 若前 s.size() 个字符相同，长度相等则编辑距离为 0，长度不等则编辑距离为 1
	// 若位置 i 字符不同，长度相等则 s[i+1:]==t[i+1:]，长度不等则删去 t 中字符，满足 t[i+1:]==s[i:]
	bool isOneEditDistance(string s, string t) {
		int m = s.size(), n = t.size();
		if (m > n) return isOneEditDistance(t, s);
		if (n - m > 1) return false;

		for (int i = 0; i < m; ++i) {
			if (s[i] != t[i]) {
				if (m == n) return s.substr(i + 1) == t.substr(i + 1);
				return s.substr(i) == t.substr(i + 1);
			}
		}
		return m != n;
	}
};

class Solution_161 {
public:
	bool isOneEditDistance(string s, string t) {
		int m = s.size(), n = t.size();
		if (m > n) return isOneEditDistance(t, s);
		if (n - m > 1) return false;

		bool edited = false; // 是否被编辑过一次
		int i = 0, j = 0;
		while (i < m) {
			if (s[i] != t[j]) {
				if (edited) return false; // 不能编辑第二次
				edited = true;
				if (m != n) ++j; // t[j+1:]==s[i:]
				else ++i, ++j; // t[j+1:]==s[i+1:]
			}
			else ++i, ++j;
		}
		return edited || !edited&&m != n; // 只被编辑一次或者没被编辑但长度不等
	}
};

void test_161() {
	string s = "ab", t = "acb";
	cout << (Solution_161().isOneEditDistance(s, t) == true) << endl;
}