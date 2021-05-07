#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_746 {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int c2 = 0, c1 = 0; // 到达位置 0 和 1 的代价为 0
		for (int i = 2; i <= n; ++i) { // 最终需要到达位置 n
			// 要到达位置 i，需要先到达位置 i-1 或 i-2，然后加上相应代价
			int c = min(c1 + cost[i - 1], c2 + cost[i - 2]);
			c2 = c1;
			c1 = c;
		}
		return c1;
	}
};


void test_746() {
	vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	cout << (Solution_746().minCostClimbingStairs(cost) == 6) << endl;
}