#include <vector>
#include <iostream>
using namespace std;

class Solution_77 {
	vector<vector<int>> res;
	vector<int> combination;
public:
	vector<vector<int>> combine(int n, int k) {
		if (n < 1 || k < 1 || n < k) return res;
		backtrack(n, k, 1);
		return res;
	}

private:
	void backtrack(int n, int k, int i) {
		// 记录合法答案
		if (combination.size() == k) {
			res.push_back(combination);
			return;
		}
		// 剪枝：不可能形成长度为 k 的组合
		if (combination.size() + n - i + 1 < k) return;
		// 不选择 i
		backtrack(n, k, i + 1);
		// 选择 i
		combination.push_back(i);
		backtrack(n, k, i + 1);
		combination.pop_back();
	}
};


void test_77() {
	auto res = Solution_77().combine(4, 2);
	for (auto &v : res) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}