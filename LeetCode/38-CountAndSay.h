#include <string>
#include <iostream>
using namespace std;

class Solution_38 {
public:
	string countAndSay(int n) {
		string s = "1";
		for (int i = 1; i < n; ++i) {
			string news;
			for (int j = 0; j < s.size();) {
				char c = s[j];
				int cnt = 1;
				// ���������������ֵĴ���
				int k = j + 1;
				for (; k < s.size() && s[k] == c; ++k) { ++cnt; }
				cnt = cnt * 10 + c - '0'; // ���� + ����
				news += to_string(cnt);
				j = k; // ��������һ�����ֵ���ʼλ��
			}
			swap(s, news);
		}
		return s;
	}
};

void test_38() {
	cout << (Solution_38().countAndSay(4)) << endl;
}