#include <vector>
#include <iostream>

using namespace std;

class Solution_34 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = left(nums, target);
		int r = right(nums, target);
		if (l > r) return { -1,-1 };
		return { l,r };
	}
	int left(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] < target)
				l = mid + 1;
			else r = mid - 1;
		}
		return r + 1;
	}
	int right(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] > target)
				r = mid - 1;
			else l = mid + 1;
		}
		return l - 1;
	}
};

void test_34() {
	vector<int> nums = { 5,7,7,8,8,10 };
	int target1 = 8, target2 = 6;
	Solution_34 s;
	vector<int> res1 = s.searchRange(nums, target1);
	vector<int> res2 = s.searchRange(nums, target2);
	cout << (res1[0] == 3 && res1[1] == 4 && res2[0] == -1 && res2[1] == -1) << endl;
}