#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution_581 {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		int minNum = INT_MAX, maxNum = INT_MIN;
		for (int i = 1; i < n; ++i) {
			if (nums[i] < nums[i - 1]) {
				minNum = min(minNum, nums[i]);
				maxNum = max(maxNum, nums[i - 1]);
			}
		}
		int l = 0, r = n - 1;
		while (l < r&&nums[l] <= minNum) ++l;
		while (l < r&&nums[r] >= maxNum) --r;

		return r > l ? r - l + 1 : 0;
	}
};

void test_581() {
	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
	cout << (Solution_581().findUnsortedSubarray(nums) == 5) << endl;
}