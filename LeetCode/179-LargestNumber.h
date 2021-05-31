#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_179 {
public:
	// 按两个数的字符串相加后字典序的大小从大到小排列
	string largestNumber(vector<int> &nums) {
		sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
			long sx = 10, sy = 10;
			while (sx <= x) {
				sx *= 10;
			}
			while (sy <= y) {
				sy *= 10;
			}
			return sy * x + y > sx * y + x;
		});
		if (nums[0] == 0) {
			return "0";
		}
		string ret;
		for (int &x : nums) {
			ret += to_string(x);
		}
		return ret;
	}
};

void test_179() {
	vector<int> nums = { 3,30,34,5,9 };
	cout << (Solution_179().largestNumber(nums) == "9534330") << endl;
}