#include <vector>
#include <algorithm>
#include <iostream>

/*
Given an array `nums`, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

class Solution_283 {
public:
	void moveZeroes(std::vector<int>& nums) {

		//// stable_partition
		//std::stable_partition(nums.begin(), nums.end(), [](int i) {return i != 0; });

		int lastNotZero = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				nums[lastNotZero++] = nums[i];
			}
		}
		//for (int i = lastNotZero; i < nums.size(); ++i) {
		//	nums[i] = 0;
		//}
		memset(nums.data() + lastNotZero, 0, (nums.size() - lastNotZero) * sizeof(int));

		//// lastNotZero <= cur，碰到非 0 执行交换
		//for (int lastNotZero = 0, cur = 0; cur < nums.size(); ++cur) {
		//	if (nums[cur] != 0) {
		//		std::swap(nums[cur], nums[lastNotZero++]);
		//	}
		//}
	}
};

bool isVectorSame(const std::vector<int> &v1, const std::vector<int> &v2) {
	if (v1.size() != v2.size()) { return false; }
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) { return false; }
	}
	return true;
}

void test_283() {
	std::vector<int> iv1 = { 0,1,0,3,2 };
	std::vector<int> iv2 = { 1,3,2,0,0 };

	Solution_283().moveZeroes(iv1);
	std::cout << "test_283 : " << isVectorSame(iv1, iv2) << std::endl;
}