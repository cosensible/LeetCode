#include "common.h"
using namespace std;

class Solution_6 {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		string ret; // ������
		int n = s.size();
		int cycleLen = 2 * numRows - 2; // ÿ�����ڰ�����ĸ������ (|/)

		for (int i = 0; i < numRows; i++) { // ���й������ַ���
			for (int j = 0; j + i < n; j += cycleLen) { // j Ϊÿ�����ڵ����
				ret += s[j + i]; // ����ÿ�����ڵĵ�i����ĸ
				// �����Ϊ��β��, ��Ҫ���ϵڶ����� (/) ����ĸ, ������Ϊ j+cycLen-i
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
					ret += s[j + cycleLen - i];
			}
		}
		return ret;
	}
};


class Solution_6_Arr {
public:
	string convert(string s, int numRows) {
		if (numRows < 2) return s;
		vector<string> rows(min(numRows, (int)s.size()));

		int idx = 0, d = 1; // idx��ʾ��ǰ�ַ����ڵڼ���, dΪidx��ǰ������
		for (char c : s) {
			rows[idx] += c;
			idx += d;
			if (idx == numRows - 1 || idx == 0) d = -d; // ������β��, ����
		}
		for (int i = 1; i < rows.size(); ++i) {
			rows[0] += rows[i];
		}
		return rows[0];
	}
};

void test_6() {
	cout << (Solution_6_Arr().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI") << endl;
}