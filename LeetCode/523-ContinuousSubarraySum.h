#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution_523 {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		// (S[j]-S[i])%k==0 && j-i>1
		// S[j]%k == S[i]%k && j-i>1
		unordered_map<int, int> mp; // 记录前缀和对 k 的余数及其第一次出现的位置
		mp[0] = -1;
		int sum = 0; // 当前前缀和
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			int m = sum % k;
			if (mp.count(m)) {
				if (i - mp[m] > 1) return true;
			}
			else {
				mp[m] = i;
			}
		}
		return false;
	}
};

void test_523() {
	vector<int> nums = { 23,2,6,4,7 };
	cout << (Solution_523().checkSubarraySum(nums, 6) == true) << endl;
}