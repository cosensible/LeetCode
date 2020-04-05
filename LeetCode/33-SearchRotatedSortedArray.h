#include <vector>
#include <iostream>

using namespace std;

class Solution_33 {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] > nums[r]) { //mid在左边递增数组
				if (target >= nums[l] && target < nums[mid])
					r = mid - 1;
				else l = mid + 1;
			}
			else { //mid在右边递增数组
				if (target > nums[mid] && target <= nums[r])
					l = mid + 1;
				else r = mid - 1;
			}
		}
		return -1;
	}
};

void test_33() {
	vector<int> vi = { 4,5,6,7,0,1,2 };
	int target1 = 0, target2 = 3;
	int res1 = 4, res2 = -1;
	Solution_33 s = Solution_33();
	cout << (s.search(vi, target1) == res1 && s.search(vi, target2) == res2) << endl;
}