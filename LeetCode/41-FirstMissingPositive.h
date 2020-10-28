#include "common.h"

using namespace std;

class Solution_41 {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};

void test_41() {
	vector<int> nums = { 0,1,1,2,2,4 };
	cout << (Solution_41().firstMissingPositive(nums) == 3) << endl;
}