#include "common.h"

using namespace std;

class Solution_128 {
public:
	int longestConsecutive(vector<int>& nums) {
		// hash_set 去重, 常数级时间复杂度判断 num 是否存在
		unordered_set<int> s(nums.begin(), nums.end());
		int maxLen = 0, curLen = 0;
		for (int num : s) {
			// 处于以 num+1 开始的连续递减序列中, 跳过
			if (!s.count(num + 1)) {
				for (curLen = 1; s.count(num - 1); --num)
					++curLen;
				maxLen = max(maxLen, curLen);
			}
		}
		return maxLen;
	}
};

void test_128() {
	vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };
	cout << (Solution_128().longestConsecutive(nums) == 9) << endl;
}