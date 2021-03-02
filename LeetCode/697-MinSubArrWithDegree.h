#include <array>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_697 {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, array<int, 3>> mp; // 某数出现的频率、头和尾
		int degree = 0, res = nums.size();
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(nums[i]) == 0) { // 之前未出现过，得到头位置
				mp[nums[i]] = { 1,i,i };
			}
			else {
				++mp[nums[i]][0];
				mp[nums[i]][2] = i; // 不断更新，直到末位置
			}
			degree = max(degree, mp[nums[i]][0]);
		}
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			if (it->second[0] == degree) { // 只考虑频率最大的元素
				res = min(res, it->second[2] - it->second[1] + 1);
			}
		}
		return res;
	}
};

void test_697() {
	vector<int> nums = { 1, 2, 2, 3, 1 };
	cout << (Solution_697().findShortestSubArray(nums) == 2) << endl;
}