#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
回溯法题集：

39. 组合总和

40. 组合总和 II

46. 全排列

47. 全排列 II

77. 组合

78. 子集

90. 子集 II

子集、组合是顺序无关的，排列是顺序有关的
*/

class Solution_90 {
	vector<vector<int>> res;
	vector<int> subset;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return res;
	}

private:
	void dfs(vector<int> &nums, int i) {
		if (i == nums.size()) {
			res.push_back(subset);
			return;
		}

		int next = i + 1;
		// 选择 nums[i]
		subset.push_back(nums[i]);
		dfs(nums, next);
		subset.pop_back();

		// 不选择 nums[i]，后面与 nums[i] 相等的元素都不能选择
		while (next < nums.size() && nums[next] == nums[i]) ++next;
		dfs(nums, next);
	}
};


class Solution_90_Another {
	vector<vector<int>> res;
	vector<int> subset;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(false, nums, 0);
		return res;
	}

private:
	// chosen 代表前一个元素是否被选择
	// 如果前一个元素未被选择且当前元素与之相等，则不能选择当前元素
	void dfs(bool chosen, vector<int> &nums, int i) {
		if (i == nums.size()) {
			res.push_back(subset);
			return;
		}

		dfs(false, nums, i + 1); // 不选择 nums[i]

		// nums[i]==nums[i-1]，且未选择 nums[i-1]，则不能选择 nums[i]
		if (i > 0 && nums[i] == nums[i - 1] && !chosen) return;

		// 选择 nums[i]
		subset.push_back(nums[i]);
		dfs(true, nums, i + 1);
		subset.pop_back();
	}
};


void test_90() {
	vector<int> nums = { 5,5,5,5 };
	auto res = Solution_90_Another().subsetsWithDup(nums);
	for (auto &v : res) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}