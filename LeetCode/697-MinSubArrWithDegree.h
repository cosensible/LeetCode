#include <array>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_697 {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, array<int, 3>> mp; // ĳ�����ֵ�Ƶ�ʡ�ͷ��β
		int degree = 0, res = nums.size();
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(nums[i]) == 0) { // ֮ǰδ���ֹ����õ�ͷλ��
				mp[nums[i]] = { 1,i,i };
			}
			else {
				++mp[nums[i]][0];
				mp[nums[i]][2] = i; // ���ϸ��£�ֱ��ĩλ��
			}
			degree = max(degree, mp[nums[i]][0]);
		}
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			if (it->second[0] == degree) { // ֻ����Ƶ������Ԫ��
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