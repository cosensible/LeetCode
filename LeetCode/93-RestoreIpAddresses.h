#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_93 {
	int part = 4; // ipv4 ��ַ�����ĸ����֣�ÿ���ֵ���ֵ��Χ�� [0,255]
	string ipstr; // ���浱ǰ�� ipv4 ��ַ
	vector<string> ans;
public:
	vector<string> restoreIpAddresses(string s) {
		backtrack(s, 0, 0);
		return ans;
	}

private:
	// idx ���������ֵ�λ�ã�cpart ��ǰ����õ� part ����
	void backtrack(string &s, int idx, int cpart) {
		int n = s.size();
		if (cpart == part) { // ����ĸ����ֵĹ��죬��ǡ��������������
			ipstr.pop_back();
			ans.push_back(ipstr);
			ipstr.push_back('.');
			return;
		}
		// �ӵ�ǰλ�ÿ�ʼ�����ֻ��ѡ 3 ������
		for (int k = idx; k <= idx + 2 && k < n; ++k) {
			if (cpart + 1 == part && k != n - 1) continue; // ������ɻ��ж������֣�����ʹ�ø�������
			if (cpart + 1 < part&&k == n - 1) return; // ���ֲ������Ƿ�
			if (!check(s, idx, k)) return; // ���ɵ������ڷ�Χ�ڣ��Ƿ�

			ipstr += s.substr(idx, k - idx + 1);
			ipstr.push_back('.');
			backtrack(s, k + 1, cpart + 1);
			ipstr.resize(ipstr.size() - k + idx - 2);
		}
	}
	// �жϵ�ǰ���ִ��Ƿ��� [0,255] ��Χ��
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
		// �ҵ� 4 �� part�������ж������֣��Ƿ�������ʣ�����֣�����Ϸ�
		if (cpart == part) {
			if (idx != n) return;
			ipstr.pop_back();
			ans.push_back(ipstr);
			ipstr.push_back('.');
			return;
		}
		// δ�ҵ� 4 �� part�����ַ��������Ƿ�
		if (idx == n) { return; }
		// �ӵ�ǰλ�ÿ�ʼ�����ֻ��ѡ 3 ������
		for (int k = idx; k <= idx + 2 && k < n; ++k) {
			if (!check(s, idx, k)) return; // ���ɵ������ڷ�Χ�ڣ��Ƿ�
			ipstr += s.substr(idx, k - idx + 1);
			ipstr.push_back('.');
			backtrack(s, k + 1, cpart + 1);
			ipstr.resize(ipstr.size() - k + idx - 2);
		}
	}
	// �жϵ�ǰ���ִ��Ƿ��� [0,255] ��Χ��
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