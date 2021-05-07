#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_56 {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() < 2) return intervals;
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
			return a[0] < b[0];
		});
		for (int i = 0; i < intervals.size(); ++i) {
			int s = intervals[i][0];
			int e = intervals[i][1];
			while (i + 1 < intervals.size() && intervals[i + 1][0] <= e) {
				e = max(e, intervals[++i][1]);
			}
			res.push_back({ s,e });
		}
		return res;
	}
};


void test_56() {
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	auto res = Solution_56().merge(intervals);
	for (auto &v : res) {
		cout << "[" << v[0] << "," << v[1] << "]" << endl;
	}
}