#include <vector>
#include <iostream>

using namespace std;

class Solution_75 {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return;
		int i = 0, j = n - 1, p = 0;
		while (p <= j) { //j之后已经合法
			if (p < i) p = i; //i之前已经合法,防止p对其造成破坏
			if (nums[p] == 0 && p != i) {
				swap(nums[p], nums[i]); //此处swap函数要求 p!=i
				i++;
			}
			else if (nums[p] == 2 && p != j) {
				swap(nums[p], nums[j]);
				j--;
			}
			else p++;
		}
	}
};

void test_75() {
	vector<int> nums = { 1,0,2,1,1,0 };
	vector<int> res = { 0,0,1,1,1,2 };
	Solution_75().sortColors(nums);
	auto comp = [](const vector<int> &nums1, const vector<int> &nums2) {
		if (nums1.size() != nums2.size()) return false;
		for (int i = 0; i < nums1.size(); i++) {
			if (nums1[i] != nums2[i]) return false;
		}
		return true;
	};
	cout << comp(nums, res) << endl;
}