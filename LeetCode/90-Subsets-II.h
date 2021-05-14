#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
���ݷ��⼯��

39. ����ܺ�

40. ����ܺ� II

46. ȫ����

47. ȫ���� II

77. ���

78. �Ӽ�

90. �Ӽ� II

�Ӽ��������˳���޹صģ�������˳���йص�
*/

class Solution_90 {
	vector<vector<int>> res;
	vector<int> subset;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return res;
	}

private:
	void dfs(vector<int> &nums, int i) {
		if (i == nums.size()) {
			res.push_back(subset);
			return;
		}

		int next = i + 1;
		// ѡ�� nums[i]
		subset.push_back(nums[i]);
		dfs(nums, next);
		subset.pop_back();

		// ��ѡ�� nums[i]�������� nums[i] ��ȵ�Ԫ�ض�����ѡ��
		while (next < nums.size() && nums[next] == nums[i]) ++next;
		dfs(nums, next);
	}
};


class Solution_90_Another {
	vector<vector<int>> res;
	vector<int> subset;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(false, nums, 0);
		return res;
	}

private:
	// chosen ����ǰһ��Ԫ���Ƿ�ѡ��
	// ���ǰһ��Ԫ��δ��ѡ���ҵ�ǰԪ����֮��ȣ�����ѡ��ǰԪ��
	void dfs(bool chosen, vector<int> &nums, int i) {
		if (i == nums.size()) {
			res.push_back(subset);
			return;
		}

		dfs(false, nums, i + 1); // ��ѡ�� nums[i]

		// nums[i]==nums[i-1]����δѡ�� nums[i-1]������ѡ�� nums[i]
		if (i > 0 && nums[i] == nums[i - 1] && !chosen) return;

		// ѡ�� nums[i]
		subset.push_back(nums[i]);
		dfs(true, nums, i + 1);
		subset.pop_back();
	}
};


void test_90() {
	vector<int> nums = { 5,5,5,5 };
	auto res = Solution_90_Another().subsetsWithDup(nums);
	for (auto &v : res) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}