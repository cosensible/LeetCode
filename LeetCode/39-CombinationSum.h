#include <vector>

using namespace std;

class Solution_39 {
	vector<vector<int>> res;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> sol;
		combination(candidates, target, sol, 0);
		return res;
	}

	void combination(vector<int> &candidates, int target, vector<int> &sol, int k) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(sol);
			return;
		}
		for (int i = k; i < candidates.size(); ++i) {
			sol.push_back(candidates[i]);
			combination(candidates, target - candidates[i], sol, i);
			sol.pop_back();
		}
	}
};