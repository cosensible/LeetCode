#include <vector>
#include <iostream>
using namespace std;

class MyHeapSort {
public:
	void sort(vector<int> &nums) {
		int n = nums.size();
		for (int i = n / 2 - 1; i >= 0; --i) {
			heapfy(nums, i, n);
		}

		for (int i = n - 1; i > 0; --i) {
			swap(nums[i], nums[0]);
			heapfy(nums, 0, i);
		}
	}

private:
	void heapfy(vector<int> &nums, int i, int len) {
		for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {
			if (k + 1 < len && nums[k] < nums[k + 1]) {
				k++;
			}
			if (nums[i] < nums[k]) {
				swap(nums[i], nums[k]);
				i = k;
			}
			else {
				break;
			}
		}
	}
};

void test_hpsort() {
	vector<int> nums = { 2,8,7,6,5,4,9,3,1 };
	MyHeapSort().sort(nums);
	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;
}