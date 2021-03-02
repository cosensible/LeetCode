#include <set>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1438_Deque {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		deque<int> smlque, bigque; // 维护当前窗口中的最小值和最大值, 递增队列维护最小值, 递减队列维护最大值
		int len = 0;
		for (int i = 0, j = 0; j < nums.size(); ++j) {
			while (!smlque.empty() && nums[j] < smlque.back()) {
				smlque.pop_back();
			}
			while (!bigque.empty() && nums[j] > bigque.back()) {
				bigque.pop_back();
			}
			smlque.push_back(nums[j]);
			bigque.push_back(nums[j]);
			// 若窗口中的最大值减去最小值违反约束, 将窗口左边界 i 右移
			if (bigque.front() - smlque.front() > limit) {
				if (bigque.front() == nums[i]) bigque.pop_front();
				if (smlque.front() == nums[i]) smlque.pop_front();
				++i;
			}
			else { // 否则, 取合法子数组的长度
				len = max(len, j - i + 1);
			}
		}
		return len;
	}
};

class Solution_1438_MultiSet {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		multiset<int> ms; // 有序集合, 用于维护窗口中元素的最大值和最小值
		int len = 0;
		for (int i = 0, j = 0; j < nums.size(); ++j) {
			ms.insert(nums[j]);
			if (*ms.rbegin() - *ms.begin() > limit) { // 违反约束, 左边界右移
				ms.erase(ms.find(nums[i++])); // 删除一个 nums[i]
			}
			else {
				len = max(len, j - i + 1);
			}
		}
		return len;
	}
};

void test_1438() {
	vector<int> vi = { 10,1,2,4,7,2 };
	cout << (Solution_1438_Deque().longestSubarray(vi, 5) == 4) << endl;
}