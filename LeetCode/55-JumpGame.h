#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<bool> can(n, false);
		can[n - 1] = true;
		for (int i = n - 2; i >= 0; i--) {
			int maxr = min(nums[i] + i, n - 1);
			for (int j = i + 1; j <= maxr; ++j) {
				if (can[j]) {
					can[i] = true;
					break;
				}
			}
		}
		return can[0];
	}
};

class Solution_55 {
public:
	bool canJump(vector<int>& nums) {
		int lastPos = nums.size() - 1;
		for (int i = lastPos - 1; i >= 0; i--) {
			if (i + nums[i] >= lastPos) lastPos = i;
		}
		return lastPos == 0;
	}
};

void test_55() {
	vector<int> nums;
	cout << Solution_55().canJump(nums) << endl;
}