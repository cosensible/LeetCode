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

		int mask = 0; // 哈希掩码：每个字母占两位，A00，B01，C10，D11，最多占 20 位，在 int 范围内
		unordered_map<char, int> dict = { {'A',0},{'C',1},{'G',2},{'T',3} };
		unordered_map<int, int> mp; // 每个掩码，即每个字符串出现的次数
		unordered_set<string> uss;  // 保存结果，防止重复

		for (int i = 0, j = 0; j < n; ++j) {
			mask <<= 2;
			mask |= dict[s[j]];
			mask &= ~(3 << (2 * L)); // 将掩码前面的无效位置零
			if (j >= L - 1) {
				if (mp.count(mask) != 0) // 掩码已经出现过，加入集合
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