#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_164_BucketSort {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		// vmax vmin 分别为数组中的最大值与最小值
		int vmax = nums[0], vmin = nums[0];
		for (int i = 1; i < n; ++i) {
			vmax = max(vmax, nums[i]);
			vmin = min(vmin, nums[i]);
		}
		// 排序后数组中相邻数字的最大间距不会低于平均间距 (vmax-vmin)/(n-1)
		// 令桶的大小为 d=(vmax-vmin)//(n-1)，则最大间距一定不会出现在桶的内部，只可能出现在相邻的桶之间
		// 遍历数组，将元素放入对应的桶中，并记录每个桶的最大与最小元素，最大间距在相邻的桶之间产生
		int d = max(1, (vmax - vmin) / (n - 1)); // 桶的大小至少为 1
		int bktNum = (vmax - vmin) / d + 1;     // 桶的数量比间隙数多一
		// 记录每个桶的最大元素与最小元素，-1 表示桶中没有元素
		vector<int> bktMin(bktNum, -1);
		vector<int> bktMax(bktNum, -1);
		for (int x : nums) {
			int idx = (x - vmin) / d; // 元素属于哪个桶
			if (bktMin[idx] == -1) {
				bktMin[idx] = bktMax[idx] = x;
			}
			else {
				bktMin[idx] = min(bktMin[idx], x);
				bktMax[idx] = max(bktMax[idx], x);
			}
		}
		// 后一个桶的最小值减去前一个桶的最大值，第一个桶一定存在元素
		int ans = 0, pre = bktMax[0];
		for (int i = 1; i < bktNum; ++i) {
			if (bktMin[i] == -1) continue;
			ans = max(bktMin[i] - pre, ans);
			pre = bktMax[i];
		}
		return ans;
	}
};

class Solution_164_RadixSort {
public:
	// 基数排序：int 最大为十位数，每一位排序都用到了计数排序
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) { return 0; }
		int exp = 1;
		vector<int> buf(n);
		int maxVal = *max_element(nums.begin(), nums.end());

		while (maxVal >= exp) {
			vector<int> cnt(10);
			for (int i = 0; i < n; i++) {
				int digit = (nums[i] / exp) % 10;
				cnt[digit]++;
			}
			for (int i = 1; i < 10; i++) {
				cnt[i] += cnt[i - 1];
			}
			// 计数排序，从后往前遍历，保持稳定性
			for (int i = n - 1; i >= 0; i--) {
				int digit = (nums[i] / exp) % 10;
				buf[cnt[digit] - 1] = nums[i];
				cnt[digit]--;
			}
			copy(buf.begin(), buf.end(), nums.begin());
			if (exp > INT_MAX / 10) break;
			exp *= 10;
		}

		int ret = 0;
		for (int i = 1; i < n; i++) {
			ret = max(ret, nums[i] - nums[i - 1]);
		}
		return ret;
	}
};

class Solution_164_CompareSort {
public:
	int maximumGap(vector<int>& nums) {
		int ans = 0;
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			ans = max(ans, nums[i] - nums[i - 1]);
		}
		return ans;
	}
};

void test_164() {
	vector<int> nums = { 3,6,9,1 };
	cout << (Solution_164_BucketSort().maximumGap(nums) == 3) << endl;
}