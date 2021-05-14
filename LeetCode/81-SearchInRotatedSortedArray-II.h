#include <vector>
#include <iostream>
using namespace std;

class Solution_81 {
public:
	// 与 33 题唯一不同之处在于数组中的元素可以重复出现
	// 可能出现 nums[l]==nums[m]==nums[r] 的情况，导致无法判断中间元素属于左半数组还是右半数组
	bool search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (target == nums[m]) return true;
			// 中间元素等于左右两边元素，无法判断中间元素属于左半数组还是右半数组
			// 需要右移左边界、左移右边界
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				while (l <= r && nums[l] == nums[m])++l;
				while (l <= r && nums[r] == nums[m])--r;
				continue;
			}
			// 中间元素大于右边元素，该元素位于左半数组，[l,m] 为有序子数组
			if (nums[m] > nums[r]) {
				if (target >= nums[l] && target < nums[m]) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
			else { // 中间元素位于右半数组，[m,r] 为有序子数组
				if (target > nums[m] && target <= nums[r]) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		return false;
	}
};


void test_81() {
	vector<int> nums = { 1,0,1,1,1 };
	cout << (Solution_81().search(nums, 0)) << endl;
}