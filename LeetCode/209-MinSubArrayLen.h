#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_209 {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int i = 0, j = 0, n = nums.size();
		int sum = 0, len = n + 1;
		while (j < n) {
			sum += nums[j];
			while (sum >= target) {
				len = min(len, j - i + 1);
				sum -= nums[i];
				++i;
			}
			++j;
		}
		return len == n + 1 ? 0 : len;
	}
};

void test_209() {
	vector<int> nums = { 2,3,1,2,4,3 };
	cout << (Solution_209().minSubArrayLen(7, nums) == 2) << endl;
}