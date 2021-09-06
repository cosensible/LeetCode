#include <vector>
#include <iostream>
using namespace std;

class QuickSort {
public:
	void quickSort(vector<int> &nums, int l, int r) {
		if (l < r) {
			int m = partition(nums, l, r);
			quickSort(nums, l, m - 1);
			quickSort(nums, m + 1, r);
		}
	}

	int partition(vector<int> &nums, int l, int r) {
		int rd = l + rand() % (r - l + 1);
		swap(nums[rd], nums[r]);
		int i = l;
		for (int j = l; j < r; ++j) {
			if (nums[j] < nums[r]) {
				swap(nums[i++], nums[j]);
			}
		}
		swap(nums[i], nums[r]);
		return i;
	}
};

class HeapSort {
public:
	void heapSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = n / 2 - 1; i >= 0; --i) {
			heapfy(nums, i, n);
		}
		for (int i = n - 1; i > 0; --i) {
			swap(nums[0], nums[i]);
			heapfy(nums, 0, i);
		}
	}

	void heapfy(vector<int> &nums, int i, int len) {
		for (int k = 2 * i + 1; k < len; k = 2 * k + 1) {
			if (k + 1 < len&&nums[k + 1] > nums[k]) ++k;
			if (nums[k] > nums[i]) {
				swap(nums[i], nums[k]);
				i = k;
			}
			else {
				break;
			}
		}
	}
};

class MergeSort {
	vector<int> tmp;
public:
	void mergeSort(vector<int> &nums) {
		int n = nums.size();
		tmp.assign(n, 0);
		mergeSortCore(nums, 0, n - 1);
	}

	void mergeSortCore(vector<int> &nums, int l, int r) {
		if (l >= r) return;
		int m = l + ((r - l) >> 1);
		mergeSortCore(nums, l, m);
		mergeSortCore(nums, m + 1, r);
		merge(nums, l, r);
	}

	void merge(vector<int> &nums, int l, int r) {
		int m = l + ((r - l) >> 1);
		int i = l, j = m + 1, k = 0;
		while (i <= m && j <= r) {
			if (nums[i] <= nums[j])
				tmp[k++] = nums[i++];
			else
				tmp[k++] = nums[j++];
		}
		while (i <= m) {
			tmp[k++] = nums[i++];
		}
		while (j <= r) {
			tmp[k++] = nums[j++];
		}
		copy_n(tmp.begin(), k, nums.begin() + l);
	}
};

class Solution_912 {
public:
	vector<int> sortArray(vector<int>& nums) {
		// QuickSort qs;
		// qs.quickSort(nums, 0, int(nums.size()-1));

		// HeapSort hs;
		// hs.heapSort(nums);

		MergeSort ms;
		ms.mergeSort(nums);

		return nums;
	}
};

void test_912() {
	vector<int> nums = { 5,1,1,2,0,0 };
	Solution_912().sortArray(nums);
	for (int i : nums) cout << i << " "; // 0 0 1 1 2 5
	cout << endl;
}