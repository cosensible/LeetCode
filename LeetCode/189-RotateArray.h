#include <vector>
#include <iostream>
using namespace std;

class Solution_189_Recurrent {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		if (n < 2 || k == 0) return;

		int start = 0; // 每一次循环的起点，当 n 整除 k 时，每次循环回到起点时会漏掉一些元素
		int cnt = 0;   // 已经归位的元素的数量
		while (cnt != n) {
			int tmp = nums[start]; // 保存被替换的元素
			int idx = start;
			do {
				int next = (idx + k) % n; // 元素的目标位置
				swap(tmp, nums[next]);
				idx = next;
				cnt++;
			} while (idx != start);
			start++;
		}
	}
};

class Solution_189_Reverse {
public:
	// 先反转整个数组，再分别反转子数组 [0,k) 和 [k,n)
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			swap(nums[i], nums[j]);
		}
		k %= n;
		for (int i = 0, j = k - 1; i < j; ++i, --j) {
			swap(nums[i], nums[j]);
		}
		for (int i = k, j = n - 1; i < j; ++i, --j) {
			swap(nums[i], nums[j]);
		}
	}
};

void test_189() {
	vector<int> nums = { 1,2,3,4,5,6 };
	int k = 3;
	Solution_189_Reverse().rotate(nums, k);
	for (int i : nums) cout << i << " ";
	cout << endl;
}