#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution_1473 {
	const int INF = 1e6 + 1; // ������ <=100��Ϳһ�����ӵ�������Ϊ 1e4����ˢ���з��ӵ�������Ϊ 1e6
public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		for (int i = 0; i < m; ++i) { --houses[i]; } // ʹ houses ��ɫ�� cost �����е���ɫ��ƥ��
		// dp[i][j][k]��ˢ 0~i �ŷ��ӣ�ʹ�� i �ŷ��ӵ���ɫΪ j�������ڵ� k ����������С����
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INF)));
		for (int j = 0; j < n; ++j) { // ֻ��һ�����ӣ�ֻ�ܹ���һ������
			if (houses[0] == -1) dp[0][j][0] = cost[0][j];
			else if (houses[0] == j) dp[0][j][0] = 0;
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				// ��������ɫ����Ŀ����ɫ��һ�����Ƿ�
				if (houses[i] != -1 && houses[i] != j) continue;
				for (int k = 0; k < target; ++k) {
					// ǰ������ɫ��ͬҲ����һ�ַ������÷����Ľ��������䣬������ɫ��ͬ���½�������� 1
					for (int pj = 0; pj < n; ++pj) {
						if (pj == j) {
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
						}
						else if (k > 0) {
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][pj][k - 1]);
						}
					}
					// ��������ɫ�Һ�Ŀ����ɫһ�£�����Ҫ���Ϸ�ˢ���ۣ���������ɫ����Ҫ���Ϸ�ˢ����
					if (houses[i] == -1) {
						dp[i][j][k] += cost[i][j];
					}
				}
			}
		}

		int ans = INF;
		for (int j = 0; j < n; ++j) {
			ans = min(ans, dp[m - 1][j][target - 1]);
		}
		return ans == INF ? -1 : ans;
	}
};


void test_1473() {
	vector<int> houses = { 0,2,1,2,0 };
	vector<vector<int>> cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
	int m = 5, n = 2, target = 3;
	cout << (Solution_1473().minCost(houses, cost, m, n, target) == 11) << endl;
}