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
		// ������������������Ϊ������Сֵ���������Ϊ�������ֵ
		while (firstDay < lastDay) {
			int midDay = firstDay + (lastDay - firstDay) / 2;
			// ����� midDay ��������������
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
			// �����������񣬿��ܴ��ڸ��ٵ����������򣬱��볢�Ը��������
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