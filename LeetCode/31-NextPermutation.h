#include <iostream>
#include <vector>

using namespace std;

class Solution_31 {
public:
	// 对于任何给定序列的降序排列, 没有比之更大的排列
	// 从后往前找到第一个升序对[i-1,i], [i,n-1]为降序排列
	// 要找字典序下一个排列, 须在[i,n-1]中找最小元素nums[j], 使nums[j]>nums[i-1],
	// 交换nums[j]和nums[i-1], 再将逆序[i,n-1]变为顺序, 便得到下一个排列
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 1;
		for (; i > 0; --i) { // 找升序对
			if (nums[i] > nums[i - 1]) break;
		}
		if (i > 0) { // i==0, 无升序对
			for (int j = n - 1; j >= i; --j) {
				if (nums[j] > nums[i - 1]) {
					swap(nums[i - 1], nums[j]);
					break;
				}
			}
		}
		// 将逆序变为顺序
		for (int j = n - 1; j > i; --j, ++i) {
			swap(nums[i], nums[j]);
		}
	}
};

void test_31() {
	vector<int> vi = { 1,4,5,3,2 };
	Solution_31().nextPermutation(vi);
	vector<int> exp = { 1,5,2,3,4 };
	cout << (exp == vi) << endl;
}