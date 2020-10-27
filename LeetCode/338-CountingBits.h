#include <vector>
#include <iostream>

using namespace std;

class Solution_338 {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
		//for (int i = 1; i <= num; ++i) {
		//	res[i] = res[i&(i - 1)] + 1;
		//}

		for (int i = 1; i <= num; ++i) {
			res[i] = i % 2 ? res[i / 2] + 1 : res[i / 2];
		}
		return res;
	}
};

void test_338() {
	auto compare = [](const vector<int> &vs1, const vector<int> &vs2) {
		if (vs1.size() != vs2.size()) return false;
		for (int i = 0; i < vs1.size(); ++i) {
			if (vs1[i] != vs2[i]) return false;
		}
		return true;
	};

	vector<int> exp = { 0,1,1,2,1,2 };
	vector<int> res = Solution_338().countBits(5);
	cout << compare(exp, res) << endl;
}