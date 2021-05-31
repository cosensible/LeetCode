#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution_164_BucketSort {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		// vmax vmin �ֱ�Ϊ�����е����ֵ����Сֵ
		int vmax = nums[0], vmin = nums[0];
		for (int i = 1; i < n; ++i) {
			vmax = max(vmax, nums[i]);
			vmin = min(vmin, nums[i]);
		}
		// ������������������ֵ�����಻�����ƽ����� (vmax-vmin)/(n-1)
		// ��Ͱ�Ĵ�СΪ d=(vmax-vmin)//(n-1)���������һ�����������Ͱ���ڲ���ֻ���ܳ��������ڵ�Ͱ֮��
		// �������飬��Ԫ�ط����Ӧ��Ͱ�У�����¼ÿ��Ͱ���������СԪ�أ�����������ڵ�Ͱ֮�����
		int d = max(1, (vmax - vmin) / (n - 1)); // Ͱ�Ĵ�С����Ϊ 1
		int bktNum = (vmax - vmin) / d + 1;     // Ͱ�������ȼ�϶����һ
		// ��¼ÿ��Ͱ�����Ԫ������СԪ�أ�-1 ��ʾͰ��û��Ԫ��
		vector<int> bktMin(bktNum, -1);
		vector<int> bktMax(bktNum, -1);
		for (int x : nums) {
			int idx = (x - vmin) / d; // Ԫ�������ĸ�Ͱ
			if (bktMin[idx] == -1) {
				bktMin[idx] = bktMax[idx] = x;
			}
			else {
				bktMin[idx] = min(bktMin[idx], x);
				bktMax[idx] = max(bktMax[idx], x);
			}
		}
		// ��һ��Ͱ����Сֵ��ȥǰһ��Ͱ�����ֵ����һ��Ͱһ������Ԫ��
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
	// ��������int ���Ϊʮλ����ÿһλ�����õ��˼�������
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
			// �������򣬴Ӻ���ǰ�����������ȶ���
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