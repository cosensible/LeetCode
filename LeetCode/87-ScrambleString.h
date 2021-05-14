#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_87 {
	vector<vector<vector<int>>> memo;
public:
	// �����ַ�����Ҫ���������������ÿ���ַ����ֵĴ������
	bool isScramble(string s1, string s2) {
		if (s1 == s2) return true;
		if (s1.size() != s2.size()) return false;
		int n = s1.size();
		if (!check(s1, s2, 0, 0, n)) return false; // �ַ���������
		// memo[i][j][k]: s1 �� i ��ʼ��s2 �� j ��ʼ������Ϊ k �������Ӵ��Ƿ�Ϊ�����ַ���
		memo.resize(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
		return dfs(s1, s2, 0, 0, s1.size());
	}

private:
	bool dfs(string &s1, string &s2, int i, int j, int len) {
		// memo[i][j][k]==0 ��ʾδ��¼���
		if (memo[i][j][len] != 0) return memo[i][j][len] == 1;
		if (len == 1) { // ����Ϊ 1���ַ������Ϊ�����ַ���
			if (s1[i] == s2[j]) return true;
			return false;
		}
		// �������Ҫ��������֦����¼���
		if (!check(s1, s2, i, j, len)) {
			memo[i][j][len] = -1;
			return false;
		}
		// ���Դ��м�����λ�öϿ��������Ƿ񽻻�
		for (int k = 1; k < len; ++k) {
			// ������ǰ���Ӵ�
			bool b1 = dfs(s1, s2, i, j, k);
			bool b2 = dfs(s1, s2, i + k, j + k, len - k);
			memo[i][j][k] = b1 ? 1 : -1;
			memo[i + k][j + k][len - k] = b2 ? 1 : -1;
			if (b1&&b2) { return true; }
			// ����ǰ���Ӵ�
			b1 = dfs(s1, s2, i, j + len - k, k);
			b2 = dfs(s1, s2, i + k, j, len - k);
			memo[i][j + len - k][k] = b1 ? 1 : -1;
			memo[i + k][j][len - k] = b2 ? 1 : -1;
			if (b1&&b2) { return true; }
		}
		return false;
	}

	// s1.substr(i,len) �� s2.substr(j,len) �Ƿ����������ַ����ı�Ҫ����
	bool check(string &s1, string &s2, int i, int j, int len) {
		vector<int> a(26), b(26);
		for (int k = i; k < i + len; ++k) {
			a[s1[k] - 'a']++;
		}
		for (int k = j; k < j + len; ++k) {
			b[s2[k] - 'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
};


void test_87() {
	string s1 = "abcde", s2 = "caebd";
	cout << (Solution_87().isScramble(s1, s2) == false) << endl;
}