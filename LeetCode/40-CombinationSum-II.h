#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_40 {
	vector<int> nums;
	vector<vector<int>> res;
	unordered_map<int, int> mp; // ����ÿ�����ֳ��ֵĴ���
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end()); // ����󷽱�������һ������
		for (int i : candidates) mp[i]++;
		dfs(candidates, target, 0);
		return res;
	}

private:
	void dfs(vector<int>& candidates, int target, int start) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(nums);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			if (target - candidates[i] < 0) break; // �������򣬿��Լ�֦
			// ÿ������ֻ�ܿ���һ��
			if (i > start && candidates[i] == candidates[i - 1]) continue;
			int t = mp[candidates[i]]; // ���ֵĸ���
			for (int k = 1; k <= t; ++k) { // �о�״̬��ѡ�����ֵĸ���
				nums.push_back(candidates[i]);
				// �ı� target������δ�����ǹ�����������ѡ��
				dfs(candidates, target - candidates[i] * k, i + t);
			}
			// ����ѡ�񣬻ָ�״̬���൱�ڲ�ѡ��ǰ����
			for (int j = 0; j < t; ++j) nums.pop_back();
		}
	}
};


class Solution_40_Another {
	vector<int> nums;
	vector<vector<int>> res;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end()); // ���򷽱�ȥ��
		dfs(candidates, target, 0);
		return res;
	}

private:
	void dfs(vector<int>& candidates, int target, int start) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(nums);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			if (target - candidates[i] < 0) break; // �������򣬿��Լ�֦
			// ÿ������ֻ�ܿ���һ��
			if (i > start && candidates[i] == candidates[i - 1]) continue;

			nums.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i + 1);

			// ����ѡ�񣬻ָ�״̬���൱�ڲ�ѡ��ǰ����
			nums.pop_back();
		}
	}
};


void test_40() {
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	Solution_40().combinationSum2(candidates, 8);
}