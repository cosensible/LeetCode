#include <vector>
#include <iostream>
using namespace std;


// 由于 nums[-1]==nums[n] == -INF，且 nums[i]!=nums[i+1]，故一定存在峰值
// 因为返回任意一个峰值都可，所以可以采用二分法来寻找峰值
// 若 nums[m]>nums[m+1]，则 nums[m] 处于下降段，其左侧一定存在峰值元素 (nums[-1] == -INF)
// 否则 nums[m] 处于上升段，其右侧一定存在峰值元素 (nums[n] == -INF)

class Solution_162 {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return -1; // 无元素，无峰值
		int l = 0, r = n - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			// 中间元素是否大于左边元素
			bool left = m == 0 ? true : nums[m] > nums[m - 1];
			// 中间元素是否大于右边元素
			bool right = m == n - 1 ? true : nums[m] > nums[m + 1];
			if (left && right) return m; // nums[m] 为峰值元素
			if (nums[m] > nums[m + 1]) r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
};


void test_162() {
	vector<int> nums = { 1,2,1,3,5,6,4 };
	int ans = Solution_162().findPeakElement(nums);
	cout << (ans == 1 || ans == 5) << endl;
}