#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_746 {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int c2 = 0, c1 = 0; // ����λ�� 0 �� 1 �Ĵ���Ϊ 0
		for (int i = 2; i <= n; ++i) { // ������Ҫ����λ�� n
			// Ҫ����λ�� i����Ҫ�ȵ���λ�� i-1 �� i-2��Ȼ�������Ӧ����
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