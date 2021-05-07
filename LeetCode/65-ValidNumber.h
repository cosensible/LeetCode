#include <string>
#include <iostream>
using namespace std;

class Solution_65 {
public:
	bool isNumber(string s) {
		int i = 0, n = s.size();
		// ��ͷû���γɺϷ�������������Ч����
		if (!crossNum(s, i)) return false;
		if (i < n && (s[i] == 'e' || s[i] == 'E')) {
			++i;
			// 'e','E' ����û����������������Ч����
			if (i < n && (s[i] == '+' || s[i] == '-')) ++i;
			if (!crossDigit(s, i)) return false;
		}
		return i == n;
	}

private:
	// �Ƿ񾭹�һ������
	bool crossDigit(string &s, int &i) {
		int j = i;
		while (i < s.size() && s[i] >= '0'&&s[i] <= '9') ++i;
		return i > j;
	}
	// �Ƿ��γ�һ�������������ֺ�С������������һ�����ڣ�
	bool crossNum(string &s, int &i) {
		bool ans = false;
		// ����λ
		if (i < s.size() && (s[i] == '+' || s[i] == '-')) ++i;
		ans = crossDigit(s, i) || ans; // ��������
		if (i < s.size() && s[i] == '.') {
			++i;
			ans = crossDigit(s, i) || ans; // С������
		}
		return ans;
	}
};


void test_65() {
	cout << (Solution_65().isNumber("53.5e-93")) << endl;
}