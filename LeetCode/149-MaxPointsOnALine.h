#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution_149 {
	using ll = long long;
	const ll epsilon = 100000LL;
public:
	// 要求最多有多少个点在同一条直线上，可以从每个点出发，求经过该点的直线中最多包含多少个其它点
	// 经过该点的直线可由斜率值唯一标识，计算该点和其它点构成的斜率大小，某斜率值出现次数最多，代表该直线经过最多的点
	// 需要考虑其它点与该点重合 或 直线与 y 轴平行的情况
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() < 3) return points.size();
		int maxCnt = 0;
		for (int i = 0; i < points.size(); ++i) { // 从各个点出发寻找直线
			int imaxCnt = 0, vCnt = 0, dup = 1;   // 出现最多的斜率的数量，与 y 轴平行的斜率的数量，该点的重复次数
			unordered_map<ll, int> cnt;
			int x1 = points[i][0], y1 = points[i][1];
			for (int j = i + 1; j < points.size(); ++j) { // n 个点之间有 n(n-1)/2 条边
				int x2 = points[j][0], y2 = points[j][1];
				if (x1 == x2 && y1 == y2) { dup++; } // 出现重复点，经过该点的直线至少包含 dup 个点
				else if (x1 == x2) { // 构成的直线与 y 轴平行，斜率为无穷大，单独计数
					vCnt++;
					imaxCnt = max(vCnt, imaxCnt);
				}
				else {
					double k = 1.0*(y1 - y2) / (x1 - x2);
					ll key = static_cast<ll>(k*epsilon);
					cnt[key]++;
					imaxCnt = max(cnt[key], imaxCnt);
				}
			}
			imaxCnt += dup; // 直线经过其它点的数量加上该点被重复的次数
			maxCnt = max(imaxCnt, maxCnt);
		}
		return maxCnt;
	}
};


void test_149() {
	vector<vector<int>> points = { {1,1 }, { 3,2 }, { 5,3 }, { 4,1 }, { 2,3 }, { 1,4 } };
	cout << (Solution_149().maxPoints(points) == 4) << endl;
}