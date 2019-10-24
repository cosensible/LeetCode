#include <vector>
#include <iostream>

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/

class Solution_136 {
public:
	int singleNumber(std::vector<int> &nums) {
		for (int i = 1; i < nums.size(); ++i) {
			nums[0] ^= nums[i];	// 所有元素异或
		}
		return nums[0];
	}
};

void test_136() {
	std::vector<int> nums = { 2,1,2,3,1 };
	std::cout << "test_136 : " << (Solution_136().singleNumber(nums) == 3) << std::endl;
}