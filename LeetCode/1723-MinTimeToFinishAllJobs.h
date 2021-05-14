#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

class Solution_1723 {
	int minTime = INT_MAX;
	vector<int> wktime;
public:
	int minimumTimeRequired(vector<int>& jobs, int k) {
		wktime.assign(k, 0);
		backtrack(jobs, k, 0, 0);
		return minTime;
	}

	void backtrack(vector<int> &jobs, int k, int c, int maxTime) {
		if (maxTime >= minTime) return; // 当前执行时间的最大值超过历史最小值，需要剪枝
		if (c == jobs.size()) {
			minTime = maxTime;
			return;
		}
		for (int i = 0; i < k; ++i) {
			// 任务分配给工人的顺序不会对结果造成影响，结果的不同只依赖于各任务集合是否不同
			// 为避免以上重复情况，在前面工人没分配任务时，后面工人不允许分配任务，需要剪枝
			if (i > 0 && wktime[i - 1] == 0) return;
			wktime[i] += jobs[c];
			backtrack(jobs, k, c + 1, max(wktime[i], maxTime));
			wktime[i] -= jobs[c];
		}
	}
};


void test_1723() {
	vector<int> jobs = { 9899456,8291115,9477657,9288480,5146275,7697968,8573153,3582365,3758448,9881935,2420271,4542202 };
	int k = 6;
	cout << (Solution_1723().minimumTimeRequired(jobs, k)) << endl;
}