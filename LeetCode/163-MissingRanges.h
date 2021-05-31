#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution_163 {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> ans;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == lower) ++lower;
			else {
				string interval = to_string(lower);
				if (lower != nums[i] - 1) {
					interval += "->";
					interval += to_string(nums[i] - 1);
				}
				ans.push_back(interval);
				lower = nums[i] + 1;
			}
		}
		if (lower <= upper) {
			string interval = to_string(lower);
			if (lower != upper) {
				interval += "->";
				interval += to_string(upper);
			}
			ans.push_back(interval);
		}
		return ans;
	}
};

void test_163() {
	vector<int> nums = { 0, 1, 3, 50, 75 };
	int lower = 0, upper = 99;
	auto ans = Solution_163().findMissingRanges(nums, lower, upper);
	for (auto &s : ans) {
		cout << s << " ";
	}
	cout << endl;
}