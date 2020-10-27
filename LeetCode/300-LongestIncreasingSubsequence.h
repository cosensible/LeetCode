#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_300 {
public:
	/*  增加数组长度的唯一情形是新元素比数组尾元素大
		用较小值更新数组能保证数组尾元素尽可能小
		以此能确保找到LIS的正确长度
	*/
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
			if (it == dp.end()) dp.push_back(nums[i]);
			else *it = nums[i];
		}
		return dp.size();
	}
};

void test_300() {
	vector<int> vi = { 10,9,2,5,1,7,101,18 };
	cout << (Solution_300().lengthOfLIS(vi) == 4) << endl;
}