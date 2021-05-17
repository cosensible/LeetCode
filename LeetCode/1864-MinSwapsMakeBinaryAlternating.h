#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1864 {
public:
	int minSwaps(string s) {
		int cnt0 = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') ++cnt0;
		}
		int cnt1 = s.size() - cnt0;
		if (abs(cnt0 - cnt1) > 1) return -1;

		// �ַ�����ʽΪ 10101010... �� 01010101...
		// ���е� 1 Ҫôȫ����������λ��Ҫôȫ������ż��λ���� cnt1>cnt0����ֻ�ܳ���������λ
		// ���Ӧ�ó��� 1 ��λ���ϳ����� 0��˵����Ҫ����һ��
		int ans = 0;
		if (cnt0 == cnt1) { // ������ 1 ��ͷ��Ҳ������ 0 ��ͷ
			int ans1 = 0, ans2 = 0;
			for (int i = 0; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans1;
			}
			for (int i = 1; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans2;
			}
			ans = min(ans1, ans2);
		}
		else if (cnt0 < cnt1) { // ������ 1 ��ͷ
			for (int i = 0; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans;
			}
		}
		else { // ������ 0 ��ͷ
			for (int i = 1; i < s.size(); i += 2) {
				if (s[i] != '1') ++ans;
			}
		}
		return ans;
	}
};

void test_1864() {
	string s = "111000";
	cout << (Solution_1864().minSwaps(s) == 1) << endl;
}