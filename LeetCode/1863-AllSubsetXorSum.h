#include <vector>
#include <iostream>
using namespace std;

// 子集问题：bitmask 或 回溯
class Solution_1863_Bitmask {
public:
	int subsetXORSum(vector<int>& nums) {
		int ans = 0;
		for (int i = 1; i < (1 << nums.size()); ++i) {
			int x = 0;
			for (int j = 0; j < nums.size(); ++j) {
				if (i&(1 << j)) x ^= nums[j];
			}
			ans += x;
		}
		return ans;
	}
};

class Solution_1863_Backtrack {
	int res = 0;
public:
	int subsetXORSum(vector<int>& nums) {
		backtrack(nums, 0, 0);
		return res;
	}

private:
	void backtrack(vector<int> &nums, int i, int cxor) {
		if (i == nums.size()) {
			res += cxor;
			return;
		}
		backtrack(nums, i + 1, cxor);
		backtrack(nums, i + 1, cxor^nums[i]);
	}
};

void test_1863() {
	vector<int> nums = { 5,1,6 };
	cout << (Solution_1863_Bitmask().subsetXORSum(nums) == 28 && Solution_1863_Backtrack().subsetXORSum(nums) == 28) << endl;
}