#include <string>
#include <iostream>
using namespace std;

class Solution_161_Substr {
public:
	// ���� s.size()<=t.size()��������֮����� 1���༭���벻����Ϊ 1
	// ��ǰ s.size() ���ַ���ͬ�����������༭����Ϊ 0�����Ȳ�����༭����Ϊ 1
	// ��λ�� i �ַ���ͬ����������� s[i+1:]==t[i+1:]�����Ȳ�����ɾȥ t ���ַ������� t[i+1:]==s[i:]
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

		bool edited = false; // �Ƿ񱻱༭��һ��
		int i = 0, j = 0;
		while (i < m) {
			if (s[i] != t[j]) {
				if (edited) return false; // ���ܱ༭�ڶ���
				edited = true;
				if (m != n) ++j; // t[j+1:]==s[i:]
				else ++i, ++j; // t[j+1:]==s[i+1:]
			}
			else ++i, ++j;
		}
		return edited || !edited&&m != n; // ֻ���༭һ�λ���û���༭�����Ȳ���
	}
};

void test_161() {
	string s = "ab", t = "acb";
	cout << (Solution_161().isOneEditDistance(s, t) == true) << endl;
}