#include <vector>
#include <iostream>

using namespace std;

class Solution_53 {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = 0, curSum = 0;
		int start = 0, end = 0;
		for (int i = 0; i < nums.size(); ++i) {
			curSum += nums[i];
			if (curSum < 0) {
				curSum = 0;
				start = i + 1;
			}
			if (curSum > maxSum) {
				maxSum = curSum;
				end = i;
			}
		}
		for (int i = start; i <= end; ++i) {
			cout << nums[i] << ",";
		}
		cout << endl;

		return maxSum;

		// ·ÖÖÎ·¨
		// return divideConquer(nums,0,nums.size()-1);
	}

private:
	int divideConquer(const vector<int> &nums, int b, int e) {
		if (e == b) { return nums[b]; }
		// if(e==b){
		//     return nums[b]>0?nums[b]:0;
		// }
		int len = (e + b) / 2;
		int left = divideConquer(nums, b, len);
		int right = divideConquer(nums, len + 1, e);

		int midl = INT_MIN, tmp = 0;
		for (int i = len; i >= 0; --i) {
			tmp += nums[i];
			midl = tmp > midl ? tmp : midl;
		}
		tmp = 0; int midr = INT_MIN;
		for (int i = len + 1; i <= e; ++i) {
			tmp += nums[i];
			midr = tmp > midr ? tmp : midr;
		}
		return max(max(left, right), midl + midr);
	}
};

void test_53() {
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << Solution_53().maxSubArray(nums) << endl;
}