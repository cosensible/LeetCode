#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution_560 {
	// ����������(i,j]�ĺ͵���ǰ׺��sum[j]-sum[i]
	// ��sum(i,j]==k, ��sum[j]-sum[i]==k
	// �赱ǰ����Ϊ j, ��Ҫ�� j ֮ǰ�ж���ǰ׺��Ϊ sum[j]-k
	// ��ǰ�����������, �ۼ�count�õ����
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