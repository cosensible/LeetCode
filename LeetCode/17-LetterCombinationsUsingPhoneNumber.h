#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution_17 {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return res;
		string s(digits);
		backtrack(digits, 0, s);
		return res;
	}

private:
	vector<string> mp = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> res;

	void backtrack(const string &digits, int level, string &s) {
		if (level == digits.size()) {
			res.push_back(s);
			return;
		}
		int id = digits[level] - 48;
		for (char c : mp[id]) {
			s[level] = c;
			backtrack(digits, level + 1, s);
		}
	}
};

void test_17() {
	//string s = "23";
	//vector<string> excp = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };

	string s = "";
	vector<string> excp;

	vector<string> res = Solution_17().letterCombinations(s);

	auto compare = [](const vector<string> &vs1, const vector<string> &vs2) {
		if (vs1.size() != vs2.size()) return false;
		for (int i = 0; i < vs1.size(); ++i) {
			if (vs1[i] != vs2[i]) return false;
		}
		return true;
	};
	cout << compare(excp, res) << endl;
}