#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_40 {
	vector<int> nums;
	vector<vector<int>> res;
	unordered_map<int, int> mp; // 保存每个数字出现的次数
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end()); // 排序后方便跳到下一个数字
		for (int i : candidates) mp[i]++;
		dfs(candidates, target, 0);
		return res;
	}

private:
	void dfs(vector<int>& candidates, int target, int start) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(nums);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			if (target - candidates[i] < 0) break; // 数组排序，可以剪枝
			// 每种数字只能考虑一次
			if (i > start && candidates[i] == candidates[i - 1]) continue;
			int t = mp[candidates[i]]; // 数字的个数
			for (int k = 1; k <= t; ++k) { // 列举状态：选择数字的个数
				nums.push_back(candidates[i]);
				// 改变 target，并从未被考虑过的数字中做选择
				dfs(candidates, target - candidates[i] * k, i + t);
			}
			// 做完选择，恢复状态，相当于不选择当前数字
			for (int j = 0; j < t; ++j) nums.pop_back();
		}
	}
};


class Solution_40_Another {
	vector<int> nums;
	vector<vector<int>> res;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end()); // 排序方便去重
		dfs(candidates, target, 0);
		return res;
	}

private:
	void dfs(vector<int>& candidates, int target, int start) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(nums);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			if (target - candidates[i] < 0) break; // 数组排序，可以剪枝
			// 每种数字只能考虑一次
			if (i > start && candidates[i] == candidates[i - 1]) continue;

			nums.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i + 1);

			// 做完选择，恢复状态，相当于不选择当前数字
			nums.pop_back();
		}
	}
};


void test_40() {
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	Solution_40().combinationSum2(candidates, 8);
}