#include <vector>
#include <iostream>
using namespace std;

class Solution_477 {
public:
	//int totalHammingDistance(vector<int>& nums) {
	//	int num = 0;
	//	for (int i = 0; i < nums.size(); ++i) {
	//		for (int j = i + 1; j < nums.size(); ++j) {
	//			num += hammingDistance(nums[i], nums[j]);
	//		}
	//	}
	//	return num;
	//}
	//int hammingDistance(int a, int b) {
	//	int c = a ^ b;
	//	int num = 0;
	//	while (c > 0) {
	//		num += (c & 1);
	//		c >>= 1;
	//	}
	//	return num;
	//}

	int totalHammingDistance(vector<int>& nums) {
		int sum = 0, n = nums.size();
		for (int i = 0, mask = 1; i < 31; mask <<= 1, ++i) {
			int cnt1 = 0;
			for (int num : nums) {
				if (num&mask) { ++cnt1; }
			}
			sum += cnt1 * (n - cnt1); // 该位为一的个数乘以该位为零的个数
		}
		return sum;
	}
};

void test_477() {
	vector<int> nums = { 4,14,2 };
	cout << (Solution_477().totalHammingDistance(nums) == 6) << endl;
}