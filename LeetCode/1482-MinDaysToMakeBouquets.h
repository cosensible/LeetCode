#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_1482 {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int n = bloomDay.size();
		if (m*k > n) return -1;

		int firstDay = *min_element(bloomDay.begin(), bloomDay.end());
		int lastDay = *max_element(bloomDay.begin(), bloomDay.end());
		// 二分天数，最少天数为数组最小值，最大天数为数组最大值
		while (firstDay < lastDay) {
			int midDay = firstDay + (lastDay - firstDay) / 2;
			// 计算第 midDay 天能制作几束花
			int i = 0, j = 0, num = 0;
			while (i < n) {
				if (bloomDay[i] <= midDay) ++i;
				else {
					num += (i - j) / k;
					if (num >= m) break;
					++i;
					j = i;
				}
			}
			num += (i - j) / k;
			// 如果能完成任务，可能存在更少的天数；否则，必须尝试更大的天数
			if (num >= m) lastDay = midDay;
			else firstDay = midDay + 1;
		}
		return lastDay;
	}
};


void test_1482() {
	vector<int> bloomDay = { 7,7,7,7,12,7,7 };
	int m = 2, k = 3;
	cout << (Solution_1482().minDays(bloomDay, m, k) == 12) << endl;
}