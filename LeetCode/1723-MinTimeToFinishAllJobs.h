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
		if (maxTime >= minTime) return; // ��ǰִ��ʱ������ֵ������ʷ��Сֵ����Ҫ��֦
		if (c == jobs.size()) {
			minTime = maxTime;
			return;
		}
		for (int i = 0; i < k; ++i) {
			// �����������˵�˳�򲻻�Խ�����Ӱ�죬����Ĳ�ֻͬ�����ڸ����񼯺��Ƿ�ͬ
			// Ϊ���������ظ��������ǰ�湤��û��������ʱ�����湤�˲��������������Ҫ��֦
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