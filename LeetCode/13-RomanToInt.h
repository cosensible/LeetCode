#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution_13 {
public:
	int romanToInt(string s) {
		// unordered_map<string,int> mp={
		//     {"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},
		//     {"IX",9},{"V",5},{"IV",4},{"I",1}
		// };

		vector<int> m(26, 0);
		m['I' - 'A'] = 1;
		m['V' - 'A'] = 5;
		m['X' - 'A'] = 10;
		m['L' - 'A'] = 50;
		m['C' - 'A'] = 100;
		m['D' - 'A'] = 500;
		m['M' - 'A'] = 1000;

		int ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (i + 1 < s.size()) {
				// 把一个小值放在大值的左边，需要做减法，否则做加法
				if (m[s[i + 1] - 'A'] > m[s[i] - 'A']) {
					ans -= m[s[i] - 'A'];
					continue;
				}
			}
			ans += m[s[i] - 'A'];
		}
		return ans;
	}
};

void test_13() {
	cout << (Solution_13().romanToInt("MCMXCIV") == 1994) << endl;
}