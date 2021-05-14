#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_93 {
	int part = 4; // ipv4 地址包含四个部分，每部分的数值范围是 [0,255]
	string ipstr; // 保存当前的 ipv4 地址
	vector<string> ans;
public:
	vector<string> restoreIpAddresses(string s) {
		backtrack(s, 0, 0);
		return ans;
	}

private:
	// idx 待处理数字的位置，cpart 当前构造好的 part 数量
	void backtrack(string &s, int idx, int cpart) {
		int n = s.size();
		if (cpart == part) { // 完成四个部分的构造，且恰好用完所有数字
			ipstr.pop_back();
			ans.push_back(ipstr);
			ipstr.push_back('.');
			return;
		}
		// 从当前位置开始，最多只能选 3 个数字
		for (int k = idx; k <= idx + 2 && k < n; ++k) {
			if (cpart + 1 == part && k != n - 1) continue; // 构造完成还有多余数字，考虑使用更多数字
			if (cpart + 1 < part&&k == n - 1) return; // 数字不够，非法
			if (!check(s, idx, k)) return; // 构成的数不在范围内，非法

			ipstr += s.substr(idx, k - idx + 1);
			ipstr.push_back('.');
			backtrack(s, k + 1, cpart + 1);
			ipstr.resize(ipstr.size() - k + idx - 2);
		}
	}
	// 判断当前数字串是否在 [0,255] 范围内
	bool check(string &s, int l, int r) {
		if (r - l + 1 > 3) return false;
		if (s[l] == '0' && r - l + 1 > 1) return false;
		int num = 0;
		for (int k = l; k <= r; ++k) {
			num = num * 10 + s[k] - '0';
			if (num > 255) return false;
		}
		return true;
	}
};


class Solution_93_Another {
	int part = 4;
	string ipstr;
	vector<string> ans;
public:
	vector<string> restoreIpAddresses(string s) {
		backtrack(s, 0, 0);
		return ans;
	}

private:
	void backtrack(string &s, int idx, int cpart) {
		int n = s.size();
		// 找到 4 个 part：若还有多余数字，非法；若无剩余数字，结果合法
		if (cpart == part) {
			if (idx != n) return;
			ipstr.pop_back();
			ans.push_back(ipstr);
			ipstr.push_back('.');
			return;
		}
		// 未找到 4 个 part，且字符不够，非法
		if (idx == n) { return; }
		// 从当前位置开始，最多只能选 3 个数字
		for (int k = idx; k <= idx + 2 && k < n; ++k) {
			if (!check(s, idx, k)) return; // 构成的数不在范围内，非法
			ipstr += s.substr(idx, k - idx + 1);
			ipstr.push_back('.');
			backtrack(s, k + 1, cpart + 1);
			ipstr.resize(ipstr.size() - k + idx - 2);
		}
	}
	// 判断当前数字串是否在 [0,255] 范围内
	bool check(string &s, int l, int r) {
		if (r - l + 1 > 3) return false;
		if (s[l] == '0' && r - l + 1 > 1) return false;
		int num = 0;
		for (int k = l; k <= r; ++k) {
			num = num * 10 + s[k] - '0';
			if (num > 255) return false;
		}
		return true;
	}
};


void test_93() {
	auto ans1 = Solution_93().restoreIpAddresses("25525511135");
	auto ans2 = Solution_93_Another().restoreIpAddresses("0000");
	for (auto &s : ans1) { cout << s << endl; }
	cout << endl;
	for (auto &s : ans2) { cout << s << endl; }
}