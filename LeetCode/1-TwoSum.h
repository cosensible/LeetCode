#include <vector>
#include <map>
#include <iostream>

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution_1 {
public:
	std::vector<int> twoSum(std::vector<int> &nums, int target) {
		std::map<int, int> vis; // value-index-set
		for (int i = 0; i < nums.size(); ++i) {
			int match = target - nums[i];
			auto pos = vis.find(match);
			if (pos != vis.end()) {
				return { pos->second,i };
			}
			vis.insert({ nums[i],i });
		}
		return {};
	}
};

void test_1() {
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	std::vector<int> res = Solution_1().twoSum(nums, target);
	std::cout << "test_1 : " << (res[0] == 0 && res[1] == 1) << std::endl;
}