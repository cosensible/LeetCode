#include <set>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1438_Deque {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		deque<int> smlque, bigque; // ά����ǰ�����е���Сֵ�����ֵ, ��������ά����Сֵ, �ݼ�����ά�����ֵ
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
			// �������е����ֵ��ȥ��СֵΥ��Լ��, ��������߽� i ����
			if (bigque.front() - smlque.front() > limit) {
				if (bigque.front() == nums[i]) bigque.pop_front();
				if (smlque.front() == nums[i]) smlque.pop_front();
				++i;
			}
			else { // ����, ȡ�Ϸ�������ĳ���
				len = max(len, j - i + 1);
			}
		}
		return len;
	}
};

class Solution_1438_MultiSet {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		multiset<int> ms; // ���򼯺�, ����ά��������Ԫ�ص����ֵ����Сֵ
		int len = 0;
		for (int i = 0, j = 0; j < nums.size(); ++j) {
			ms.insert(nums[j]);
			if (*ms.rbegin() - *ms.begin() > limit) { // Υ��Լ��, ��߽�����
				ms.erase(ms.find(nums[i++])); // ɾ��һ�� nums[i]
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