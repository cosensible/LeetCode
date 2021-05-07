#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution_91 {
public:
	int numDecodings(string s) {
		if (s.empty()) return 1;
		int pre2 = 1, pre1 = s[0] == '0' ? 0 : 1;

		for (int i = 2; i <= s.size(); ++i) {
			int snum = 0;
			int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
			if (s[i - 1] != '0') // 最后一位不为 0
				snum += pre1;
			if (s[i - 2] != '0' && num >= 10 && num <= 26) // 倒数第二位不为 0 且组成的数在 [10,26] 范围内
				snum += pre2;
			pre2 = pre1;
			pre1 = snum;
		}
		return pre1;
	}
};


void test_91() {
	cout << (Solution_91().numDecodings("12") == 2) << endl;
}