#include <vector>
using namespace std;

// 迭代解法：每个数选与不选与二进制联系起来
// 递归解法：回溯算法

class Solution_78 {
	vector<vector<int>> res;
	vector<int> subset;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		dfs(nums, 0);
		return res;
	}

private:
	void dfs(vector<int> &nums, int i) {
		if (i == nums.size()) {
			res.push_back(subset);
			return;
		}
		dfs(nums, i + 1); // 不选择 nums[i]
		// 选择 nums[i]
		subset.push_back(nums[i]);
		dfs(nums, i + 1);
		subset.pop_back();
	}
};


class Solution_78_Another {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> sol;
		help(nums, sol, 0);
		return res;
	}

private:
	vector<vector<int>> res;

	void help(vector<int> &nums, vector<int> &sol, int k) {
		res.push_back(sol);
		for (int i = k; i < nums.size(); ++i) {
			sol.push_back(nums[i]);
			help(nums, sol, i + 1);
			sol.pop_back();
		}
	}
};


void test_78() {
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = Solution_78().subsets(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}