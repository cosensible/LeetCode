#include "common.h"

using namespace std;

class Solution_128 {
public:
	int longestConsecutive(vector<int>& nums) {
		// hash_set ȥ��, ������ʱ�临�Ӷ��ж� num �Ƿ����
		unordered_set<int> s(nums.begin(), nums.end());
		int maxLen = 0, curLen = 0;
		for (int num : s) {
			// ������ num+1 ��ʼ�������ݼ�������, ����
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