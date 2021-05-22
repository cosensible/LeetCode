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
			// ���м�Ԫ�ص�������Ԫ�أ��޷��ж��м�Ԫ�������������黹�������������飬���ұ߽��ƶ�һ��
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