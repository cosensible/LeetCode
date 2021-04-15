#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_16 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int diff = INT_MAX, ans = 0;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size(); ++k) {
			if (k > 0 && nums[k] == nums[k - 1]) { continue; }
			for (int i = k + 1, j = nums.size() - 1; i < j;) {
				int sum = nums[k] + nums[i] + nums[j];
				if (abs(sum - target) < diff) {
					ans = sum;
					diff = abs(sum - target);
					if (diff == 0) return ans;
				}
				if (sum < target) {
					while (i < j && nums[i + 1] == nums[i]) ++i;
					++i;
				}
				else if (sum > target) {
					while (i < j && nums[j - 1] == nums[j]) --j;
					--j;
				}
			}
		}
		return ans;
	}
};


void test_16() {
	vector<int> nums = { -1,2,1,-4 };
	cout << (Solution_16().threeSumClosest(nums, 1) == 2) << endl;
}