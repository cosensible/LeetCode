#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_57 {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int i = 0, n = intervals.size();
		// ��ǰ�����ڱ�������������
		while (i < n && intervals[i][1] < newInterval[0]) {
			res.push_back(intervals[i++]);
		}
		// ��ǰ�����뱻���������н���
		while (i < n && intervals[i][0] <= newInterval[1]) {
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			++i;
		}
		res.push_back(newInterval);
		// ʣ�µ����䶼��ǰ�������û�н���
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