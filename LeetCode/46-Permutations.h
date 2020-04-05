#include <vector>

using namespace std;

class Solution_46 {
	vector<vector<int>> res;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> sol;
		help(nums, sol);
		return res;
	}

	void help(vector<int> &nums, vector<int> &sol) {
		if (sol.size() == nums.size()) {
			res.push_back(sol);
			return;
		}
		for (int i : nums) {
			if (find(sol.begin(), sol.end(), i) == sol.end()) {
				sol.push_back(i);
				help(nums, sol);
				sol.pop_back();
			}
		}
	}
};