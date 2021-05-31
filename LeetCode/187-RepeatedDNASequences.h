#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution_187 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		const int L = 10;
		int n = s.size();
		if (n <= L) return {};

		int mask = 0; // ��ϣ���룺ÿ����ĸռ��λ��A00��B01��C10��D11�����ռ 20 λ���� int ��Χ��
		unordered_map<char, int> dict = { {'A',0},{'C',1},{'G',2},{'T',3} };
		unordered_map<int, int> mp; // ÿ�����룬��ÿ���ַ������ֵĴ���
		unordered_set<string> uss;  // ����������ֹ�ظ�

		for (int i = 0, j = 0; j < n; ++j) {
			mask <<= 2;
			mask |= dict[s[j]];
			mask &= ~(3 << (2 * L)); // ������ǰ�����Чλ����
			if (j >= L - 1) {
				if (mp.count(mask) != 0) // �����Ѿ����ֹ������뼯��
					uss.insert(s.substr(i, L));
				mp[mask]++;
				++i;
			}
		}
		vector<string> ans(uss.begin(), uss.end());
		return ans;
	}
};

void test_187() {
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	auto res = Solution_187().findRepeatedDnaSequences(s);
	for (string &s : res) {
		cout << s << endl;
	}
}