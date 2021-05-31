#include <vector>
#include <iostream>
using namespace std;

class Solution_477 {
public:
	int totalHammingDistanceNSquare(vector<int>& nums) {
		int num = 0;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				num += hammingDistance(nums[i], nums[j]);
			}
		}
		return num;
	}

	int totalHammingDistance(vector<int>& nums) {
		int ans = 0;
		int n = nums.size();
		for (int k = 0; k <= 30; ++k) {
			int cnt = 0;
			for (int x : nums) {
				if (x&(1 << k)) cnt++;
			}
			ans += (n - cnt)*cnt; // 每一位结果为 1 的数量为该位 0 的数量乘以 1 的数量
		}
		return ans;
	}

private:
	int hammingDistance(int a, int b) {
		int x = a ^ b;
		int cnt = 0;
		while (x) {
			cnt++;
			x = x & (x - 1);
		}
		return cnt;
	}
};

void test_477() {
	vector<int> nums = { 4,14,2 };
	cout << (Solution_477().totalHammingDistance(nums) == 6) << endl;
}