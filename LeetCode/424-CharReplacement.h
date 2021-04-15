#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_424 {
public:
	int characterReplacement(string s, int k) {
		int l = 0, r = 0;  // �����������ұ߽�
		int maxcnt = 0; // ��ʷ�����г��ֹ��������ĸ������
		vector<int> cnt(26, 0); // ��¼�����и�����ĸ������
		while (r < s.size()) {
			++cnt[s[r] - 'A'];
			maxcnt = max(maxcnt, cnt[s[r] - 'A']);
			if (r - l + 1 > maxcnt + k) { // ����k���޷���������, ������������
				--cnt[s[l] - 'A'];
				++l;
			}
			++r;
		}
		return r - l;
	}
};


void test_424() {
	cout << (Solution_424().characterReplacement("AABABBA", 1) == 4) << endl;
}