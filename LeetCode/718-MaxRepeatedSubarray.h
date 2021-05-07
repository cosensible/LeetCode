#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_718 {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		// 最长重复子串一定是从某相等位置 A[i]==B[j] 开始，一直到 A[i+]!=B[j+]
		// dp[i][j] 表示从 A[i] 和 B[j] 开始的最长重复前缀
		// 答案是求所有最长重复前缀 dp[i][j] 的最大值
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		int ans = 0;
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (nums1[i] != nums2[j])
					dp[i][j] = 0;
				else {
					dp[i][j] = dp[i + 1][j + 1] + 1;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		return ans;
	}
	// 滚动数组，优化空间复杂度
	int findLength_ScrollingArray(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		vector<int> dp(n + 1, 0);
		int ans = 0;
		for (int i = m - 1; i >= 0; --i) {
			for (int j = 0; j < n; ++j) {
				if (nums1[i] != nums2[j])
					dp[j] = 0;
				else {
					dp[j] = dp[j + 1] + 1;
					ans = max(ans, dp[j]);
				}
			}
		}
		return ans;
	}
};

class Solution_718_SlidingWindow {
public:
	int maxLength(vector<int>& A, vector<int>& B, int addA, int addB, int len) {
		int ret = 0, k = 0;
		for (int i = 0; i < len; i++) {
			if (A[addA + i] == B[addB + i]) {
				k++;
			}
			else {
				k = 0;
			}
			ret = max(ret, k);
		}
		return ret;
	}
	int findLength(vector<int>& A, vector<int>& B) {
		int n = A.size(), m = B.size();
		int ret = 0;
		for (int i = 0; i < n; i++) {//此时A不断左移，使用不同的元素对齐B首元素
			int len = min(m, n - i);
			if (len <= ret)
				break;
			int maxlen = maxLength(A, B, i, 0, len);
			ret = max(ret, maxlen);
		}
		for (int i = 0; i < m; i++) {//B不断左移
			int len = min(n, m - i);
			if (len <= ret)
				break;
			int maxlen = maxLength(A, B, 0, i, len);
			ret = max(ret, maxlen);
		}
		return ret;
	}
};


void test_718() {
	vector<int> nums1 = { 1,2,3,2,1 };
	vector<int> nums2 = { 3,2,1,4,7 };
	cout << (Solution_718().findLength_ScrollingArray(nums1, nums2) == 3) << endl;
}