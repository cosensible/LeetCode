#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_18 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4) return res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j <= nums.size() - 1; ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int l = j + 1, r = nums.size() - 1;
				while (l < r) {
					int sum4 = nums[i] + nums[j] + nums[l] + nums[r];
					if (sum4 == target) {
						res.push_back({ nums[i],nums[j],nums[l],nums[r] });
						while (l < r&&nums[l + 1] == nums[l]) ++l;
						++l;
						while (l < r&&nums[r - 1] == nums[r]) --r;
						--r;
					}
					else if (sum4 < target) {
						while (l < r&&nums[l + 1] == nums[l]) ++l;
						++l;
					}
					else {
						while (l < r&&nums[r - 1] == nums[r]) --r;
						--r;
					}
				}
			}
		}
		return res;
	}

	vector<vector<int>> fourSum1(vector<int>& nums, int target) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.size() < 4) return res;

		for (int k = 0; k < nums.size(); ++k) {
			if (k > 0 && nums[k] == nums[k - 1]) continue;
			int target3 = target - nums[k];
			int i = k + 1, j = nums.size() - 1;
			// vector<vector<int>> res3=threeSum(nums,target3,i,j);
			vector<vector<int>> res3;
			threeSum(nums, res3, target3, i, j);
			for (auto &v : res3) {
				v.push_back(nums[k]);
				res.push_back(v);
			}
		}
		return res;
	}

private:
	void threeSum(vector<int> &nums, vector<vector<int>> &res, int target, int b, int e) {
		if (e - b + 1 < 3) return;
		for (int k = b; k <= e; ++k) {
			if (k > b&&nums[k] == nums[k - 1]) continue;
			int i = k + 1, j = e, twoSum = target - nums[k];
			while (i < j) {
				if (nums[i] + nums[j] == twoSum) {
					res.push_back({ nums[k],nums[i],nums[j] });
					while (i < j&&nums[i + 1] == nums[i]) ++i;
					while (i < j&&nums[j - 1] == nums[j]) --j;
					++i;
					--j;
				}
				else if (nums[i] + nums[j] < twoSum) {
					while (i < j&&nums[i + 1] == nums[i]) ++i;
					++i;
				}
				else {
					while (i < j&&nums[j - 1] == nums[j]) --j;
					--j;
				}
			}
		}
	}

	vector<vector<int>> threeSum(vector<int>& nums, int sum3, int b, int e) {
		vector<vector<int>> res;
		if (e - b + 1 < 3) return res;
		for (int i = b; i <= e; ++i) {
			// if (nums[i] > sum3) return res; // 正数越加越大, 负数越加越小, 不能按此条件剪枝
			if (i > b && nums[i] == nums[i - 1]) continue;
			int target = sum3 - nums[i];
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[j] + nums[k] == target) {
					res.push_back({ nums[i],nums[j],nums[k] });
					while (j < k&&nums[j + 1] == nums[j])++j;
					while (j < k&&nums[k - 1] == nums[k])--k;
					++j;
					--k;
				}
				else if (nums[j] + nums[k] < target) {
					while (j < k&&nums[j + 1] == nums[j]) ++j;
					++j;
				}
				else {
					while (j < k&&nums[k - 1] == nums[k])--k;
					--k;
				}
			}
		}
		return res;
	}
};


void test_18() {
	vector<int> nums = { 1,0,-1,0,-2,2 };
	auto res = Solution_18().fourSum(nums, 0);
	for (auto &v : res) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}