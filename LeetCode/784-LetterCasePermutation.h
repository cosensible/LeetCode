#include "common.h"
using namespace std;

class Solution_784 {
	vector<string> res;
public:
	vector<string> letterCasePermutation(string S) {
		backtrack(S, 0);
		return res;
	}

private:
	void backtrack(string &S, int idx) {
		while (idx < S.size() && !letter(S[idx])) { ++idx; }
		if (idx >= S.size()) {
			res.push_back(S);
			return;
		}
		// 字母不变
		backtrack(S, idx + 1);
		// 字母反转
		if (S[idx] > 'Z') {
			S[idx] -= 32;
			backtrack(S, idx + 1);
			S[idx] += 32;
		}
		else {
			S[idx] += 32;
			backtrack(S, idx + 1);
			S[idx] -= 32;
		}
	}

	bool letter(char c) {
		return c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z';
	}
};

void test_784() {
	vector<string> res = Solution_784().letterCasePermutation("a1B2");
	for (const auto &s : res) {
		cout << s << endl;
	}
}