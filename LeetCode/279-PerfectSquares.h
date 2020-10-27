#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution_279_1 {
public:
	int numSquares(int n) {
		static vector<int> dp{ 0 };
		for (int i = 1; i <= n; i++) {
			int num = n + 1;
			for (int j = 1; j*j <= i; j++) {
				num = min(num, dp[i - j * j] + 1);
			}
			dp.push_back(num);
		}
		return dp[n];
	}
};

class Solution_279 {
public:
	int numSquares(int n) {
		static vector<int> dp(n + 1, n + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};

void test_279() {
	cout << Solution_279().numSquares(13) << endl;
}