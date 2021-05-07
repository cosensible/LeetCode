#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_57 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int i = 0, n = intervals.size();
		// 当前区间在被插入区间的左边
		while (i < n && intervals[i][1] < newInterval[0]) {
			res.push_back(intervals[i++]);
		}
		// 当前区间与被插入区间有交集
		while (i < n && intervals[i][0] <= newInterval[1]) {
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			++i;
		}
		res.push_back(newInterval);
		// 剩下的区间都与前面的区间没有交集
		copy(intervals.begin() + i, intervals.end(), back_inserter(res));
		return res;
	}
};


void test_57() {
	vector<vector<int>> intervals = { {1,3},{6,9} };
	vector<int> newIntervals = { 2,5 };
	auto res = Solution_57().insert(intervals, newIntervals);
	for (auto &v : res) {
		cout << "[" << v[0] << "," << v[1] << "]" << endl;
	}
}