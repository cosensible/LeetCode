#include <vector>
#include <iostream>
using namespace std;

class Solution_153 {
public:
	int findMin(vector<int>& nums) {
		int ans = INT_MIN;
		if (nums.empty()) return ans;
		if (nums.front() < nums.back()) return nums.front();
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			// 中间元素在左上升数组，最小元素一定在右边
			if (nums[m] > nums[r]) l = m + 1;
			else r = m;
		}
		return nums[r];
	}
};


void test_153() {
	vector<int> nums = { 3,4,5,1,2 };
	cout << (Solution_153().findMin(nums) == 1) << endl;
}