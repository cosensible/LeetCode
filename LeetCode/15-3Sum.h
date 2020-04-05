#include <vector>

using namespace std;

class Solution_15 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.front() > 0 || nums.back() < 0)
			return res;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) return res;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int target = -nums[i];
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[j] + nums[k] == target) {
					res.push_back({ -target,nums[j],nums[k] });
					while (j < k&&nums[j + 1] == nums[j])++j;
					while (j < k&&nums[k - 1] == nums[k])--k;
					++j;
					--k;
				}
				else if (nums[j] + nums[k] < target)
					++j;
				else --k;
			}
		}
		return res;
	}
};