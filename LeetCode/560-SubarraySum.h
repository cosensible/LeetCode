#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution_560 {
	// 连续子数组(i,j]的和等于前缀和sum[j]-sum[i]
	// 若sum(i,j]==k, 有sum[j]-sum[i]==k
	// 设当前索引为 j, 需要看 j 之前有多少前缀和为 sum[j]-k
	// 从前往后遍历数组, 累加count得到结果
public:
	int subarraySum(vector<int>& nums, int k) {
		int count = 0, pre = 0;
		unordered_map<int, int> mp;
		mp[0] = 1;
		for (int n : nums) {
			pre += n;
			if (mp.find(pre - k) != mp.end()) {
				count += mp[pre - k];
			}
			mp[pre]++;
		}
		return count;
	}
};

void test_560() {
	vector<int> nums = { 1,1,1 };
	int k = 2;
	cout << Solution_560().subarraySum(nums, k) << endl;
}