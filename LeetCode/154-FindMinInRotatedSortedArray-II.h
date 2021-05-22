#include <vector>
#include <iostream>
using namespace std;

class Solution_154 {
public:
	int findMin(vector<int>& nums) {
		int ans = INT_MIN;
		if (nums.empty()) return ans;
		if (nums.front() < nums.back()) return nums.front();
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			// 若中间元素等于两边元素，无法判断中间元素在左上升数组还是在右上升数组，左右边界移动一步
			if (nums[m] == nums[l] && nums[m] == nums[r]) {
				++l; --r;
			}
			else if (nums[m] > nums[r]) l = m + 1;
			else r = m;
		}
		return nums[r];
	}
};


void test_154() {
	vector<int> nums = { 2,2,2,0,2,2 };
	cout << (Solution_154().findMin(nums) == 0) << endl;
}