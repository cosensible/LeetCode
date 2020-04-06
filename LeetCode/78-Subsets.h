#include <vector>

using namespace std;

class Solution_78 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> sol;
		help(nums, sol, 0);
		return res;
	}

private:
	vector<vector<int>> res;

	void help(vector<int> &nums, vector<int> &sol, int k) {
		res.push_back(sol);
		for (int i = k; i < nums.size(); ++i) {
			sol.push_back(nums[i]);
			help(nums, sol, i + 1);
			sol.pop_back();
		}
	}
};

void test_78() {
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = Solution_78().subsets(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << ",";
		}
		cout << endl;
	}
}